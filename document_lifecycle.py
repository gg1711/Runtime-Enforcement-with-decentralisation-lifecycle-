import rsa
import os.path
import ast
import hashlib
from key_generation_peers import Peers

delimiter = '$ $'


class Document:

    def __init__(self, filename):
        self.filename = filename

    def create_new_file(self):
        if os.path.isfile(self.filename):
            print("FileName already exists...Deleting its content")
        f = open(self.filename, 'w')
        f.write(f'Document {self.filename} created\n')
        f.close()

    def write_file(self, peer, group, action):

        if group.name not in peer.groups:
            print(f"Write {action} by {peer.name} not possible thorugh {group.name} group")

        with open(self.filename, 'r') as reader:
            line = reader.readlines()
            last_line = line[-1]
            last_digest = self.extract_digest(last_line)
            # print(line, " ", str(last_digest))

        with open(self.filename, 'a') as writer:
            hashed = self.compute_digest(last_digest, peer.name.encode('utf-8'), group.name.encode('utf-8'))
            digest = rsa.encrypt(hashed.digest(), peer.get_private_key())
            sequence = [str(rsa.encrypt(action.encode(), group.get_public_key())), peer.name, group.name, str(digest)]
            line = delimiter.join(sequence)     # '$ $' is used as delimiter because space can't be used as delimiter
            writer.write(line + '\n')

    def num_lines(self):
        with open(self.filename, 'r') as reader:
            return len(reader.readlines())

    def read_file(self, peer):
        print('reading file')
        with open(self.filename, 'r') as reader:
            reader.readline()
            for line in reader.readlines():
                sequence = line.split(delimiter)
                crypted_text = ast.literal_eval(sequence[0])
                # print(crypted_text)
                peer_name = sequence[1]
                group_name = sequence[2]
                digest = sequence[3]
                # print(peer_name, group_name)
                if group_name in peer.groups:
                    message = rsa.decrypt(crypted_text, Peers(group_name).get_private_key()).decode('utf-8')
                else:
                    message = "message can't be decrypted by non-group member"
                print(message, ' ', peer_name, ' ', group_name, digest)

    def compute_digest(self, *args):
        hashed = hashlib.sha256()
        for arg in args:
            hashed.update(arg)
        return hashed

    def extract_digest(self, line):
        sequences = line.split(delimiter)
        if len(sequences) == 1:   # if it is first action..only one line about file will be written
            return b''
        last_digest = sequences[-1][:-1]
        return ast.literal_eval(last_digest)

    def verify_digest(self):
        try:
            with open(self.filename, 'r') as reader:
                lines = reader.readlines()
                for idx, line in enumerate((lines[1:])):
                    sequence = line.split(delimiter)
                    crypto_digest = sequence[-1][:-1] # last character skipped bcz of '\n' added in line
                    crypto_digest = ast.literal_eval(crypto_digest)
                    # print(crypto_digest)
                    peer_name = sequence[1]
                    group_name = sequence[2]
                    hashed_digest = rsa.decrypt(crypto_digest, Peers(peer_name).get_private_key())
                    last_digest = self.extract_digest(lines[idx])  # idx will be one less of that lines bcz started from 1
                    # print(peer_name, group_name, last_digest, hashed_digest)
                    recompute_digest = self.compute_digest(last_digest, peer_name.encode('utf-8'), group_name.encode('utf-8')).digest()
            print('No error found in digest || Document not tampered')
        except Exception as e:
            print(f'Error detected in line {idx} \n Error: {e}')
        finally:
            print('Digest verification completed')

    def get_lifecycle(self,peer,groups):
        required_groups = [group.name for group in groups]
        for group in required_groups:
            if group not in peer.groups:
                return [f"{peer.name} has no rights to access group {group}"]

        actions = list()

        with open(self.filename, 'r') as reader:
            reader.readline()
            for line in reader.readlines():
                sequence = line.split(delimiter)
                crypted_text = ast.literal_eval(sequence[0])
                peer_name = sequence[1]
                group_name = sequence[2]

                if group_name in required_groups:
                    message = rsa.decrypt(crypted_text, Peers(group_name).get_private_key()).decode('utf-8')
                    actions.append(f"{peer_name} written {message}")

        return actions
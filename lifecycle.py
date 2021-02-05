import rsa
import os.path
import ast
import hashlib

class Peers:
    def __init__(self, name):
        self.name = name

    def add_user(self):
        pubkey, privkey = rsa.newkeys(512)
        # print(dir(pubkey))
        # print(dir(privkey))
        # print(dir(rsa.PrivateKey))
        privkey_name = self.name + '_private'
        pubkey_name = self.name + '_public'

        privkey = rsa.PrivateKey.save_pkcs1(privkey)
        pubkey = rsa.PublicKey.save_pkcs1(pubkey)

        with open(privkey_name, 'wb') as writer:
            writer.write(privkey)

        with open(pubkey_name, 'wb') as writer:
            writer.write(pubkey)

    def get_private_key(self):
        privkey_name = self.name + '_private'
        with open(privkey_name, 'r') as reader:
            keydata = reader.read()
        privkey = rsa.PrivateKey.load_pkcs1(keydata)
        return privkey

    def get_public_key(self):
        pubkey_name = self.name + '_public'
        with open(pubkey_name, 'r') as reader:
            keydata = reader.read()
        pubkey = rsa.PublicKey.load_pkcs1(keydata)
        return pubkey


class Document:

    def __init__(self, fname):
        self.fname = fname

    def create_new_file(self):
        if os.path.isfile(self.fname):
            print("FileName already exists...Deleting its content")
        f = open(self.fname, 'w')
        f.write(f'Document {self.fname} created\n')
        f.close()

    def write_file(self, peer, group, action):
        if self.num_lines() == 1:
            last_digest = b''
        else:
            with open(self.fname, 'r') as reader:
                line = reader.readlines()
                last_line = line[-1].split('$ $')
                last_digest = last_line[-1]
                last_digest = ast.literal_eval(last_digest)
                print(line, " ", str(last_digest))

        with open(self.fname, 'a') as writer:
            hash = hashlib.sha256()
            hash.update(last_digest)
            hash.update(peer.name.encode('utf-8'))
            hash.update(group.name.encode('utf-8'))
            digest = rsa.encrypt(hash.digest(), peer.get_private_key())
            sequence = [str(rsa.encrypt(action.encode(), group.get_public_key())), peer.name, group.name, str(digest)]
            line = '$ $'.join(sequence)     # '$ $' is used as delimiter because space can't be used as delimiter
            writer.write(line + '\n')

    def num_lines(self):
        with open(self.fname, 'r') as reader:
            return len(reader.readlines())

    def read_file(self):
        print('reading file')
        with open(self.fname, 'r') as reader:
            reader.readline()
            for line in reader.readlines():
                sequence = line.split('$ $')
                crypted_text = ast.literal_eval(sequence[0])
                # print(crypted_text)
                peer_name = sequence[1]
                group_name = sequence[2]
                digest = sequence[3]
                # print(peer_name, group_name)
                message = rsa.decrypt(crypted_text, Peers(group_name).get_private_key()).decode('utf-8')
                print(message, ' ', peer_name, ' ', group_name, digest)

    def verify_digest(self):
        


if __name__ == '__main__':
    group = Peers('iitbbs')
    group.add_user()

    if int(input('Want to add user -- Yes(1) / No(0):')):
        name = input('Enter name of peer want to add: ')
        peer = Peers(name)
        peer.add_user()
        # print(peer.get_public_key())
        # print(peer.get_private_key())

    fname = input('Enter name of document: ')
    artifact = Document(fname)
    artifact.create_new_file()

    artifact.write_file(Peers('gaurav'), group, '17cs02005')
    artifact.write_file(Peers('rahul'), group, '17cs02003')
    artifact.write_file(Peers('rajat'), group, '17cs02007')
    artifact.write_file(Peers('gaurav'), group, '17cs02005')

    print(artifact.num_lines())
    artifact.read_file()










import random, string
import os
from key_generation_peers import Peers
from document_lifecycle import Document
import time
import matplotlib.pyplot as plt


def get_text(len):
    return ''.join(random.choice(string.ascii_letters) for i in range(len))


def generate_graph(x, y, xlabel, ylabel, title):
    plt.plot(x,y)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.title(title)
    plt.show()


if __name__ == '__main__':

    groups = ['G1', 'G2']

    group1 = Peers(groups[0], is_group = True)
    group2 = Peers(groups[1], is_group = True)

    arg = input('Want to generate new keys for Groups YES/NO: ')

    if arg == 'YES':
        group1.add_user()
        group2.add_user()
    print(f"groups available are:  {group1.name} and {group2.name}")

    users = ['A','B','C', 'D','E','F']
    user_objects = dict()

    for user in users:
        user_objects[user] = Peers(user)

    print("Users available are: ", end="")
    print(users)

    user_groups = [[group1], [group1], [group1], [group2], [group1, group2], [group2]]
    arg = input('Want to generate new keys for Users YES/NO: ')

    if arg == 'YES':
        for user in users:
            user_objects[user].add_user()

    for user, groups in zip(users, user_groups):
        for group in groups:
            user_objects[user].add_group(group.name)

    filename = input('Enter name of document: ')
    doc = Document(filename)

    arg = input('Want to write document YES/NO: ')

    if arg == 'YES':
        doc.create_new_file()

        doc.write_file(user_objects['A'], group1, '17cs02005')
        doc.write_file(user_objects['B'], group1, '17cs02003')
        doc.write_file(user_objects['D'], group2, get_text(15))
        doc.write_file(user_objects['E'], group1, '17cs02007')
        doc.write_file(user_objects['F'], group1, get_text(15))
        doc.write_file(user_objects['D'], group2, get_text(15))
        doc.write_file(user_objects['C'], group1, '17cs02005')
        doc.write_file(user_objects['E'], group2, get_text(15))
        doc.write_file(user_objects['F'], group2, 'I am admin')

        # doc.write_file(Peers('gaurav'), group2, '17cs02005')

    print(doc.num_lines())
    doc.read_file(user_objects['E'])
    doc.read_file(user_objects['A'])
    doc.verify_digest()

    actions = doc.get_lifecycle(user_objects['A'], [group1])
    print(f"\nactions performed in {group1.name} group")
    for action in actions:
        print(action)

    actions = doc.get_lifecycle(user_objects['D'], [group1])
    print(f"\nactions performed in {group1.name} group")
    for action in actions:
        print(action)

    actions = doc.get_lifecycle(user_objects['E'], [group1, group2])
    print(f"\nactions performed in {group1.name} and {group2.name} group")
    for action in actions:
        print(action)


#   This part is used to get graphs for writing and file size after performing operations

#   generate graph of time taken vs write operations.
#     doc.create_new_file()
#     start = time.time()
#     writes = []
#     timer =  []
#     filesize = []
#     writes.append(0)
#     filesize.append(0)
#     timer.append(0)
#     for i in range(1,21):
#         for j in range(1000):
#             doc.write_file(user_objects['gaurav'], group1, '17cs02005')
#         timer.append(time.time()-start)
#         writes.append(i*100)
#         filesize.append(os.stat(filename).st_size)
#
#     print(timer)
#     print(writes)
#     print(filesize)
#     generate_graph(writes, timer, 'num of writes', 'time (sec)', 'writes vs Time taken')
#     generate_graph(writes, filesize, 'num of writes', 'filesize (Bytes)', 'writes vs filesize')

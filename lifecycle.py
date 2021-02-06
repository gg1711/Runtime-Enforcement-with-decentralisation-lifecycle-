import random, string
from key_generation_peers import Peers
from document_lifecycle import Document


def get_text(len):
    return ''.join(random.choice(string.ascii_letters) for i in range(len))


if __name__ == '__main__':

    groups = ['Computer Science', 'Electrical']

    group1 = Peers(groups[0], is_group = True)
    group2 = Peers(groups[1], is_group = True)

    arg = input('Want to generate new keys for Groups YES/NO: ')

    if arg == 'YES':
        group1.add_user()
        group2.add_user()
    print(f"groups available are:  {group1.name} and {group2.name}")

    users = ['gaurav', 'rajat', 'rahul', 'alice', 'bob', 'charlie', 'admin']
    user_objects = dict()

    for user in users:
        user_objects[user] = Peers(user)

    print("Users available are: ", end="")
    print(users)

    user_groups = [[group1], [group1], [group1], [group2], [group2], [group2], [group1, group2]]
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

        doc.write_file(user_objects['gaurav'], group1, '17cs02005')
        doc.write_file(user_objects['rahul'], group1, '17cs02003')
        doc.write_file(user_objects['alice'], group2, get_text(15))
        doc.write_file(user_objects['rajat'], group1, '17cs02007')
        doc.write_file(user_objects['admin'], group1, get_text(15))
        doc.write_file(user_objects['charlie'], group2, get_text(15))
        doc.write_file(user_objects['gaurav'], group1, '17cs02005')
        doc.write_file(user_objects['bob'], group2, get_text(15))
        doc.write_file(user_objects['admin'], group2, 'I am admin')

        # doc.write_file(Peers('gaurav'), group2, '17cs02005')

    print(doc.num_lines())
    doc.read_file(user_objects['admin'])
    # doc.read_file(user_objects['gaurav'])
    doc.verify_digest()

    actions = doc.get_lifecycle(user_objects['admin'], [group1])
    print(f"\nactions performed in {group1.name} group")
    for action in actions:
        print(action)

    actions = doc.get_lifecycle(user_objects['bob'], [group1])
    print(f"\nactions performed in {group1.name} group")
    for action in actions:
        print(action)

    actions = doc.get_lifecycle(user_objects['admin'], [group1, group2])
    print(f"\nactions performed in {group1.name} and {group2.name} group")
    for action in actions:
        print(action)

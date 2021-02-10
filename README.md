# Decentralised-enforcement-of-artifact-lifecycle


This project contains 3 files:
*   main.py
*   key_generation_peers.py
*   document_lifecycle.py

Requirements:
*   Python 3.7
*   rsa library *pip install rsa*
*   hashlib     
*   os


To run code:

> python3 main.py

+-----------------+
|      Peers      |
|-----------------|
| groups          |
| is_group        |
| name            |
|-----------------|
| __init__        |
| add_group       |
| add_user        |
| get_private_key |
| get_public_key  |
+-----------------+
                                        
                   
+-----------------+
|     Document    |
|-----------------|
| filename        |
|-----------------|
| __init__        |
| compute_digest  |
| create_new_file |
| extract_digest  |
| get_lifecycle   |
| num_lines       |
| read_file       |
| verify_digest   |
| write_file      |
+-----------------+
 
**Detailed ReadME will be added soon.**


  

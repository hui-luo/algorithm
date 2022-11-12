import os
import random

with open('home/jkx/data/hadoop/user_login.txt', encoding='utf-8') as file_obj:
    contents = file_obj.readlines()
    with open('user_login_new.txt', 'w', encoding='utf-8') as f:
        id = 1
        for x in contents:
            s = str(id) + "," + x
            f.write(s)
            id=id+1
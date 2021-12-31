import re

def solution(new_id):
    answer = ''
    
    new_id = new_id.lower();
    new_id = re.sub('[^0-9a-z-_.]','',new_id)

    while True:
        new_id = new_id.replace('..','.')
        if new_id == new_id.replace('..','.'):
            break
    
    if len(new_id):
        if new_id[0] == '.':
            new_id = new_id[1:]
            
        if new_id.endswith('.'):
            new_id = new_id[:-1]
    
    if len(new_id) == 0:
        new_id = "a"
    
    if len(new_id) >= 16:
        new_id = new_id[:15]
        if new_id.endswith('.'):
            new_id = new_id[:-1]
    
    if len(new_id) <= 2:
        lastChar = new_id[-1]
        while len(new_id) <= 2:
            new_id = new_id + lastChar
    
    return new_id
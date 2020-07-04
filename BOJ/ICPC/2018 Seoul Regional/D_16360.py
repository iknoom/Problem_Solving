m = [
    ('a', 'as'),
    ('i', 'ios'),
    ('y', 'ios'),
    ('l', 'les'),
    ('n', 'anes'),
    ('o', 'os'),
    ('r', 'res'),
    ('t', 'tas'),
    ('u', 'us'),
    ('v', 'ves'),
    ('w', 'was')
]

def solution(str):
    for i in range(len(m)):
        if str[-1]==m[i][0]:
            return str[:-1]+m[i][1]
    if str[-2:]=='ne':
        return str[:-2]+'anes'
    return str+'us'

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        word = input()
        answer = solution(word)
        print(answer)
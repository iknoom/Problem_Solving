import sys
input = sys.stdin.readline
words = []

while True:
    word = input().rstrip()
    if word == '-': break
    words.append(word)

while True:
    board = input().rstrip()
    ABC = [0] * 26
    if board == '#': break
    A = [0] * 26
    for a in board:
        A[ord(a) - 65] += 1


    for word in words:
        B = [0] * 26
        for b in word:
            B[ord(b) - 65] += 1
        flag = True
        for i in range(26):
            if A[i] < B[i]:
                flag = False
        if flag:
            for b in set(word):
                ABC[ord(b) - 65] += 1
    min_cnt = 10**9
    min_list = []
    max_cnt = 0
    max_list = []

    for a in set(board):
        ret = ABC[ord(a) - 65]
        if min_cnt == ret:
            min_list.append(a)
        elif ret < min_cnt:
            min_cnt = ret
            min_list = [a]
        if max_cnt == ret:
            max_list.append(a)
        elif ret > max_cnt:
            max_cnt = ret
            max_list = [a]
    print(''.join(sorted(min_list)), min_cnt, ''.join(sorted(max_list)), max_cnt)
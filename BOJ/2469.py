k = int(input())
n = int(input())

# last
last = input()
last_position = [-1] * k
for i in range(k):
    last_position[ord(last[i]) - 65] = i

# ladder
question = -1
ladders = [[] for _ in range(n)]
for h in range(n):
    row = input()
    if row[0] == '?':
        question = h
        continue
    for i in range(k - 1):
        if row[i] == '-':
            ladders[h].append(i)

# solution
answer = [''] * (k - 1)
is_possible = [False] * k
for i in range(k):
    for shift in [-1, 0, 1]:
        cur = i
        cur_h = 0
        possible = (-1, -1)
        flag = True
        while cur_h < n:
            if cur_h == question:
                if shift == 1 and cur == k:
                    flag = False
                    break
                if shift == -1 and cur == 0:
                    flag = False
                    break
                possible = (cur, shift)
                cur += shift
            for ladder in ladders[cur_h]:
                if cur == ladder:
                    cur += 1
                    break
                elif cur == ladder + 1:
                    cur -= 1
                    break
            cur_h += 1
        if flag and cur == last_position[i]:
            x, shift = possible
            if shift == 0:
                c = '*'
                if x != k - 1:
                    if answer[x] == '-':
                        continue
                    answer[x] = '*'
                if x != 0:
                    if answer[x - 1] == '-':
                        continue
                    answer[x - 1] = '*'
                is_possible[i] = True
            else:
                if shift == -1:
                    x -= 1
                c = '-'
                if not answer[x]:
                    answer[x] = c
                if answer[x] == c:
                    is_possible[i] = True

if all(is_possible):
    for i in range(k - 1):
        if not answer[i]:
            answer[i] = '*'
    print(''.join(answer))
else:
    print('x' * (k - 1))
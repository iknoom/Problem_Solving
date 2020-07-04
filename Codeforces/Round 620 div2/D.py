import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    n, S = input().split()
    n = int(n)
    max_ans = [0] * n
    i = j = 0
    cur = 1
    for s in S + '<':
        if s == '>':
            j += 1
        elif s == '<':
            for k in range(j, i - 1, -1):
                max_ans[k] = cur
                cur += 1
            j += 1
            i = j

    min_ans = [0] * n
    i = j = 0
    cur = 1
    for s in S[::-1] + '>':
        if s == '<':
            j += 1
        elif s == '>':
            for k in range(j, i - 1, -1):
                min_ans[k] = cur
                cur += 1
            j += 1
            i = j
    print(*min_ans[::-1])
    print(*max_ans)
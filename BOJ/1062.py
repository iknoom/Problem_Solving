from itertools import combinations as cb
f = lambda a : ord(a) - 97
N, K = map(int, input().split())
word = [list(map(f, input()[4:-4])) for _ in range(N)]
choiced = set(map(f, ['a', 'n', 't', 'i', 'c']))
ab = list(set(range(26)) - choiced)

if K < 5:
    print(0)
    exit(0)

ans = 0
for choice in cb(ab, K - 5):
    check = [0] * 26
    for i in choice: check[i] = 1
    for i in choiced: check[i] = 1
    ret = 0
    for i in range(N):
        flag = True
        for j in word[i]:
            if not check[j]:
                flag = False
        if flag: ret += 1
    ans = max(ans, ret)
print(ans)
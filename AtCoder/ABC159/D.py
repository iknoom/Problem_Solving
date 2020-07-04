N = int(input())
A = list(map(int, input().split()))

dic = {}
for a in A:
    if a in dic: dic[a] += 1
    else: dic[a] = 1

ans = 0
for k in dic:
    x = dic[k]
    ans += x * (x - 1) // 2

for a in A:
    print(ans - dic[a] + 1)
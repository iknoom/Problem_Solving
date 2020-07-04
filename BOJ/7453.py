N = int(input())
A, B, C, D = zip(*[tuple(map(int,input().split())) for _ in range(N)])
dic = {}
for i in range(N):
    for j in range(N):
        x = A[i] + B[j]
        if x not in dic: dic[x] = 1
        else: dic[x] += 1

ans = 0

for i in range(N):
    for j in range(N):
        y = C[i] + D[j]
        if -y in dic:
            ans += dic[-y]
print(ans)
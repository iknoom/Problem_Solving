N = int(input())
s = input()
A = []
for i in range(N):
    A.append((s[i], i))
A.sort()
B = [0] * N
C = [i for i in range(N)]

for i in range(N):
    _, j = A[i]
    B[i] = j


adj = [[] for _ in range(N)]
for i in range(N):
    x = B[i]
    j = C.index(x)
    while i < j:
        y = C[j-1]
        adj[x].append(y)
        adj[y].append(x)
        C[j], C[j-1] = C[j-1], C[j]
        j -= 1

vst = [-1] * N
succ = True


for i in range(N):
    if vst[i] < 0: vst[i] = 0
    for j in adj[i]:
        if vst[j] < 0:
            vst[j] = 1 - vst[i]
        elif vst[j] + vst[i] != 1:
            succ = False

if succ:
    print("YES")
    print(''.join(map(str,vst)))

else:
    print("NO")







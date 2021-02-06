N,H,W=map(int,input().split())
A=[input() for _ in range(H)]
for i in range(N):
    ret='?'
    for x in range(W):
        for y in range(H):
            if A[y][i*W+x]!='?':ret=A[y][i*W+x]
    print(ret,end='')
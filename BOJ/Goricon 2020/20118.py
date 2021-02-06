N,M=map(int,input().split())
A=[input() for _ in range(N)]
ans=[]
for i in range(M//2):ans+=[(0,i*2),(0,i*2+1)]*2
if M&1:
    for i in range(N//2):ans+=[(i*2,M-1),(i*2+1,M-1)]*2
else:
    for i in range((N-1)//2):ans+=[(i*2+1, M-1),(i*2+2, M-1)]*2
if (M&1)+(N&1)!=1:ans+=[(N-1,M-2),(N-1,M-1)]*2
print(len(ans))
for t in ans:print(*t)
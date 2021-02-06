n,L=map(int,input().split())
M=list(map(int,input().split()))
S=0
a="stable"
for i in range(1,n):
    S+=M[-i]
    if S/i<=M[-i-1]-L or M[-i-1]+L<=S/i:a="unstable"
print(a)
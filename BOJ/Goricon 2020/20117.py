N=int(input())
A=sorted(map(int,input().split()))
for i in range(N//2):A[i]=A[-i-1]
print(sum(A))
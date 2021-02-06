N=int(input())
A=[input() for _ in range(N)]
B=[*zip(*A)]
print("YES" if all(A[i]==''.join(B[i]) for i in range(N)) else "NO")
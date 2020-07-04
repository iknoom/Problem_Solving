A, B = map(int, input().split())
M = int(input())
T = list(map(int, input().split()))
S = sum(T[-i-1]*(A**i) for i in range(M))
ans = []
while S:
    ans.append(S % B)
    S //= B
print(*ans[::-1])
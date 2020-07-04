N = int(input())
ans = []
for _ in range(N):
    A = input()
    ans.append((len(A), sum(int(k) for k in A if 48 <= ord(k) <= 57), A))
_, _, a = zip(*sorted(ans))
print(*a, sep='\n')
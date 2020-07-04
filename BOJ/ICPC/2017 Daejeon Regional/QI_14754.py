n, m = map(int, input().split())
B = [list(map(int, input().split())) for _ in range(n)]
S = sum(sum(B[i]) for i in range(n))
X = set(max(B[i]) for i in range(n))
B = [*zip(*B)]
Y = set(max(B[i]) for i in range(m))
print(S - sum(X|Y))
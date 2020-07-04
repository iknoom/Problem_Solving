N = int(input())
S = [input() for _ in range(N)]
for i in range(1, 101):
    if len(set(S[j][-i:] for j in range(N))) == N:
        print(i)
        break
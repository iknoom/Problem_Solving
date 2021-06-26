N = int(input())
S = [input() for _ in range(N)]
for k in S:
    if k[::-1] in S:
        print(len(k), k[len(k)//2])
        break
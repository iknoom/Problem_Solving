from itertools import permutations as p
N = int(input())
V = input().split()
ans = []
for p in p(range(10), N + 1):
    if all(V[i] == '<' and p[i] < p[i + 1] or V[i] == '>' and p[i] > p[i + 1] for i in range(N)): ans.append(''.join(map(str,p)))
print(max(ans)+'\n'+min(ans))
import sys
from itertools import combinations as cb
input = sys.stdin.readline


def f(u):
    if u != p[u]:p[u] = f(p[u])
    return p[u]

N = int(input())

p = [0] * 26
for i in range(26):
    p[i] = i

vst = set()

for i in range(N):
    t = input().rstrip()
    al = set()
    for a in t:
        k = ord(a) - 97
        al.add(k)
        vst.add(k)
    if len(al) > 1:
        for u,v in cb(al, 2):
            if f(u) != f(v):
                p[f(u)] = p[f(v)]

q = set()
for w in vst:
    q.add(p[f(w)])

print(len(q))

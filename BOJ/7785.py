input = __import__('sys').stdin.readline
n = int(input())
a = set()
for _ in range(n):
    x, y = input().split()
    if y == 'enter': a.add(x)
    else: a.discard(x)
for k in sorted(a, reverse=True): print(k)
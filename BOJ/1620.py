input = __import__('sys').stdin.readline

N, M = map(int, input().split())
dic1 = {}
dic2 = {}
for i in range(1, N + 1):
    name = input().rstrip()
    dic1[str(i)] = name
    dic2[name] = str(i)
for _ in range(M):
    q = input().rstrip()
    if q in dic1: print(dic1[q])
    elif q in dic2: print(dic2[q])
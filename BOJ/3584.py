for _ in range(int(input())):
    N = int(input())
    p = [0] * (N + 1)
    for _ in range(N - 1):
        a, b = map(int, input().split())
        p[b] = a
    a, b = map(int, input().split())
    while p[a]:
        t = a
        a, p[t] = p[a], 0
    p[a] = 0
    while p[b]: b = p[b]
    print(b)
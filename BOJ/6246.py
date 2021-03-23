N, Q = map(int, input().split())
vst = [0] * N
for _ in range(Q):
    L, I = map(int, input().split())
    L -= 1
    while L < N:
        vst[L] = 1
        L += I
print(N - sum(vst))
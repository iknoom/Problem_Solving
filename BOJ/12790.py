T = int(input())

for _ in range(T):
    a0, b0, c0, d0, a1, b1, c1, d1 = map(int, input().split())
    HP = max(1, (a0 + a1))
    MP = max(1, (b0 + b1))
    AD = max(0, (c0 + c1))
    DF = d0 + d1
    print(HP + 5 * MP + 2 * AD + 2 * DF)
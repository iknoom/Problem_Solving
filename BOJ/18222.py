def sol(n):
    if n == 1:
        return 0
    mid = 1
    while mid * 2 < n:
        mid *= 2
    return sol(n - mid) ^ 1

k = int(input())
print(sol(k))
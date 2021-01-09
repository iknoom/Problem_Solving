from sys import stdin, setrecursionlimit
setrecursionlimit(10**9)
input = stdin.readline

def pow(a, b, mod):
    if b == 0:
        return 1
    if b % 2 == 0:
        n = pow(a, b//2, mod)
        return (n * n)% mod
    else:
        n = pow(a, (b - 1) // 2, mod)
        return (n * n * a) % mod

if __name__ == "__main__":
     N, M = map(int, input().split())
     Q = M * M
     t = pow(10, N, Q)
     print(t // M)


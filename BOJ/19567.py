from sys import stdin
input = stdin.readline

INF = float('inf')

def solution():
    global frogs, N
    U = L = INF
    D = R = -INF
    for a, b, c in frogs:
        uy, dy = a + b + c, a + b - c
        ly, ry = b - a + c, b - a - c
        if uy < D or U < dy or ly < R or L < ry:
            print("NO")
            return
        U, L = min(U, uy), min(L, ly)
        D, R = max(D, dy), max(R, ry)
    print((D - L)//2, (D + L)//2)

if __name__ == "__main__":
    N = int(input())
    frogs = [tuple(map(int, input().split())) for _ in range(N)]
    S = sum(sum(frogs[i]) % 2 for i in range(N))
    if S != 0 and S != N:
        print("NO")
    else:
        solution()
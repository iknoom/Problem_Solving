from sys import stdin

input = stdin.readline

if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    T = [(A[i], i) for i in range(2**N)]
    while True:
        L = len(T)
        if L == 2: break
        nT = []
        for i in range(L // 2):
            if T[i * 2][0] < T[i * 2 + 1][0]:
                nT.append(T[i * 2 + 1])
            else:
                nT.append(T[i * 2])
        T = nT

    if T[0][0] > T[1][0]:
        print(T[1][1] + 1)
    else:
        print(T[0][1] + 1)


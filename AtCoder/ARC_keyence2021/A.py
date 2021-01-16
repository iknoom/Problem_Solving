from sys import stdin
input = stdin.readline

if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = []
    ma = -1
    mb = -1
    for i in range(N):
        ma = max(ma, A[i])
        if C:
            C.append(max(ma * B[i], C[-1]))
        else:
            C.append(ma * B[i])
    print(*C, sep='\n')

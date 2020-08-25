import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**9)

def solution(i, j):
    while i < j and A[i] == 0: i += 1
    while i <= j and A[j] == 0: j -= 1
    if i > j: return 0
    ret = 10 ** 9
    H = 0
    while True:
        S = 0
        for k in range(i, j + 1):
            if A[k] != 0: S += 1
        ret = min(ret, H + S)
        if j - i + 1 == S:
            for k in range(i, j + 1):
                A[k] -= 1
            H += 1
        else:
            nxt = 0
            if A[i] != 0: Left = i
            else: Left = -1
            for k in range(i, j + 1):
                if k == j and A[j] == 1:
                    nxt += solution(Left, k)
                elif k == j:
                    continue
                elif A[k] == 0 and A[k + 1] != 0:
                    Left = k + 1
                elif A[k] != 0 and A[k + 1] == 0:
                    nxt += solution(Left, k)
            ret = min(ret, H + nxt)
            break
    return ret


if __name__ == "__main__":
     N = int(input())
     A = list(map(int, input().split()))
     print(solution(0, N - 1))
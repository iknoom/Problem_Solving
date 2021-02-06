import sys

input = sys.stdin.readline


def solution():
    n = int(input())
    r = list(map(int, input().split()))
    m = int(input())
    b = list(map(int, input().split()))
    ans = [0]
    S = 0
    for r_i in r:
        S += r_i
        ans.append(S)
    S = 0
    for b_i in b:
        S += b_i
        ans.append(S)

    S1 = 0
    for r_i in r:
        S1 += r_i
        S2 = 0
        for b_i in b:
            S2 += b_i
            ans.append(S1 + S2)
    print(max(ans))

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()
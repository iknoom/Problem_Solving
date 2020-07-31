import sys

input = sys.stdin.readline


def solution():
    N = int(input())
    ret = [6, 10, 14]
    S = sum(ret)
    if N - S in ret:
        ret.pop()
        ret.append(15)
        S = sum(ret)

    if N <= S:
        print("NO")
    else:
        print("YES")
        ret.append(N - S)
        print(*ret)



if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()
import sys

input = sys.stdin.readline

def solution():
    n = int(input())
    C = list(map(int, input().split()))
    one_idx = []
    for i in range(n):
        if C[i] == 1:
            one_idx.append(i)
    if len(one_idx) != 1:
        print("NO")
        return
    C = C[one_idx[0]:] + C[:one_idx[0]]
    before = C[0]
    for i in range(1, n):
        if before < C[i]:
            if abs(before - C[i]) != 1:
                print("NO")
                return
        before = C[i]
    print("YES")

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()
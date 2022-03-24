import sys
from collections import Counter

input = sys.stdin.readline

def solution():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    C = Counter(arr)
    for a in arr:
        x = a - k
        if x == a:
            if C[x] > 1:
                print("YES")
                return
        else:
            if x in C:
                print("YES")
                return
        y = a + k
        if y in C:
            print("YES")
            return
    print("NO")
    return


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()
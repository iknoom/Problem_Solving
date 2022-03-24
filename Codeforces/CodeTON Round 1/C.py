import sys

input = sys.stdin.readline

def solution():
    n = int(input())
    arr = list(map(int, input().split()))
    S = set(arr)
    if 1 not in arr:
        print("YES")
        return
    for a in arr:
        if a - 1 in arr:
            print("NO")
            return
        if a + 1 in arr:
            print("NO")
            return
    print("YES")
    return


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()
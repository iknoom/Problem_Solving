import sys

input = sys.stdin.readline

def solution():
    n = int(input())
    arr = list(map(int, input().split()))
    x = min(arr)
    y = max(arr)
    a = -1
    b = -1
    for i in range(n):
        if arr[i] == x:
            a = i
        if arr[i] == y:
            b = i
    print(a + 1, b + 1)

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()
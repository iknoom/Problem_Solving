from sys import stdin

input = stdin.readline

if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    ans = 0
    for i in range(N):
        ans += A[i] * B[i]
    if ans == 0:
        print("Yes")
    else:
        print("No")


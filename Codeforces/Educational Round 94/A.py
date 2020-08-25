import sys
input = sys.stdin.readline


def solution():
    n = int(input())
    A = list(map(int, input().rstrip()))
    arr = [A[i:i+n] for i in range(n)]
    ans = [0] * n
    for i in range(n):
        ans[i] = arr[i][i]
    print(''.join(map(str,ans)))

if __name__ == "__main__":
     T = int(input())
     for _ in range(T):
         solution()
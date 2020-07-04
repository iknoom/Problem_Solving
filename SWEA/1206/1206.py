import sys
sys.stdin = open("input.txt", "r")

for test_case in range(1, 11):
    ans = 0
    N = int(input())
    A = list(map(int, input().split()))
    for i in range(2, N-2):
        x = 0
        for d in range(1,3):
            x = max(x, A[i-d])
            x = max(x, A[i+d])
        ans += max(0, A[i] - x)
    print("#%d %d" %(test_case, ans))
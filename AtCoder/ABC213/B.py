N = int(input())
A = list(map(int, input().split()))
# smaller score ranks higher.
B = [(A[i], i) for i in range(N)]
B.sort()
print(B[-2][1] + 1)

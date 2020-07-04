N = int(input())
k = sum(i & 1 for i in map(int, input().split()))
print(min(k, N - k))
N = int(input())
arr = sorted(map(int, input().split()))
h = N // 2

if N % 2 == 0:
    ans = 2 * sum(arr[h + 1:N]) - 2 * sum(arr[:h - 1]) + arr[h] - arr[h - 1]
else:
    ans = sum(arr[h:N]) + sum(arr[h+2:N]) - 2 * sum(arr[:h])
    ans = max(ans, 2 * sum(arr[h+1:N]) - sum(arr[:h-1]) - sum(arr[:h+1]))

print(ans)
N = int(input())
arr = [tuple(map(int, input().split())) for _ in range(N)]
answer = float('inf')
for i in range(1, 1 << N):
    a = 1
    b = 0
    for j in range(N):
        if i & (1 << j):
            a *= arr[j][0]
            b += arr[j][1]
    answer = min(answer, abs(a - b))
print(answer)
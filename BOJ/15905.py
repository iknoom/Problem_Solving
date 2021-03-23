N = int(input())
arr = [tuple(map(int, input().split())) for _ in range(N)]
arr.sort(key=lambda x: (-x[0], x[1]))
answer = 0
for i in range(5, N):
    if arr[i - 1][0] == arr[i][0]:
        answer += 1
    else:
        break
print(answer)
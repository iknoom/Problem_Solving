N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
B.sort()

answer = sum(A)
for i in range(N):
    answer += i * B[i]
print(answer)
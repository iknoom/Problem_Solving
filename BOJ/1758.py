from sys import stdin
input = stdin.readline

N = int(input())
tip = [int(input()) for _ in range(N)]
tip.sort(reverse=True)
answer = 0
for i in range(N):
    answer += max(tip[i] - i, 0)
print(answer)
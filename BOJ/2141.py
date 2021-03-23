from sys import stdin
input = stdin.readline

N = int(input())
sweep = []
cur_x = -1000000001
cur_dx = 0
cur_S = 0

for _ in range(N):
    x, a = map(int, input().split())
    cur_dx += -a
    cur_S += (x - cur_x) * a
    sweep.append((x, 2 * a))

sweep.sort()
answer = cur_S
answer_x = cur_x
for x, dx in sweep:
    cur_S += cur_dx * (x - cur_x)
    cur_x = x
    cur_dx += dx
    if cur_S < answer:
        answer = cur_S
        answer_x = cur_x
print(answer_x)
import sys
input = sys.stdin.readline

N = int(input())
positive = []
negative = []
answer = 0
zero_flag = False
for _ in range(N):
    t = int(input())
    if t == 1:
        answer += t
    elif t > 0:
        positive.append(t)
    elif t < 0:
        negative.append(t)
    else:
        zero_flag = True

positive.sort(reverse=True)
negative.sort()

for i in range(len(positive)//2):
    answer += positive[i * 2] * positive[i * 2 + 1]
for i in range(len(negative)//2):
    answer += negative[i * 2] * negative[i * 2 + 1]

if len(positive) & 1:
    answer += positive[-1]

if len(negative) & 1 and not zero_flag:
    answer += negative[-1]

print(answer)
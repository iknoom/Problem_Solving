N = int(input())
adv = [list(map(int, input().split())) for _ in range(N)]
answer = float('inf')
for i in range(1 << N):
    left = []
    right = []
    for j in range(N):
        if i & (1 << j):
            left.append(j)
        else:
            right.append(j)
    left_adv = 0
    right_adv = 0
    for x in left:
        for y in left:
            left_adv += adv[x][y]
    for x in right:
        for y in right:
            right_adv += adv[x][y]
    answer = min(answer, abs(left_adv - right_adv))
print(answer)
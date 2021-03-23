paper = [-1] + [int(input()) for _ in range(6)]
space = [-1] + [0] * 6

answer = 0

# 6
answer += paper[6]

# 5
answer += paper[5]
space[1] += paper[5] * 11

# 4
answer += paper[4]
space[2] += paper[4] * 5

# 3
answer += paper[3] // 4
if paper[3] % 4:
    answer += 1
    one = [-1, 7, 6, 5]
    two = [-1, 5, 3, 1]
    space[1] += one[paper[3] % 4]
    space[2] += two[paper[3] % 4]

# 2
if space[2] >= paper[2]:
    space[2] -= paper[2]
    space[1] += space[2] * 4
else:
    paper[2] -= space[2]
    answer += paper[2] // 9
    if paper[2] % 9:
        answer += 1
        space[1] += (9 - (paper[2] % 9)) * 4

# 1
if space[1] >= paper[1]:
    space[1] -= paper[1]
else:
    paper[1] -= space[1]
    answer += paper[1] // 36
    if paper[1] % 36:
        answer += 1

print(answer)
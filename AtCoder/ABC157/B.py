A = [list(map(int, input().split())) for _ in range(3)]
B = [[0]*3 for _ in range(3)]
bingo = set(int(input()) for _ in range(int(input())))
for i in range(3):
    for j in range(3):
        if A[i][j] in bingo:
            B[i][j] = 1

ans = "No"
for i in range(3):
    if sum(B[i]) == 3: ans = "Yes"

for j in range(3):
    if B[0][j] + B[1][j] + B[2][j] == 3:
        ans = "Yes"

if B[0][0] + B[1][1] + B[2][2] == 3:
    ans = "Yes"

if B[0][2] + B[1][1] + B[2][0] == 3:
    ans = "Yes"

print(ans)
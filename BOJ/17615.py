N = int(input())
ALL = list(input())
R_ALL = ALL[::-1]
answer = float('inf')

for all in [ALL, R_ALL]:
    R = 0
    B = 0
    Rflag = False
    Bflag = False
    for i in range(N - 2, -1, -1):
        if all[i] == 'R' and all[i + 1] == 'B':
            Rflag = True
        if all[i] == 'B' and all[i + 1] == 'R':
            Bflag = True
        if Rflag and all[i] == 'R':
            R += 1
        if Bflag and all[i] == 'B':
            B += 1
    answer = min(answer, min(R, B))
print(answer)
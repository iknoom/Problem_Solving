import sys
input = sys.stdin.readline


N = int(input())
C = [tuple(map(int,input().split())) for _ in range(N)]
if N & 1:
    print("NO")
else:
    ans = []
    for i in range(N//2):
        x = C[i][0] + C[i+N//2][0]
        y = C[i][1] + C[i+N//2][1]
        ans.append((x,y))
    flag = True
    for i in range(len(ans) - 1):
        x1, y1 = ans[i]
        x2, y2 = ans[i+1]
        if x1 != x2 or y1 != y2:
            flag = False
    if flag: print("YES")
    else: print("NO")
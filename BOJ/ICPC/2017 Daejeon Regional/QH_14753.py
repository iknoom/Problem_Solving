N = int(input())
T = sorted(map(int,input().split()))
ans = [0] * 4
ans[0] = T[-1] * T[-2] * T[-3]
ans[1] = T[-1] * T[-2]
ans[2] = T[0] * T[1]
ans[3] = T[0] * T[1] * T[-1]
print(max(ans))
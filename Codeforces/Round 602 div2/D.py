import sys
input = sys.stdin.readline


N = int(input())
k = list(map(int,input().split()))
num = []
for i in range(N):
    num.append((k[i], -i))
num.sort(reverse=True)
for _ in range(int(input())):
    L, pos = map(int,input().split())
    ans = num[:L]
    ans.sort(reverse=True, key=lambda x: x[1])
    print(ans[pos-1][0])
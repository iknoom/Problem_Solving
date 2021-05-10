# 상근이와 친구들은 총 M명, 한 줄로 서서 입국심사를 기다리고 있다.
# 입국심사대는 총 N개, i번 심사대에 앉아있는 심사관이 심사를 하는데 드는 시간은 T_i이다.

from sys import stdin
input = stdin.readline

N, M = map(int, input().split())
S = [int(input()) for _ in range(N)]

l = 0
r = 10 ** 18
while l + 1 < r:
    mid = (l + r) // 2
    X = sum(mid // S[i] for i in range(N))
    if X >= M:
        r = mid
    else:
        l = mid
print(r)
# 착한 아이들에게 선물을 나눠줄 것이다.
# 거점들을 세워 그 곳을 방문하며 선물을 충전해 나갈 것이다.
# 착한 아이들을 만날 때마다 자신이 들고있는 가장 가치가 큰 선물 하나를 선물해 줄 것이다.

# 차례대로 방문한 아이들과 거점지의 정보들이 주어졌을 때, 아이들이 준 선물들의 가치들을 출력하시오.
# 만약 아이들에게 줄 선물이 없다면 -1을 출력하시오.

from sys import stdin
input = stdin.readline
from heapq import *

n = int(input())
hq = []
for _ in range(n):
    P = list(map(int, input().split()))
    if P[0] == 0:
        if not hq:
            print(-1)
        else:
            print(-heappop(hq))
    else:
        for i in range(1, P[0] + 1):
            heappush(hq, -P[i])
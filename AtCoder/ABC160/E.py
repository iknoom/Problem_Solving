import sys
input = sys.stdin.readline

X, Y, A, B, C = map(int, input().split())
p = sorted(map(int, input().split()), reverse=True)
q = sorted(map(int, input().split()), reverse=True)
r = sorted(map(int, input().split()), reverse=True)

# 큰 것부터 X개, Y개 선택
pq = p[:X] + q[:Y]

# (X + Y)개보다 모자르면 0을 추가
if len(pq) < X + Y:
    pq += [0] * (X + Y - len(pq))

# 정렬
pq.sort()

# 작은 것부터 C로 대체
for i in range(min(C, len(pq))):
    if pq[i] < r[i]: pq[i] = r[i]

print(sum(pq))
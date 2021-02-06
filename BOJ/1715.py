import sys, heapq


def int_input():
    return int(sys.stdin.readline())


# 입력
N = int_input()
hq = [int_input() for _ in range(N)]

# heapify : 배열을 힙으로 만든다.
heapq.heapify(hq)

# solution
answer = 0
while len(hq) > 1:
    a = heapq.heappop(hq)
    b = heapq.heappop(hq)
    answer += a + b
    heapq.heappush(hq, a + b)

# 출력
print(answer)
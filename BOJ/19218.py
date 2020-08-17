from heapq import *
import sys
input = sys.stdin.readline

if __name__ == "__main__":
    N = int(input())
    sweep = []

    for i in range(N):
        a, b, t = map(int, input().split())
        sweep.append((a + t, -1, t))
        sweep.append((b, 1, t))

    ans = 0
    prv = 0
    pq = []
    del_pq = []
    for cur, flag, t in sorted(sweep):
        # 최적화 부분 : L // min(t_i)
        if pq:
            min_t = pq[0]
            L = cur - prv
            n = L // min_t
            ans += n
            prv += n * min_t
        # 삭제
        if flag == 1:
            heappush(del_pq, t)
            while del_pq and pq[0] == del_pq[0]:
                heappop(pq)
                heappop(del_pq)
        # 추가
        else:
            # a에서 선택이 가능했었다면 ans += 1
            if prv <= cur - t:
                ans += 1
                prv = cur
            heappush(pq, t)

    print(ans)
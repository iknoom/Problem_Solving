from heapq import *

def solve(W, D):
    hq = [(-W[i], 0, i) for i in range(m)]
    heapify(hq)
    plans = [[] for _ in range(m)]

    for i in range(n):
        if D[i]:
            T = D[i]
            st1 = []
            st2 = []
            for _ in range(T):
                while hq and i < hq[0][1]:
                    st1.append(heappop(hq))
                if not hq:
                    return None
                p, q, r = heappop(hq)
                W[r] -= w
                plans[r].append(i + 1)
                if W[r] >= w:
                    st2.append((-W[r], i + w + h, r))

            for j in range(w):
                if D[i + j] >= T:
                    D[i + j] -= T
                else:
                    return None

            for k in st1 + st2:
                heappush(hq, k)
    return plans

if __name__ == "__main__":
    m, n, w, h = map(int, input().split())
    W = list(map(int, input().split()))
    D = list(map(int, input().split()))

    plans = solve(W, D)

    if plans is None:
        print(-1)
    else:
        print(1)
        for plan in plans:
            print(*plan)

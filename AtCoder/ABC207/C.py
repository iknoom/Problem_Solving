from sys import stdin
input = stdin.readline

def sol(a, b):
    t1, l1, r1 = intervals[a]
    t2, l2, r2 = intervals[b]
    if r1 < l2:
        return False
    if r2 < l1:
        return False
    if t1 in [2, 4] and r1 == l2:
        # [l1, r1)
        return False
    if t2 in [2, 4] and r2 == l1:
        # [l2, r2)
        return False
    if t1 in [3, 4] and l1 == r2:
        # (l1, r1]
        return False
    if t2 in [3, 4] and l2 == r1:
        # (l2, r2]
        return False
    return True

if __name__ == '__main__':
    N = int(input())
    intervals = [tuple(map(int, input().split())) for _ in range(N)]
    answer = 0
    for i in range(N - 1):
        for j in range(i + 1, N):
            if sol(i, j):
                answer += 1
    print(answer)
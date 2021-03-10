def sol(max_dist, A):
    if max_dist == 0:
        return False
    stack = M
    cur = A[0]
    for i in range(1, len(A)):
        while A[i] - cur > max_dist:
            cur += max_dist
            stack -= 1
        cur = A[i]
    return stack >= 0

if __name__ == '__main__':
    N, M, L = map(int, input().split())
    A = [0] + list(map(int, input().split())) + [L]
    A.sort()
    left = 0
    right = 20000
    while left + 1 < right:
        mid = (left + right) // 2
        if sol(mid, A):
            right = mid
        else:
            left = mid
    print(right)
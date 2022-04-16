import sys

input = sys.stdin.readline


def sub_solution_d1(l, r, a):
    b = {i for i in range(l, r + 1)}
    bits1 = [0] * 18
    bits2 = [0] * 18
    for c in a:
        for i in range(18):
            if c & (1 << i):
                bits1[i] += 1
    for c in b:
        for i in range(18):
            if c & (1 << i):
                bits2[i] += 1
    ans = 0
    for i in range(18):
        if bits1[i] != bits2[i]:
            ans += (1 << i)
    return ans


def solution(l, r, a):
    # 1.
    if (r - l + 1) % 2 == 1:
        return sub_solution_d1(l, r, a)
    # 2. i)
    if l % 2 == 0:
        nxt_a = {a_i >> 1 for a_i in a}
        return solution(l >> 1, r >> 1, nxt_a) << 1
    # 2. ii)
    pq = [a_i for a_i in a if a_i ^ 1 not in a]
    p, q = pq
    x = p ^ l  # x: p ^ l or q ^ l
    if all(l <= a_i ^ x <= r for a_i in a):
        return x
    else:
        return q ^ l


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        l, r = map(int, input().split())
        a = set(map(int, input().split()))
        print(solution(l, r, a))

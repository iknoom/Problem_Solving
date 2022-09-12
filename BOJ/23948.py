from sys import stdin
input = stdin.readline


def solution(n, m, arr):
    # get min xor sum
    min_diffs = [0] * 54
    for bit in range(53, -1, -1):
        x = (1 << bit)
        one = 0
        zero = 0
        for e in arr:
            if e & x:
                zero += x
            else:
                one += x
        min_diffs[bit] = min(one, zero)
    min_diff_sum = sum(min_diffs)
    if min_diff_sum > m:
        return -1
    # increase xor sum
    ret = 0
    cur_sum = min_diff_sum
    for bit in range(53, -1, -1):
        x = (1 << bit)
        nxt_diff = 0
        for e in arr:
            if (e & x) == 0:
                nxt_diff += x
        inc = nxt_diff - min_diffs[bit]
        if cur_sum + inc <= m:
            cur_sum += inc
            ret += x
    return ret


if __name__ == "__main__":
    T = int(input())
    for testcase in range(1, T + 1):
        n, m = map(int, input().split())
        arr = list(map(int, input().split()))
        answer = solution(n, m, arr)
        print(f'Case #{testcase}:', answer)
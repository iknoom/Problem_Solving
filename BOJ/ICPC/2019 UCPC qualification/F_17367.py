DP = dict()

def get_val(a, b, c):
    if a == b == c:
        return 10000 + a * 1000
    if a == b:
        return 1000 + a * 100
    if a == c:
        return 1000 + a * 100
    if b == c:
        return 1000 + b * 100
    else:
        return 100 * max([a, b, c])

def solution(a, b, n):
    if n == 0: return 0
    if (a, b, n) in DP: return DP[(a, b, n)]
    ret = 0.0
    for c in range(1, 7):
        ret += max(get_val(a, b, c), solution(b, c, n - 1))
    ret /= 6
    DP[(a, b, n)] = ret
    return ret

if __name__ == "__main__":
    N = int(input())
    ans = 0.0
    for a in range(1, 7):
        for b in range(1, 7):
            ans += solution(a, b, N - 2)
    print(ans / 36)
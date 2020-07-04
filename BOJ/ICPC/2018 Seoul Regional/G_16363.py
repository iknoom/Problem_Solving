def solution(N):
    ans = []
    for test in range(1, N + 1):
        S, a, b, c = map(int, input().split())
        ret = S ** 3
        for x, y in [(a, b), (a, c), (b, a), (b, c), (c, a), (c, b)]:
            ret -= ((S - x) ** 3) / 6
            ret -= ((S - y) ** 3) / 6
            ret += ((S - x - y) ** 3) / 6
        ans.append((ret / (S ** 3), test))
    return sorted(ans)

if __name__ == "__main__":
    N = int(input())
    ans = solution(N)
    for _, test in ans:
        print(test, end=' ')
    print()
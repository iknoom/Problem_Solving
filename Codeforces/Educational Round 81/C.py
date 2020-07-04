import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    s = input().rstrip()
    t = input().rstrip()
    L = len(s)
    dp = []
    cur_min = [-1] * 26

    for i in range(L):
        x = s[L - 1 - i]
        xx = ord(x) - 97
        cur_min[xx] = L - 1 - i
        dp.append(cur_min[:])
    dp.reverse()

    ans = 1
    ALL = set(s)
    for x in t:
        if x not in ALL:
            ans = -1

    if ans < 0:
        print(ans)
        continue

    cur = 0
    for x in t:
        xx = ord(x) - 97
        if cur == L or dp[cur][xx] < 0:
            cur = 0
            ans += 1

        cur = dp[cur][xx] + 1
    print(ans)
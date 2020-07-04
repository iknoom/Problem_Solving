for _ in range(int(input())):
    N = int(input())
    s = input()
    t = input()
    idx = [-1, -1]
    cnt = 0
    ans = "YES"
    for i in range(N):
        if s[i] != t[i]:
            if cnt == 2:
                cnt = -1
                ans = "NO"
                break
            idx[cnt] = i
            cnt += 1
    if cnt == 1:
        ans = "NO"

    if cnt == 2:
        if s[idx[0]] != s[idx[1]] or t[idx[1]] != t[idx[0]]:
            ans = "NO"
    print(ans)
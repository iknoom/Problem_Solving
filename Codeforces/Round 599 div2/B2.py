import sys
input = sys.stdin.readline

for q in range(int(input())):
    N = int(input())
    s = list(input().rstrip())
    t = list(input().rstrip())
    ans = []
    for i in range(N-1):
        if s[i] != t[i]:
            for j in range(i + 1, N):
                if s[j] == s[i]:
                    ans.append((j + 1, i + 1))
                    s[j], t[i] = t[i], s[j]
                    break
                if t[j] == s[i]:
                    ans.append((i + 2, j + 1))
                    s[i + 1], t[j] = t[j], s[i + 1]
                    ans.append((i + 2, i + 1))
                    s[i + 1], t[i] = t[i], s[i + 1]
                    break

    flag = True
    for i in range(N):
        if s[i] != t[i]:
            flag = False

    if flag:
        print("Yes")
        print(len(ans))
        for u,v in ans:
            print(u, v)
    else:
        print("No")
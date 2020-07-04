import sys
input = sys.stdin.readline

T = int(input())

def dfs(u):
    global ans, flag
    ans += chr(u + 97)
    for v in adj[u]:
        if not vst[v]:
            vst[v] = True
            for q in adj[v]:
                if vst[q] and q != u:
                    flag = False
            dfs(v)

for _ in range(T):
    X = input().rstrip()
    adj = [set() for _ in range(26)]
    N = len(X)
    for i in range(N -1):
        a, b = X[i], X[i + 1]
        adj[ord(a) - 97].add(ord(b) - 97)
        adj[ord(b) - 97].add(ord(a) - 97)

    if N == 1:
        print("YES")
        for i in range(26):
            print(chr(i + 97), end='')
        print()
        continue
    one = []
    flag = True
    a2 = 0
    for i in range(26):
        k = adj[i]
        if len(k) == 0:
            a2 += 1
        elif len(k) == 1:
            one.append(i)
        elif len(k) > 2:
            flag = False

    if not one:
        print("NO")
        continue

    ans = ""
    vst = [False] * 26
    if len(one) != 2:
        flag = False
    vst[one[0]] = True
    dfs(one[0])
    a1 = 0
    for i in range(26):
        if not vst[i]:
            a1 += 1
            ans += chr(i + 97)

    if flag and a1 == a2:
        print("YES")
        print(ans)
    else:
        print("NO")
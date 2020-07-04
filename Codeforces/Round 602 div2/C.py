import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, k = map(int,input().split())
    s = input().rstrip()
    ans = []

    for i in range((k-1)*2):
        if i & 1 == 0 and s[i] == ')':
            for j in range(i+1, n):
                if s[j] == '(':
                    ans.append((i+1,j+1))
                    s = s[:i] + s[i:j+1][::-1] + s[j+1:]
                    break

        elif i & 1 == 1 and s[i] == '(':
            for j in range(i+1, n):
                if s[j] == ')':
                    ans.append((i+1,j+1))
                    s = s[:i] + s[i:j+1][::-1] + s[j+1:]
                    break
    q = (k-1)*2
    t = n - (k-1)*2
    for i in range(q, q+t//2):
        if s[i] == ')':
            for j in range(i + 1, n):
                if s[j] == '(':
                    ans.append((i + 1, j + 1))
                    s = s[:i] + s[i:j + 1][::-1] + s[j + 1:]
                    break
    for i in range(q+t//2, n):
        if s[i] == '(':
            for j in range(i + 1, n):
                if s[j] == ')':
                    ans.append((i + 1, j + 1))
                    s = s[:i] + s[i:j + 1][::-1] + s[j + 1:]
                    break
    print(len(ans))
    for i,j in ans:
        print(i,j)
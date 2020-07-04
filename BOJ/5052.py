import sys
input = sys.stdin.readline
t = int(input())

for _ in range(t):
    N = int(input())
    word = [input().rstrip() for _ in range(N)]
    vst = set(word)
    ans = "YES"
    for k in word:
        for i in range(len(k) - 1):
            if k[:i + 1] in vst:
                ans = "NO"
    if len(vst) != len(word): ans = "NO"
    print(ans)
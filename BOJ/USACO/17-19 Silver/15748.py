import sys
input = sys.stdin.readline

L, N, F, B = map(int, input().split())
st = []
for _ in range(N):
    x, c = map(int,input().split())
    while st and st[-1][1] <= c: st.pop()
    st.append((x, c))
ans = p = 0
for x, c in st:
    ans += c*(x-p)*(F-B)
    p = x
print(ans)
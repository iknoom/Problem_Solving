INF = float('inf')

def div(a, b):
    if a < 0 and b > 0:
        return -(abs(a)//b)
    return a//b

def dfs(cur, i):
    global min_value, max_value, a, b, c, d
    if i == N:
        min_value = min(min_value, cur)
        max_value = max(max_value, cur)
        return
    if a:
        a -= 1
        dfs(cur + A[i], i + 1)
        a += 1
    if b:
        b -= 1
        dfs(cur - A[i], i + 1)
        b += 1
    if c:
        c -= 1
        dfs(cur * A[i], i + 1)
        c += 1
    if d and A[i] != 0:
        d -= 1
        dfs(div(cur, A[i]), i + 1)
        d += 1

if __name__ == '__main__':
    N = int(input())
    A = list(map(int, input().split()))
    a, b, c, d = map(int, input().split())
    min_value = INF
    max_value = -INF
    dfs(A[0], 1)
    print(max_value)
    print(min_value)
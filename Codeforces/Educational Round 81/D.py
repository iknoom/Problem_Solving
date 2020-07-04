import sys, math, itertools
input = sys.stdin.readline

T = int(input())

def gcd(a, b):
    if a < b: a, b = b, a
    while b:
        r = a % b
        a, b = b, r
    return a

for _ in range(T):
    a, m = map(int, input().split())
    g = gcd(a,m)

    D = set()
    k = m // g
    while True:
        if k == 1: break
        q = k
        for i in range(2, int(math.sqrt(k)) + 2):
            if k % i == 0:
                D.add(i)
                k //= i
                break
        if k == q:
            D.add(k)
            break

    P = a + m - 1
    Q = a - 1

    ans = P // g
    diff = Q // g
    for i in range(1, len(D) + 1):

        for q in itertools.combinations(D, i):
            qq = 1
            for z in q:
                qq *= z

            if i & 1:
                ans -= P // (qq * g)
                diff -= Q // (qq * g)
            else:
                ans += P // (qq * g)
                diff += Q // (qq * g)


    print(ans - diff)
import sys
input = sys.stdin.readline



N, K = map(int, input().split())
A = list(map(int, input().split()))

def determine(L):
    if L == 0:
        return False
    ret = 0
    for a in A:
        k = a // L
        if k * L == a:
            k -= 1
        ret += k

    if ret <= K:
        return True

    else:
        return False



L = 0
R = 10 ** 9

while L + 1 < R:
    mid = (L + R) // 2
    if determine(mid):
        R = mid
    else:
        L = mid

print(R)
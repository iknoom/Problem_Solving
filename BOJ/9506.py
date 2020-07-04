import sys
input = sys.stdin.readline

def sol(num):
    i = 1
    ret = set()
    while i * i <= num:
        if num % i == 0: ret |= {i, num//i}
        i += 1
    return ret - {num}

while True:
    N = int(input())
    if N == -1: break
    S = sol(N)
    if sum(S) == N:
        ans = str(N) + " = "
        for s in sorted(S):
            ans += str(s) + " + "
        print(ans[:-3])
    else:
        print(f"{N} is NOT perfect.")
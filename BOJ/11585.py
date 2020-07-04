# KMP

def make_fail_function(S):
    fail = [0] * len(S)
    j = 0
    for i in range(1, len(S)):
        while j and S[i] != S[j]: j = fail[j - 1]
        if S[i] == S[j]:
            j += 1
            fail[i] = j
    return fail

def KMP(FROM, FIND, FAIL):
    ret = []
    j = 0
    for i in range(len(FROM)):
        while j and FROM[i] != FIND[j]:
            j = FAIL[j - 1]
        if FROM[i] == FIND[j]:
            if j == len(FIND) - 1:
                ret.append(i - len(FIND))
                j = FAIL[j]
            else:
                j += 1
    return ret

def gcd(a, b):
    if a < b: a, b = a, b
    r = 2
    while r > 1:
        r = b % a
        if r == 0: break
        else:
            b = a
            a = r
    return a

if __name__ == "__main__":
    N = int(input())
    A = input().split()
    B = input().split()
    A = A + A
    A.pop()
    fail = make_fail_function(B)
    ans = KMP(A, B, fail)
    a = len(ans)
    b = len(B)
    g = gcd(a, b)
    print(f"{a//g}/{b//g}")

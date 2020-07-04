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
            if j == min(len(FIND), len(FROM)) - 1:
                return j + 1
            else:
                j += 1
        ret.append(j)
    return max(ret)

A = input()
B = input()
ans = 0
for i in range(len(B)):
    sub = B[i:]
    fail = make_fail_function(sub)
    ans = max(ans, KMP(A, sub, fail))
print(ans)
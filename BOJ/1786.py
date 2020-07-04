# KMP

A = input()
B = input()

def make_fail_function(S):
    fail = [0] * len(S)
    j = 0
    for i in range(1, len(S)):
        while j and B[i] != B[j]: j = fail[j - 1]
        if B[i] == B[j]:
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
                ret.append(i - len(FIND) + 2)
                j = FAIL[j]
            else:
                j += 1
    return ret

fail = make_fail_function(B)
ans = KMP(A, B, fail)
print(len(ans))
print(*ans)
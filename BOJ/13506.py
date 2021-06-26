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
    j = 0
    for i in range(len(FROM)):
        while j and FROM[i] != FIND[j]:
            j = FAIL[j - 1]
        if FROM[i] == FIND[j]:
            if j == len(FIND) - 1:
                return True
            else:
                j += 1
    return False

if __name__ == '__main__':
    A = input()
    fail = make_fail_function(A)
    if fail[-1] == 0:
        print(-1)
    else:
        sub = A[:fail[-1]]
        if KMP(A[1:-1], sub, fail):
            print(sub)
        else:
            fail2 = make_fail_function(sub)
            if fail2[-1] == 0:
                print(-1)
            else:
                print(sub[:fail2[-1]])
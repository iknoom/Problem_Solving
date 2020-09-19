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

def solution(A):
    fail = make_fail_function(A)
    L = len(A) - fail[-1]
    if len(A) % L != 0:
        return 1
    else:
        return len(A) // L

if __name__ == '__main__':
    while True:
        A = input()
        if A == '.': break
        print(solution(A))
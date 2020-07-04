import sys
input = sys.stdin.readline

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
                return True
            else:
                j += 1
    return False


if __name__ == "__main__":
    N, K = map(int, input().split())
    arr = []
    for _ in range(N):
        input()
        arr.append(list(map(int, input().split())))
    ans = "NO"
    A = arr[0]
    for i in range(len(A) - K + 1):
        sub_arr = A[i : i + K]
        sub_arr_r = sub_arr[::-1]
        fail = make_fail_function(sub_arr)
        fail_r = make_fail_function(sub_arr_r)
        flag = True
        for j in range(1, N):
            if not KMP(arr[j], sub_arr, fail) and not KMP(arr[j], sub_arr_r, fail_r):
                flag = False
        if flag:
            ans = "YES"
            break
    print(ans)
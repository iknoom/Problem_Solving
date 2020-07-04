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
    dp = [0] * (len(FROM) + 1)
    p = [0] * N
    for i in range(len(FROM)):
        dp[i + 1] = dp[i]                               # 이전값으로 dp 초기화
        for j in range(N):                              # N개의 문자열에 대해서 모두 KMP

            while p[j] and FROM[i] != FIND[j][p[j]]:    # 실패했을 때
                p[j] = FAIL[j][p[j] - 1]

            if FROM[i] == FIND[j][p[j]]:                # 한 문자 일치
                if p[j] == len(FIND[j]) - 1:            # 전부 일치했을 때
                    dp[i + 1] = max(dp[i + 1], dp[i + 1 - len(FIND[j])] + len(FIND[j]))
                    p[j] = FAIL[j][p[j]]
                else:                                   # 아직 전부 일치하지는 않았을 때
                    p[j] += 1
    return dp[-1]

if __name__ == "__main__":
    LONG = input()
    N = int(input())
    sub = [input() for _ in range(N)]
    fail = [make_fail_function(sub[i]) for i in range(N)]
    print(KMP(LONG, sub, fail))
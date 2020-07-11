from bisect import bisect

def get_dp(scores):
    ret = []
    for score in scores:
        tmp = [0]
        for s in score:
            tmp.append(tmp[-1] + s)
        ret.append(tmp)
    return ret

def get_cuts(scores):
    ret = set()
    for score in scores:
        ret |= set(score)
    return sorted(ret, reverse=True)

def query(p, h, cut, scores, dp, answer):
    users_sum = []
    for user in range(p):
        i = bisect(scores[user], cut)
        user_sum = dp[user][i] + (h - i) * cut
        users_sum.append(user_sum)

    sorted_sum = sorted(users_sum)
    print(cut, users_sum)
    for user in range(p):
        rank = bisect(sorted_sum, users_sum[user])
        answer[user] = min(answer[user], rank)

if __name__ == "__main__":
    p, h = map(int, input().split())
    scores = [sorted(map(int, input().split())) for _ in range(p)]
    dp = get_dp(scores)
    cuts = get_cuts(scores)

    answer = [float('inf')] * p
    for cut in cuts:
        query(p, h, cut, scores, dp, answer)

    print(*answer, sep='\n')
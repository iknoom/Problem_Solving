min_ans = 10**9
max_ans = 0

def sol(S, t):
    global min_ans, max_ans
    if len(S) == 1:
        t += int(S) % 2
        min_ans = min(min_ans, t)
        max_ans = max(max_ans, t)
        return
    t += sum(int(i) % 2 for i in S)
    if len(S) == 2:
        tmp = sum(map(int, S))
        sol(str(tmp), t)
    else:
        N = len(S)
        for i in range(1, N - 1):
            for j in range(i + 1, N):
                tmp = int(S[:i]) + int(S[i:j]) + int(S[j:])
                sol(str(tmp), t)

if __name__ == "__main__":
    N = input()
    sol(N, 0)
    print(min_ans, max_ans)
if __name__ == '__main__':
    N, K = map(int, input().split())
    cur = K * (K + 1) // 2
    if cur > N:
        print(-1)
    else:
        answer = K - 1
        R = N - cur
        if R % K:
            answer += 1
        print(answer)
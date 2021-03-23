def main():
    N = int(input())
    dist = [list(map(int, input().split())) for _ in range(N)]
    answer = 0
    for i in range(N - 1):
        for j in range(i + 1, N):
            flag = True
            for k in range(N):
                if k in [i, j]: continue
                if dist[i][j] == dist[i][k] + dist[k][j]:
                    flag = False
                if dist[i][j] > dist[i][k] + dist[k][j]:
                    print(-1)
                    return
            if flag:
                answer += dist[i][j]
    print(answer)

if __name__ == '__main__':
    main()
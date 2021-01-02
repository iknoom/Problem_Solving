from sys import stdin

input = stdin.readline

if __name__ == "__main__":
    N = int(input())
    AB = [tuple(map(int, input().split())) for _ in range(N)]
    Aoki = sum(AB[i][0] for i in range(N))
    Takahashi = 0
    AB.sort(key=lambda x : x[0] * 2 + x[1], reverse=True)
    ans = -1
    for i in range(N):
        a, b = AB[i]
        Aoki -= a
        Takahashi += (a + b)
        if Aoki < Takahashi:
            ans = i + 1
            break
    print(ans)


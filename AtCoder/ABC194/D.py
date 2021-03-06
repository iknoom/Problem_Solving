from sys import stdin
input = stdin.readline

if __name__ == '__main__':
    N = int(input())
    answer = 0.0
    for cur in range(1, N):
        answer += N / (N - cur)
    print(answer)
from itertools import permutations
INF = 10 ** 9

if __name__ == '__main__':
    X = input()
    N = len(X)
    answer = INF
    for p in permutations(X, N):
        cur = int(''.join(p))
        if int(X) < cur:
            answer = min(answer, cur)
    if answer == INF:
        print(0)
    else:
        print(answer)
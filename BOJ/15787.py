from sys import stdin
input = stdin.readline

if __name__ == '__main__':
    N, M = map(int, input().split())
    train = [0 for _ in range(N)]
    for _ in range(M):
        query = list(map(int, input().split()))
        if query[0] == 1:
            i, x = query[1:]
            train[i - 1] |= (1 << (x - 1))
        if query[0] == 2:
            i, x = query[1:]
            if train[i - 1] & (1 << (x - 1)):
                train[i - 1] -= (1 << (x - 1))
        if query[0] == 3:
            i = query[1]
            train[i - 1] <<= 1
            train[i - 1] %= (1 << 20)
        if query[0] == 4:
            i = query[1]
            train[i - 1] >>= 1
    print(len(set(train)))
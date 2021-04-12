from sys import stdin
input = stdin.readline


def solution():
    n, k = map(int, input().split())
    al = [chr(97 + i) for i in range(k)]
    S = []
    while True:
        for i in range(k):
            S.append(al[i])
            if len(S) == n:
                print(''.join(S))
                return
            for j in range(i + 1, k):
                S.append(al[i])
                if len(S) == n:
                    print(''.join(S))
                    return
                S.append(al[j])
                if len(S) == n:
                    print(''.join(S))
                    return

if __name__ == '__main__':
    solution()
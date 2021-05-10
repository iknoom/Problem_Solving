from sys import stdin
input = stdin.readline


def solution():
    N, M = map(int, input().split())
    B = [list(map(int, input().split())) for _ in range(N)]
    C = [0] * N
    for i in range(M):
        inner = []
        outer = []
        for j in range(N):
            if B[j][i]:
                inner.append(j)
            else:
                outer.append(j)
        inner_max = max([C[j] for j in inner] + [-1])
        outer_min = min([C[j] for j in outer] + [float('inf')])
        if outer_min < inner_max:
            return "NO"
        for j in outer:
            C[j] += 1
    return "YES"

if __name__ == '__main__':
    answer = solution()
    print(answer)
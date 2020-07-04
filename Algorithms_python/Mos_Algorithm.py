import sys
from math import sqrt
input = sys.stdin.readline

def get_query(N, M):
    query = []
    sqrtN = sqrt(N)
    for i in range(M):
        l, r = map(int, input().split())
        l -= 1
        r -= 1
        query.append((l, r, i))
    query.sort(key=lambda x : (x[0] // sqrtN, x[1]))
    return query

def get_result(N, M, A, query):
    result = [0] * M
    s, e, n = query[0]
    S = sum(A[s:e + 1])
    result[n] = S
    for si, ei, i in query:
        while si < s:
            s -= 1
            S += A[s]
        while si > s:
            S -= A[s]
            s += 1
        while ei > e:
            e += 1
            S += A[e]
        while ei < e:
            S -= A[e]
            e -= 1
        result[i] = S
    return result

if __name__ == "__main__":
    N, M = map(int, input().split())
    A = list(map(int, input().split()))

    query = get_query(N, M)
    answer = get_result(N, M, A, query)

    print(*answer, sep='\n')
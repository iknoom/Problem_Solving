from sys import stdin
input = stdin.readline

def get_cost(CJ, JC, S):
    ret = 0
    for i in range(len(S) - 1):
        if S[i] == 'C' and S[i + 1] == 'J':
            ret += CJ
        if S[i] == 'J' and S[i + 1] == 'C':
            ret += JC
    return ret

def get_min_cost(CJ, JC, S):
    costs = []
    for a, b in [('J', 'J'), ('C', 'C'), ('J', 'C'), ('C', 'J')]:
        dup_S = S[:]
        for i in range(len(dup_S)):
            if dup_S[i] == '?':
                dup_S[i] = a if i % 2 else b
        costs.append(get_cost(CJ, JC, dup_S))
    return min(costs)

def solution():
    query = input().split()
    CJ, JC = map(int, query[:2])
    S = list(query[2])
    ret = get_cost(CJ, JC, S)
    for i in range(len(S)):
        if S[i] != '?':
            continue
        j = i
        while j < len(S) and S[j] == '?':
            j += 1
        L = max(i - 1, 0)
        R = min(j + 1, len(S))
        ret += get_min_cost(CJ, JC, S[L:R])
        for k in range(i, j):
            S[k] = 'X'
    return ret

if __name__ == '__main__':
    T = int(input())
    for case in range(1, T + 1):
        answer = solution()
        print("Case #"+str(case) + ":", answer)
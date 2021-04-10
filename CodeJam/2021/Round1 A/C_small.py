from sys import stdin
from math import gcd
input = stdin.readline

def solution(N, Q, Answers):
    predicts = []
    for i in range(1 << Q):
        cur = ""
        for j in range(Q):
            if i & (1 << j):
                cur = cur + "T"
            else:
                cur = cur + "F"
        flag = True
        for Answer, point in Answers:
            p = sum(Answer[k] == cur[k] for k in range(Q))
            if p != point:
                flag = False
        if flag:
            predicts.append(cur)

    # eval max
    ret = []
    for i in range(1 << Q):
        cur = ""
        for j in range(Q):
            if i & (1 << j):
                cur = cur + "T"
            else:
                cur = cur + "F"
        S = 0
        for predict in predicts:
            S += sum(predict[k] == cur[k] for k in range(Q))
        ret.append((S, cur))

    ret.sort(reverse=True)
    z, y = ret[0]
    w = len(predicts)
    return y, z, w

if __name__ == '__main__':
    T = int(input())
    for case in range(1, T + 1):
        N, Q = map(int, input().split())
        Answers = []
        for _ in range(N):
            x, y = input().split()
            Answers.append((x, int(y)))
        y, z, w = solution(N, Q, Answers)
        print(f'Case #{case}: {y} {z//gcd(z,w)}/{w//gcd(z,w)}')
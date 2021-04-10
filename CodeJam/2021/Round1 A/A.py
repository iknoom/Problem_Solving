from sys import stdin
input = stdin.readline

def solution(N, X):
    ret = 0
    for i in range(1, N):
        if X[i - 1] < X[i]:
            continue
        if len(str(X[i - 1])) == len(str(X[i])):
            X[i] *= 10
            ret += 1
            continue
        strY = str(X[i])
        strX = str(X[i - 1])
        preX = strX[:len(strY)]
        suX = strX[len(strY):]
        if preX == strY and len(suX) >= len(str(int(suX) + 1)):
            ret += len(suX)
            X[i] = X[i - 1] + 1
        else:
            while X[i - 1] >= X[i]:
                ret += 1
                X[i] *= 10
    return ret

if __name__ == '__main__':
    T = int(input())
    for case in range(1, T + 1):
        N = int(input())
        X = list(map(int, input().split()))
        answer = solution(N, X)
        print("Case #"+str(case) + ": "+str(answer))
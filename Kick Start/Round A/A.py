import sys
input = sys.stdin.readline

def solution(N, K, S):
    ret = 0
    for i in range(N // 2):
        if S[i] != S[-i-1]: ret += 1
    return abs(K - ret)

if __name__ == '__main__':
    T = int(input())
    for case in range(1, T + 1):
        N, K = map(int, input().split())
        S = input().rstrip()
        answer = solution(N, K, S)
        print("Case #" + str(case) + ":", answer)
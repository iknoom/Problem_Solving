from sys import stdin
input = stdin.readline

def solution(M, primes):
    ret = 0
    N = len(primes)
    for i in range(1, (1 << N) - 1):
        sum_p = 0
        mul_p = 1
        for j in range(N):
            if i & (1 << j):
                sum_p += primes[j]
            else:
                mul_p *= primes[j]
        if sum_p == mul_p:
            ret = max(ret, sum_p)
    return ret

if __name__ == '__main__':
    T = int(input())
    for case in range(1, T + 1):
        M = int(input())
        primes = []
        for _ in range(M):
            p_i, n_i = map(int, input().split())
            for i in range(n_i):
                primes.append(p_i)
        answer = solution(M, primes)
        print("Case #"+str(case) + ": "+str(answer))
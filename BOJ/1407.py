def solution(K):
    ret = 0
    for i in range(100):
        exp = 2 ** i
        if exp > K: break
        n = K // exp
        ret -= n * (exp//2)
        ret += n * exp
    return ret

if __name__ == "__main__":
    A, B = map(int, input().split())
    print(solution(B) - solution(A - 1))
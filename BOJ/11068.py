def sol(N, i):
    ret = []
    while N:
        ret.append(N % i)
        N //= i
    for i in range(len(ret)):
        if ret[i] != ret[-i-1]:
            return False
    return True


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        N = int(input())
        answer = 0
        for i in range(2, 65):
            if sol(N, i):
                answer = 1
                break
        print(answer)
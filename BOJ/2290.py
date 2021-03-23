MOD = 10 ** 9 + 7

def my_pow(A, X):
    ret = 1
    cur = A
    while X:
        if X % 2:
            ret *= cur
            ret %= MOD
        X //= 2
        cur *= cur
        cur %= MOD
    return ret

if __name__ == '__main__':
    A = int(input())
    X = int(input())
    print(my_pow(A, X))

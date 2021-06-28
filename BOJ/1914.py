from sys import setrecursionlimit
setrecursionlimit(2**21)

def sol(n, _from, _to, _mid):
    if n == 0:
        return
    sol(n - 1, _from, _mid, _to)
    print(_from, _to)
    sol(n - 1, _mid, _to, _from)


if __name__ == '__main__':
    N = int(input())
    print(2 ** N - 1)
    if N <= 20:
        sol(N, 1, 3, 2)
import math

INF = float('inf')

def pow(N):
    if N > 32:
        return INF
    return 2 ** N

def fac(N):
    if N > 13:
        return INF
    return math.factorial(N)

func = {
    "O(N)": lambda x: x,
    "O(N^2)": lambda x: x * x,
    "O(N^3)": lambda x: x * x * x,
    "O(2^N)": pow,
    "O(N!)": fac
}

if __name__ == '__main__':
    C = int(input())
    for _ in range(C):
        time_complex, _N, _T, _L = input().split()
        N, T, L = map(int, [_N, _T, _L])
        limit = L * 100000000
        test = func[time_complex](N) * T
        if limit < test:
            print("TLE!")
        else:
            print("May Pass.")
import math

def FFT(f, w):
    n = len(f)
    if n == 1: return
    even = []
    odd = []
    for i in range(n):
        if i & 1: odd.append(f[i])
        else: even.append(f[i])

    FFT(even, w * w)
    FFT(odd, w * w)

    wp = complex(1, 0)
    for i in range(n//2):
        f[i] = even[i] + wp * odd[i]
        f[i + n//2] = even[i] - wp * odd[i]
        wp *= w

if __name__ == '__main__':
    N = int(input())
    X = list(map(int, input().split()))
    Y = list(map(int, input().split()))

    M = 2 ** (2 * N).bit_length()
    diff = M - 2 * N

    A = [0] * diff + X[:] + X[:]
    B = [0] * diff + Y[::-1] + [0] * N
    x_1 = complex(math.cos(2 * math.pi / M), math.sin(2 * math.pi / M))

    FFT(A, x_1)
    FFT(B, x_1)

    C = [A[i] * B[i] for i in range(M)]
    FFT(C, -x_1)
    for i in range(M):
        C[i] = C[i].real / M

    print(round(max(C)))
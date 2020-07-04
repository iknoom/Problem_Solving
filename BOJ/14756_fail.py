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

def convolution(A, B):
    n = 1
    while n <= len(A) or n <= len(B):
        n *= 2
    n *= 2
    A += [0] * (n - len(A))
    B += [0] * (n - len(B))
    C = [0] * n
    x_1 = complex(math.cos(2 * math.pi / n), math.sin(2 * math.pi / n))
    FFT(A, x_1)
    FFT(B, x_1)
    for i in range(n):
        C[i] = A[i] * B[i]
    FFT(C, complex(1,0) / x_1)
    for i in range(n):
        C[i] = round(C[i].real / n)
    return C

if __name__ == '__main__':
    n, l, m, W = map(int, input().split())
    X = [list(map(int, input().split())) for _ in range(m)]
    Y = [list(map(int, input().split())) + [0] * (n - l) for _ in range(m)]
    ans = [0] * (n - l + 1)

    for i in range(m):
        C = convolution(X[i], Y[i][::-1])
        for i in range(n - l + 1):
            ans[i] += C[l + i + 1]
    print(sum(ans[i] > W for i in range(n - l + 1)))
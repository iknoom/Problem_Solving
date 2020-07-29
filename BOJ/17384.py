def fill(n, s):
    for i in range(n):
        bits[s + i] = '#'

def solution(n, s, k):
    d = 2 ** (k - 2)
    if n == 4 * d:
        fill(n, s)
    elif n > 3 * d:
        fill(2 * d, s)
        solution(n - 2 * d, s + 2 * d, k - 1)
    elif n > 2 * d:
        solution(n - d, s, k - 1)
        fill(d, s + 2 * d)

if __name__ == "__main__":
    N = int(input())
    K = (N - 1).bit_length()
    bits = ['.'] * (2 ** K)
    solution(N, 0, K)
    print(''.join(bits))

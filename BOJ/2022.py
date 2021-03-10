from math import sqrt

def det(x, y, c, L):
    left = sqrt(x * x - L * L)
    right = sqrt(y * y - L * L)
    a = L * c / left
    b = (L - a) * right / L
    if b > c:
        return True
    else:
        return False


if __name__ == '__main__':
    x, y, c = map(float, input().split())
    l = 0
    r = min(x, y)
    while r - l > 10**(-6):
        mid = (l + r) / 2
        if det(x, y, c, mid):
            l = mid
        else:
            r = mid
    print(f'{r:.6f}')
def gcd(a, b):
    if a < b: a, b = a, b
    r = 2
    while r > 1:
        r = b % a
        if r == 0: break
        else:
            b = a
            a = r
    return a
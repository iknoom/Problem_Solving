from math import log2, ceil
N = abs(int(input()))
if N == 0:
    print(0)
elif N & 1:
    print(ceil(log2(N + 1)))
else:
    print(-1)
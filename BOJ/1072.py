import math
X, Y = map(int, input().split())
if X == Y: print(-1)
else:
    T = (Y * 100) // X
    if T == 99: print(-1)
    else: print(math.ceil((T * X + X - 100 * Y) / (99 - T)))
from math import sqrt

Xa, Ya, Xb, Yb, Xc, Yc = map(int, input().split())
if (Yc - Ya) * (Xb - Xa) == (Xc - Xa) * (Yb - Ya):
    print(-1)
else:
    R = [sqrt((Xa - Xb)**2 + (Ya - Yb)**2) + sqrt((Xa - Xc)**2 + (Ya - Yc)**2),
         sqrt((Xa - Xb)**2 + (Ya - Yb)**2) + sqrt((Xb - Xc)**2 + (Yb - Yc)**2),
         sqrt((Xa - Xc)**2 + (Ya - Yc)**2) + sqrt((Xb - Xc)**2 + (Yb - Yc)**2)]
    R.sort()
    print((R[-1] - R[0]) * 2)
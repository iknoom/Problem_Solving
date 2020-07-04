H,W = map(int,input().split())
h,w = H//2, W//2
h1, w1 = h, w
if H & 1:
    h += 1

if W & 1:
    w += 1

if H == 1:
    print(1)
elif W == 1:
    print(1)
else:
    print(w * h + w1 * h1)
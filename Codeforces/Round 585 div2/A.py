a = int(input())
b = int(input())
k1 = int(input())
k2 = int(input())
n = int(input())

A = a*k1
B = b*k2

tmin = max(0, n - (k1-1)*a - (k2-1)*b)
tmax = -1

if n >= A + B: tmax = a+b

elif k1 < k2:
    if n <= A:
        tmax = n//k1
    else:
        tmax = a + (n-A)//k2
else:
    if n <= B:
        tmax = n//k2
    else:
        tmax = b + (n-B)//k1

print(tmin, tmax)




import sys, math
input = sys.stdin.readline

A, B, H, M = map(int, input().split())
h = H / 12 + (M / 60) / 12
m = M / 60

hx = 360 * h
mx = 360 * m
dx = min(abs(hx - mx), 360 - abs(hx - mx))
dtheta = math.radians(dx)
ret = (A * math.sin(dtheta)) ** 2 + (B - A * math.cos(dtheta)) ** 2
print(math.sqrt(ret))
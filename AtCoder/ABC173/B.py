import sys
input = sys.stdin.readline

N = int(input())

a, b, c, d = 0, 0, 0, 0

for _ in range(N):
    S = input().rstrip()
    if S == "AC": a += 1
    elif S == "WA": b += 1
    elif S == "TLE": c += 1
    else: d += 1

print("AC x", a)
print("WA x", b)
print("TLE x", c)
print("RE x", d)
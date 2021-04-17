from sys import stdin
input = stdin.readline

X, Y, Z = map(int, input().split())
YZ = Y * Z
A = YZ // X
if YZ % X == 0:
    A -= 1
print(A)
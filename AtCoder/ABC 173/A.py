import sys
input = sys.stdin.readline

N = int(input())

k = N % 1000

if k == 0:
    print(0)
else:
    print(1000 - k)
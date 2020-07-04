import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    n = int(input())
    print(n//2 + n%2)
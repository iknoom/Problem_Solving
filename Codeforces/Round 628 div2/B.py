import sys

input = sys.stdin.readline

Q = int(input())

for _ in range(Q):
    n = int(input())
    A = list(map(int,input().split()))
    print(len(set(A)))
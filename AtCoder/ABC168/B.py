import sys
input = sys.stdin.readline

K = int(input())
S = input().rstrip()

if len(S) > K:
    print(S[:K] + '...')
else:
    print(S)
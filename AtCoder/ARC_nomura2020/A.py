import sys
input = sys.stdin.readline

H1, M1, H2, M2, K = map(int, input().split())
S = (H2 - H1) * 60 + M2 - M1
print(S - K)
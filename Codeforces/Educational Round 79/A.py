import sys
input = sys.stdin.readline

for _ in range(int(input())):
    a, b, c = sorted(map(int,input().split()))
    if a + b + 1 < c: print("NO")
    else: print("YES")



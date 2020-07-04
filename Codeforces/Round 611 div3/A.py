import sys
input = sys.stdin.readline

for _ in range(int(input())):
    a,b = map(int,input().split())
    h = 23 - a
    m = 60 - b
    print(h*60 + m)
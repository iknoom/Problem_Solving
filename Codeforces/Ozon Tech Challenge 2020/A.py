import sys
input = sys.stdin.readline

q = int(input())
for _ in range(q):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    print(*sorted(a))
    print(*sorted(b))

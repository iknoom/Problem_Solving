import sys
input = sys.stdin.readline

n, m = map(int,input().split())
A = input().rstrip().split()
B = input().rstrip().split()
for _ in range(int(input())):
    t = int(input())
    print(A[t%n - 1]+B[t%m - 1])

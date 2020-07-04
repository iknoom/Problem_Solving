import sys
input = sys.stdin.readline

T = int(input())

for case in range(1, T + 1):
    N = int(input())
    print("Case #" + str(case) + ":")
    k = 1
    print(1, 1)
    N -= 1
    while N >= k:
        print(k + 1, 2)
        N -= k
        k += 1
    while N:
        print(k, 1)
        N -= 1
        k -= 1

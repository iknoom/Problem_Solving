import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, s = map(int,input().split())
    A = list(map(int,input().split()))
    if sum(A) <= s:
        print(0)
        continue

    max_a = 0
    max_idx = -1
    flag = False
    for i in range(n):
        s -= A[i]

        if A[i] > max_a:
            s += A[i]
            s -= max_a
            max_a = A[i]
            if s >= 0:
                max_idx = i + 1
            else:
                break
        if s < 0:
            break

    print(max_idx)







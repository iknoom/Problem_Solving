N = int(input())
M, K = map(int, input().split())
A = list(map(int, input().split()))
MK = M * K
if sum(A) < MK:
    print("STRESS")
else:
    count = 0
    A.sort(reverse=True)
    for i in range(N):
        if MK <= 0:
            break
        MK -= A[i]
        count += 1
    print(count)
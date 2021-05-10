A = input()
B = input()
N = len(A)
M = len(B)

i = 0
j = 0
while i < N and i < M:
    if A[i] == B[i]:
        i += 1
    else:
        break
while j < N and j < M:
    if A[-j-1] == B[-j-1]:
        j += 1
    else:
        break

if N > M:
    print(max(0, M - i - j))
else:
    if i + j >= N:
        print(M - N)
    else:
        print(M - i - j)
from functools import cmp_to_key

def my_cmp(x, y):
    return int(str(y) + str(x)) - int(str(x) + str(y))

K, N = map(int, input().split())
A = [int(input()) for _ in range(K)]
answer = []
for i in range(K):
    B = A[:]
    for _ in range(N - K):
        B.append(A[i])
    B.sort(key=cmp_to_key(my_cmp))
    answer.append(int(''.join(map(str, B))))
print(max(answer))
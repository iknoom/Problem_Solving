N = int(input())

answer = 0
cur = 1
while N:
    if N % 2:
        answer += cur
    N //= 2
    cur *= 3
print(answer)
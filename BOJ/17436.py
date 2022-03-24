N, M = map(int, input().split())
primes = list(map(int, input().split()))
answer = 0
for i in range(N):
    for bits in range(1 << i):
        cur = primes[i]
        flag = 1
        for j in range(i):
            if (1 << j) & bits:
                cur *= primes[j]
                flag *= -1
        answer += flag * (M // cur)
print(answer)
MAX_SIZE = 5000001
primes = [list() for _ in range(MAX_SIZE)]
for i in range(2, MAX_SIZE):
    if primes[i]:
        continue
    for j in range(i, MAX_SIZE, i):
        primes[j].append(i)

N = int(input())
arr = list(map(int, input().split()))
for element in arr:
    ret = []
    for prime in primes[element]:
        while element % prime == 0:
            element //= prime
            ret.append(prime)
    print(*ret)
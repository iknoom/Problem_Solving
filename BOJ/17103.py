prime = []
is_prime = [True] * 1000001
is_prime[0] = is_prime[1] = False
for i in range(2, 1000001):
    if is_prime[i]:
        prime.append(i)
        for j in range(i * 2, 1000001, i):
            is_prime[j] = False

T = int(input())
prime_set = set(prime)
for _ in range(T):
    N = int(input())
    answer = 0
    for p in prime:
        if p > N // 2:
            break
        if N - p in prime_set:
            answer += 1
    print(answer)
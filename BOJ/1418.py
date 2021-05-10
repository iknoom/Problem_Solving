from sys import stdin
input = stdin.readline

def get_max_prime(a):
    primes = [1]
    for i in range(2, a):
        if i * i > a:
            break
        if a % i == 0:
            primes.append(i)
            while a % i == 0:
                a //= i
    if a > 1:
        primes.append(a)
    return max(primes)

if __name__ == '__main__':
    N = int(input())
    K = int(input())
    answer = 0
    for i in range(1, N + 1):
        if get_max_prime(i) <= K:
            answer += 1
    print(answer)
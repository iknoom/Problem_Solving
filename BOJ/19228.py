from sys import stdin
input = stdin.readline

def make_fact(n):
    fact = [1, 1]
    for i in range(2, n + 1):
        fact.append((fact[-1] * i))
    return fact

def combination(n, k):
    global fact
    if n <= k: return 1
    if n < 2: return 1
    return fact[n] // (fact[n - k] * fact[k])

def get_ans(keys):
    ret = 1
    j = sum(keys) + 1
    s = 0
    for i in range(j, -1, -1):
        n = min(j - 1, j - i) - s
        if keys[i] > 0 and n < keys[i]: return 0
        ret *= combination(n, keys[i])
        s += keys[i]
    return ret

def sol(n):
    keys = [0] * 21
    for i in range(2, 21):
        if n == 0: break
        keys[n % i] += 1
        n //= i
    ret = get_ans(keys)
    if keys[0] > 0:
        keys[0] -= 1
        ret -= get_ans(keys)
    return ret - 1

if __name__ == "__main__":
    fact = make_fact(21)
    t = int(input())
    for _ in range(t):
        N = int(input())
        print(sol(N))
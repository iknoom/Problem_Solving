def int_fact(num):
    ret = []
    while True:
        if num == 1: break
        tmp = num
        div = 2
        while div * div <= num:
            if num % div == 0:
                ret.append(div)
                num //= div
                break
            div += 1
        if num == tmp:
             ret.append(num)
             break
    return ret

N = int(input())
prime = list(set(int_fact(N)))
M = len(prime)
ans = N
for i in range(1, 1 << M):
    mul = 1
    sign = 1
    for j in range(M):
        if i & (1 << j):
            mul *= prime[j]
            sign *= -1
    ans += sign * (N // mul)
print(ans)
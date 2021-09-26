MAX_SIZE = 5000001
factors = [0] * MAX_SIZE
for i in range(2, MAX_SIZE):
    if factors[i]:
        continue
    for j in range(i, MAX_SIZE, i):
        if factors[j]:
            factors[j] = min(factors[j], i)
        else:
            factors[j] = i

N = int(input())
arr = list(map(int, input().split()))
for element in arr:
    ret = []
    while element > 1:
        ret.append(factors[element])
        element //= factors[element]
    print(*ret)
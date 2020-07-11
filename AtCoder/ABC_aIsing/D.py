def evaluation(number):
    loop = 0
    while number != 0:
        popcount = 0
        for i in range(30):
            if (1 << i) & number:
                popcount += 1
        number %= popcount
        loop += 1
    return loop

def get_zero_S(for_zero):
    ret = 0
    tmp = 1
    for i in range(N):
        if X[-i - 1] == '1':
            ret += tmp
            ret %= for_zero
        tmp *= 2
        tmp %= for_zero
    return ret

def get_one_S(for_one):
    ret = 0
    tmp = 1
    for i in range(N):
        if X[-i - 1] == '1':
            ret += tmp
            ret %= for_one
        tmp *= 2
        tmp %= for_one
    return ret

def solution(N, X, for_zero, for_one):
    zero_sum = get_zero_S(for_zero)
    one_sum = get_one_S(for_one)
    numbers = [0] * N
    tmp_zero = 1
    tmp_one = 1
    for i in range(N):
        if X[-i - 1] == '1':
            numbers[-i - 1] = (one_sum - tmp_one) % for_one
        else:
            numbers[-i - 1] = (zero_sum + tmp_zero) % for_zero
        tmp_zero *= 2
        tmp_zero %= for_zero
        tmp_one *= 2
        tmp_one %= for_one
    return numbers

def exception_solution(N, X, for_zero):
    numbers = [0] * N
    zero_sum = get_zero_S(for_zero)
    tmp_zero = 1
    for i in range(N):
        if X[-i - 1] == '1': pass
        else: numbers[-i - 1] = (zero_sum + tmp_zero) % for_zero
        tmp_zero *= 2
        tmp_zero %= for_zero
    return numbers

if __name__ == "__main__":
    N = int(input())
    X = input()
    tmp = sum(X[i] == '1' for i in range(N))

    for_zero = tmp + 1
    for_one = tmp - 1

    counts = [1] * N

    if tmp == 1:
        for i in range(N):
            if X[i] == '1': counts[i] = 0
        numbers = exception_solution(N, X, for_zero)
    else:
        numbers = solution(N, X, for_zero, for_one)

    for i in range(N):
        counts[i] += evaluation(numbers[i])

    print(*counts, sep='\n')

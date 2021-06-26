def combination(n, k):
    # nCk
    a = b = 1
    for i in range(k): a *= n - i;b *= i + 1
    return a // b

if __name__ == '__main__':
    N, L, I = map(int, input().split())
    answer = ''
    for k in range(N - 1, -1, -1):
        x = sum(combination(k, j) for j in range(L + 1))
        if x >= I:
            answer += '0'
        else:
            answer += '1'
            I -= x
            L -= 1
    print(answer)
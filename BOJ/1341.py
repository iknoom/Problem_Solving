from sys import stdin
input = stdin.readline

# a/b = k*a / k*b
# k*b = sum(2^i)   all i = [2^0, 2^1, ..., 2^60]
# k*b = 1, 4 - 1, 8 - 1, 16 - 1, ..., 2^60 - 1
# k*a = sum(2^j)   some j = [2^0, 2^1, ..., 2^60]


if __name__ == '__main__':
    b_set = [2**i - 1 for i in range(2, 61)]
    print(b_set)
    a, b = map(int, input().split())
    # get k
    k = -1
    for b_i in b_set:
        if b_i % b == 0:
            k = b_i // b
            break
    if a == 0:
        print('-')
    elif a == b:
        print('*')



    elif k < 0:
        print(-1)
    else:
        a *= k
        b *= k
        answer = []
        j = 0
        while True:
            if not (1 << j) & b:
                break
            if (1 << j) & a:
                answer.append('*')
            else:
                answer.append('-')
            j += 1
        answer.reverse()
        print(''.join(answer))
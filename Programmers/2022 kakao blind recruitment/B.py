def is_prime(x):
    if x < 2:
        return False
    for i in range(2, x):
        if i * i > x:
            break
        if x % i == 0:
            return False
    return True

def solution(n, k):
    tmp = []
    while n:
        tmp.append(str(n % k))
        n //= k
    tmp.reverse()
    convert_n_base_k = ''.join(tmp)
    answer = 0
    for num in convert_n_base_k.split('0'):
        if not num:
            continue
        if is_prime(int(num)):
            answer += 1
    return answer


if __name__ == '__main__':
    # print(solution(437674, 3))
    print(solution(110011, 10))
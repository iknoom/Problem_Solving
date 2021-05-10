def is_pal(x):
    string = str(x)
    n = len(string)
    for i in range(n):
        if string[i] != string[-i-1]:
            return False
    return True

def is_prime(x):
    if x == 1:
        return False
    if x == 2 or x == 3:
        return True
    for i in range(2, x):
        if i * i > x:
            break
        if x % i == 0:
            return False
    return True

if __name__ == '__main__':
    N = int(input())
    while True:
        if not is_pal(N):
            continue
        if is_prime(N):
            print(N)
            break
        N += 1
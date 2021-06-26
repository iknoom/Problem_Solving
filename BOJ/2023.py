
def is_prime(x):
    for i in range(2, x):
        if i * i > x:
            break
        if x % i == 0:
            return False
    return True

if __name__ == '__main__':
    N = int(input())
    queue = [2, 3, 5, 7]
    for _ in range(N - 1):
        next_queue = []
        for x in queue:
            for i in range(10):
                if is_prime(x * 10 + i):
                    next_queue.append(x * 10 + i)
        queue = next_queue
    print(*queue, sep='\n')
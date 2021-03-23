from sys import stdin
input = stdin.readline

def solution(x):
    cur = 1
    while True:
        if x <= cur * 10:
            break
        k = (x % (cur * 10)) // cur
        x -= cur * k
        if k >= 5:
            cur *= 10
            x += cur
        else:
            cur *= 10
    return x

if __name__ == '__main__':
    n = int(input())
    for _ in range(n):
        x = int(input())
        answer = solution(x)
        print(answer)
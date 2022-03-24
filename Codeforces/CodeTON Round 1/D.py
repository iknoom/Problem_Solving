import sys

input = sys.stdin.readline

def solution():
    n = int(input())

    arr = set()
    cur = 1
    while cur <= 10 ** 18:
        arr.add(cur)
        cur *= 2
    # 2의 제곱수
    if n in arr:
        print(-1)
        return
    # 홀수
    if n % 2 == 1:
        print(2)
        return
    # 그 외 모두 가능
    n *= 2
    a = 1
    while n % 2 == 0:
        n //= 2
        a *= 2
    print(min(a, n))


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()
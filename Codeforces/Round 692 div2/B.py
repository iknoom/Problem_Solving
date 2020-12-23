import sys

input = sys.stdin.readline

def is_ok(n):
    divs = set(map(int, str(n))) - {0}
    for div in divs:
        if n % div != 0:
            return False
    return True

def solution():
    n = int(input())
    while True:
        if is_ok(n):
            print(n)
            return
        n += 1

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()
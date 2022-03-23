import sys

input = sys.stdin.readline

is_sqare = set()
for i in range(1, 100):
    is_sqare.add(i * i)

def solution():
    a, b = map(int, input().split())
    if a == 0 and b == 0:
        print(0)
    elif (a * a + b * b) in is_sqare:
        print(1)
    else:
        print(2)

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()
from sys import stdin
from itertools import permutations
import random
import matplotlib.pyplot as plt
input = stdin.readline

def get_value(s):
    min_value = float('inf')
    max_value = -1
    answer = 0
    for c in s:
        min_value = min(min_value, c)
        max_value = max(max_value, c)
        answer += max_value - min_value
    return answer

def solution():
    # n = int(input())
    # s = list(map(int, input().split()))
    n = 8
    s = [random.randint(1, 500) for _ in range(n)]
    MIN = 10**18
    answer = []
    for per in permutations(s):
        value = get_value(per)
        if value < MIN:
            MIN = value
            answer = [per]
        elif value == MIN:
            answer.append(per)
    print(MIN)
    print(*answer, sep='\n')
    X = list(answer[0])
    for i in range(n):
        print(sum(abs(X[i] - X[j]) for j in range(n)))
    plt.plot(list(answer[0]))
    plt.show()

if __name__ == '__main__':
    solution()
from sys import stdin
input = stdin.readline

def solution():
    n, k = map(int, input().split())
    answer = []
    for i in reversed(range(1, n + 1)):
        if i == k:
            continue
        if k - i > i:
            break
        answer.append(i)
    print(len(answer))
    print(*answer)

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()
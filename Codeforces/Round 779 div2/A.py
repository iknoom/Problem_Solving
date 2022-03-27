import sys

input = sys.stdin.readline

def solution():
    n = int(input())
    S = input().rstrip()
    answer = 0
    for i in range(n - 1):
        if S[i] == S[i + 1] == '0':
            answer += 2
    for i in range(n - 2):
        if S[i] == '0' and S[i + 1] == '1' and S[i + 2] == '0':
            answer += 1
    print(answer)

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()
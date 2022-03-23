import sys

input = sys.stdin.readline


def solution():
    n = int(input())
    S = input().rstrip()
    stack = []
    c = 0
    for i in range(n):
        if not stack:
            stack.append(S[i])
        else:
            if len(stack) == 1:
                if stack[0] == ')' and S[i] == '(':
                    stack.append(S[i])
                else:
                    stack.pop()
                    c += 1
            else:
                if S[i] == ')':
                    stack = []
                    c += 1
                else:
                    stack.append(S[i])
    print(c, len(stack))

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()
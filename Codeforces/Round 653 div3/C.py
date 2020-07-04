import sys
input = sys.stdin.readline


T = int(input())

for _ in range(T):
    n = int(input())
    s = input().rstrip()
    stack = []
    for i in range(n):
        if s[i] == '(':
            stack.append('(')
        else:
            if stack and stack[-1] == '(':
                stack.pop()
            else:
                stack.append(')')
    print(len(stack)//2)
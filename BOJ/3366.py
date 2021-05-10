from sys import stdin
input = stdin.readline

n = int(input())
A = [int(input()) for _ in range(n)]
answer = 0

stack = []
for i in range(n):
    if not stack:
        stack.append(A[i])
    elif stack[-1] >= A[i]:
        stack.append(A[i])
    else:
        while stack and stack[-1] < A[i]:
            x = stack.pop()
            if stack:
                answer += min(stack[-1], A[i])
            else:
                answer += A[i]
        stack.append(A[i])

if len(stack) > 1:
    answer += sum(stack[:-1])
print(answer)
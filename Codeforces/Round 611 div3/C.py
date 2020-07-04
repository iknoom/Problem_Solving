N = int(input())

A = list(map(int,input().split()))

receive = [False] * N

for f in A:
    if f:
        receive[f-1] = True

stack = []
cnt = 0
x = -1
for i in range(N):
    if not receive[i]:
        stack.append(i+1)
        if A[i] == 0:
            cnt += 1
            x = i + 1
print(cnt)
if cnt != 1:
    stack.reverse()

    print(stack)
    stack2 = []

    for i in range(N):
        if A[i] == 0:
            k = stack.pop()
            if i+1 == k:
                stack2.append(k)
            else:
                A[i] = k

    if stack2:
        q = stack2.pop()
        stack2.insert(0, q)

    stack2.reverse()
    print(stack2)
    for i in range(N):
        if A[i] == 0:
            k = stack2.pop()
            A[i] = k

    print(*A)

else:
    for i in range(N):
        if A[i] == 0 and x != i + 1:
            A[i] = x
            break
    stack.remove(x)
    stack.reverse()
    for i in range(N):
        if A[i] == 0:
            A[i] = stack.pop()
    print(*A)
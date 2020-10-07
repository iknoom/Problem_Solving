L = [-1, 0]
R = []
stack = []
cur = 0
for c in input():
    if c == '(':
        L.append(0)
        stack.append(c)
    if c == ')':
        if L[-2] != -1:
            R.append(L.pop())
            L[-1] += 1
            cur += L[-1]
            stack.append('-')
        else:
            L.append(-1)
            L.append(0)
            stack.append(c)
    if c == '-':
        if stack[-1] == '(':
            L.pop()
        elif stack[-1] == ')':
            L.pop()
            L.pop()
        else:
            cur -= L[-1]
            L[-1] -= 1
            L.append(R.pop())
        stack.pop()
    print(cur)
stack1 = [0]
stack2 = []
string = input()
N = len(string)
for i in range(N):
    if string[i] == '(':
        continue
    elif string[i] == ')':
        x = stack1.pop()
        y = stack2.pop()
        stack1[-1] += x * y
    elif i + 1 < N and string[i + 1] == '(':
        stack1.append(0)
        stack2.append(int(string[i]))
    else:
        stack1[-1] += 1
print(stack1[0])
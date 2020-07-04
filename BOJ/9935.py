A = input()
B = input()
L = len(B)
stack = []
for a in A:
	stack.append(a)
	if ''.join(stack[-L:]) == B:
		for _ in range(L): stack.pop()
if stack: print(''.join(stack))
else: print("FRULA")

N = int(input())
WM = input()
stack = list(WM[::-1])
slot = []
diff = 0
ans = 0
while stack or slot:
    while stack and len(slot) < 2:
        slot.append(stack.pop())
    cur = ''
#    print(stack, diff, slot)
    if len(slot) == 1:
        cur = slot[0]
    else:
        x, y = slot
        if x == y:
            cur = x
        else:
            cur = 'WM'
    if cur == 'WM':
        if diff >= 0:
            diff -= 1
            slot = ['M']
        else:
            diff += 1
            slot = ['W']
    elif cur == 'W':
        if diff == -N:
            break
        else:
            diff -= 1
            slot.pop()
    else:
        if diff == N:
            break
        else:
            diff += 1
            slot.pop()
    ans += 1

print(ans)
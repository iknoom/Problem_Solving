val = {'+' : 1, '-' : 1, '*' : 2, '/' : 2}
arr = []
i, j = 0, 1

def cal(i):
    t = arr[i + 1]
    if t == '+': return arr[i] + arr[i + 2]
    if t == '-': return arr[i] - arr[i + 2]
    if t == '*': return arr[i] * arr[i + 2]
    else: return int(arr[i] / arr[i + 2])

state = input()


while True:
    if j >= len(state):
        arr.append(int(state[i: j]))
        break
    if state[j] in val:
        arr.append(int(state[i: j]))
        arr.append(state[j])
        j += 1
        i = j
    j += 1


i, j = 0, len(arr) - 1
LR = '-'

while i < j:
    L = cal(i)
    R = cal(j - 2)
    if val[arr[i + 1]] < val[arr[j - 1]]: LR = 'R'
    elif val[arr[i + 1]] > val[arr[j - 1]]: LR = 'L'
    elif L < R: LR = 'R'
    else: LR = 'L'

    if LR == 'L':
        arr[i + 2] = L
        i += 2
    else:
        arr[j - 2] = R
        j -= 2

print(arr[i])
def dfs(d):
    if d == 15:
        return True
    a, b = match[d]
    ret = False
    if abc[a][0] and abc[b][2]:
        abc[a][0] -= 1
        abc[b][2] -= 1
        if dfs(d + 1):
            ret = True
        abc[a][0] += 1
        abc[b][2] += 1
    if abc[a][1] and abc[b][1]:
        abc[a][1] -= 1
        abc[b][1] -= 1
        if dfs(d + 1):
            ret = True
        abc[a][1] += 1
        abc[b][1] += 1
    if abc[a][2] and abc[b][0]:
        abc[a][2] -= 1
        abc[b][0] -= 1
        if dfs(d + 1):
            ret = True
        abc[a][2] += 1
        abc[b][0] += 1
    return ret

def solution():
    for i in range(6):
        if sum(abc[i]) != 5:
            return 0
    if dfs(0):
        return 1
    else:
        return 0

if __name__ == '__main__':
    match = [(i, j) for i in range(5) for j in range(i + 1, 6)]
    answer = []
    for _ in range(4):
        arr = list(map(int, input().split()))
        abc = []
        for i in range(6):
            abc.append(arr[i * 3 : (i + 1) * 3])
        cur = solution()
        answer.append(cur)
    print(*answer)
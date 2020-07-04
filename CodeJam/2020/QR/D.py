T, B = map(int, input().split())
ans = [-1] * B

def get_bit(kth):
    print(kth, flush=True)
    a = int(input())
    return a

def complement():
    global ans, B
    for i in range(B):
        if ans[i] < 0: continue
        ans[i] ^= 1

def reverse():
    global ans
    ans = ans[::-1]

def effects(flag1, flag2):
    if flag1 and flag2: complement()
    elif flag1: complement(); reverse()
    elif flag2: reverse()
    else: pass

for case in range(1, T + 1):
    ans = [-1] * B
    index1 = -1  # same bits
    index2 = -1  # different bits
    cur = 0

    while True:
        query = 4
        flag1 = flag2 = False

        if index1 >= 0 and index2 >= 0:
            a = get_bit(index1 + 1)
            b = get_bit(index2 + 1)
            if a != ans[index1]: flag1 = True
            if b != ans[index2]: flag2 = True
        elif index1 >= 0:
            a = get_bit(index1 + 1)
            _ = get_bit(index1 + 1)
            if a != ans[index1]: flag1 = True
        elif index2 >= 0:
            a = get_bit(index2 + 1)
            _ = get_bit(index2 + 1)
            if a != ans[index2]: flag2 = True
        else:
            query += 1

        effects(flag1, flag2)

        for _ in range(query):
            a = get_bit(cur + 1)
            b = get_bit(B - cur)
            ans[cur] = a
            ans[B - cur - 1] = b
            if a == b: index1 = cur
            if a != b: index2 = cur
            cur += 1

        if cur >= B // 2: break

    print(''.join(map(str, ans)), flush=True)
    ok = input()

    if ok == 'Y':
        continue
    else:
        exit()




import sys
input = sys.stdin.readline

def is_valid(st):
    for i in range(65, 65 + 26):
        al = chr(i)
        arr = []
        for j in range(len(st)):
            if st[j] == al:
                arr.append(j)
        for j in range(len(arr) - 1):
            if arr[j + 1] - arr[j] > 1:
                return False
    return True


def solution():
    N = int(input())
    arr = input().split()
    for x in arr:
        if not is_valid(x):
            return "IMPOSSIBLE"
    answer = []
    tower = arr[0]
    rest = arr[1:]
    while len(rest) > 0:
        flag = False
        for r in rest:
            if r[0] != r[-1]:
                continue
            if r[0] == tower[-1]:
                tower = tower + r
                rest.remove(r)
                flag = True
                break
            if r[-1] == tower[0]:
                tower = r + tower
                rest.remove(r)
                flag = True
                break
        if flag:
            continue
        flag = False
        for r in rest:
            if r[0] == tower[-1]:
                tower = tower + r
                rest.remove(r)
                flag = True
                break
            if r[-1] == tower[0]:
                tower = r + tower
                rest.remove(r)
                flag = True
                break
        if not flag:
            answer.append(tower[:])
            tower = rest[0]
            rest.remove(tower)
        if not is_valid(tower):
            return "IMPOSSIBLE"
    answer.append(tower[:])
    for x in answer:
        if not is_valid(x):
            return "IMPOSSIBLE"
    ret = ''.join(answer)
    if not is_valid(ret):
        return "IMPOSSIBLE"
    return ret


if __name__ == '__main__':
    T = int(input())
    for case in range(1, T + 1):
        print("Case #"+str(case) + ":", solution())
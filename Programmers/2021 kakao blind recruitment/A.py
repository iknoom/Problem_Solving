def is_valid(c):
    if ord('a') <= ord(c) <= ord('z'): return True
    if ord('0') <= ord(c) <= ord('9'): return True
    if c in {'-', '_', '.'}: return True
    return False

def solution(new_id):
    answer = []
    # 1
    new_id = new_id.lower()
    # 2
    for c in new_id:
        if is_valid(c):
            answer.append(c)
    # 3, 4, 5
    nxt = []
    for i in range(len(answer)):
        if i == len(answer) - 1: nxt.append(answer[i])
        elif answer[i] == answer[i + 1] == '.': continue
        else: nxt.append(answer[i])

    if nxt and nxt[0] == '.': nxt = nxt[1:]
    if nxt and nxt[-1] == '.': nxt.pop()

    if not nxt: answer = ['a']
    else: answer = nxt

    # 6
    if len(answer) >= 16:
        answer = answer[:15]
        if answer[-1] == '.':
            answer.pop()

    # 7
    elif len(answer) <= 2:
        while len(answer) != 3:
            answer.append(answer[-1])

    return ''.join(answer)

if __name__ == "__main__":
    print(solution(".........!@BaT#*........y.abcdefghijklm............"))
    print(solution("abcdefghijklmn.p"))
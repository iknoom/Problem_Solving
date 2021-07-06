def solution(bitset, state):
    l_cnt = 0
    ret = []
    stack = []
    for c in state:
        if c == '(':
            if not bitset & (1 << l_cnt):
                ret.append(c)
            stack.append(l_cnt)
            l_cnt += 1
        elif c == ')':
            r_cnt = stack.pop()
            if not bitset & (1 << r_cnt):
                ret.append(c)
        else:
            ret.append(c)
    return ''.join(ret)

if __name__ == '__main__':
    state = input()
    l = 0
    for c in state:
        if c == '(':
            l += 1
    answer = {solution(i, state) for i in range(1, (1 << l))}
    print(*sorted(answer), sep='\n')
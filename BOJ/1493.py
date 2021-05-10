def fit_box(l, w, h):
    if not l * w * h:
        return 0
    for i in range(19, -1, -1):
        length = 2 ** i
        n = (l//length) * (w//length) * (h//length)
        if n > 0:
            cube[i] -= n
            ret = n
            ret += fit_box(l % length, w - w % length, h - h % length)
            ret += fit_box(l - l % length, w % length, h - h % length)
            ret += fit_box(l % length, w % length, h - h % length)
            ret += fit_box(l, w, h % length)
            return ret


if __name__ == '__main__':
    L, W, H = map(int,input().split())
    cube = [0] * 20
    for _ in range(int(input())):
        a, b = map(int,input().split())
        cube[a] = b

    answer = fit_box(L, W, H)
    for i in range(19, 0, -1):
        # i번째 큐브 -> i - 1번째 큐브
        if cube[i] < 0:
            answer -= 7 * cube[i]
            cube[i - 1] += 8 * cube[i]

    if cube[0] < 0:
        print(-1)
    else:
        print(answer)
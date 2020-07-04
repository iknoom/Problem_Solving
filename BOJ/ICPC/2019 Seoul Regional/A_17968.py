def make_arr():
    ret = [0] * 1001
    ret[0] = ret[1] = 1
    for i in range(2, 1001):
        p = set(range(1, 100))
        for k in range(1, i // 2 + 1):
            x = 2 * ret[i - k] - ret[i - 2 * k]
            p.discard(x)
        ret[i] = min(p)
    return ret

if __name__ == "__main__":
    arr = make_arr()
    idx = int(input())
    print(arr[idx])
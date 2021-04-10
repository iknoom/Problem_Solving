def get_median(a, b, c):
    print(a, b, c, flush=True)
    mid = int(input())
    return mid

def init_to3():
    mid = get_median(1, 2, 3)
    arr = [1, 2, 3]
    arr.remove(mid)
    arr.insert(1, mid)
    return arr

def solution():
    arr = init_to3()
    for x in range(4, N + 1):
        l = arr[0]
        r = arr[-1]
        mid = get_median(l, r, x)
        if mid == l:
            arr.insert(0, x)
        elif mid == r:
            arr.append(x)
        else:
            l_idx = 0
            r_idx = len(arr) - 1
            while l_idx + 1 < r_idx:
                mid_idx = (l_idx + r_idx) // 2
                mid = get_median(arr[mid_idx], arr[r_idx], x)
                if mid == x:
                    l_idx = mid_idx
                else:
                    r_idx = mid_idx
            arr.insert(r_idx, x)
    print(*arr, flush=True)
    _ = input()

if __name__ == '__main__':
    T, N, Q = map(int, input().split())
    for _ in range(T):
        solution()
def query(arr, kth):
    print('?', arr, kth, flush=True)
    res = int(input())
    return res

if __name__ == "__main__":
    # input
    N = int(input())

    # solution
    la, ra = 1, N
    lb, rb = 1, N
    va, vb = -1, -1
    while la < ra:
        ma = (la + ra) // 2
        va = query('A', ma)
        mb = (lb + rb) // 2
        vb = query('B', mb)
        if va <= vb:
            la = ma + 1
            rb = mb
        else:
            lb = mb + 1
            ra = ma
    va = query('A', la)
    vb = query('B', lb)
    if va < vb:
        print('!', va, flush=True)
    else:
        print('!', vb, flush=True)
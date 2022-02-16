def query(i):
    print('?', i, flush=True)
    ret = int(input())
    return ret

def solution():
    N = int(input())
    answer = [-1] * (N + 1)
    count = 0
    for i in range(1, N + 1):
        if answer[i] >= 0:
            continue
        # get sub permutation
        sub_perm = [query(i)]
        while True:
            x = query(i)
            count += 1
            if x == sub_perm[0]:
                break
            sub_perm.append(x)
        # fill answer
        L = len(sub_perm)
        idx = count % L
        for j in range(L):
            l = sub_perm[(j + idx) % L]
            r = sub_perm[(j + idx + 1) % L]
            answer[l] = r
    print('!', *answer[1:])

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()
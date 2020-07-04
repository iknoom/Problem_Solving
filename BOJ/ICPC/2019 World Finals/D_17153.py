def first_sweep():
    first_cnt = {}
    min_cnt = {}
    for DNA in DNAs:
        key = int(DNA[1:])
        if key not in first_cnt:
            first_cnt[key] = 0
        if key not in min_cnt:
            min_cnt[key] = float('inf')
        if DNA[0] == 's':
            first_cnt[key] += 1
        else:
            first_cnt[key] -= 1
        min_cnt[key] = min(min_cnt[key], first_cnt[key])
    return first_cnt, min_cnt

def second_sweep(total_min):
    second_cnt = {}
    ans_max = total_min
    indice = []

    for i in range(N):
        key = int(DNAs[i][1:])
        if key not in second_cnt:
            second_cnt[key] = 0
        if first_cnt[key] != 0:
            pass
        elif DNAs[i][0] == 's':
            if min_cnt[key] == second_cnt[key]: total_min -= 1
            second_cnt[key] += 1
        else:
            second_cnt[key] -= 1
            if min_cnt[key] == second_cnt[key]: total_min += 1
        if total_min > ans_max:
            ans_max = total_min
            indice = [(i + 1) % N]
        elif total_min == ans_max:
            indice.append((i + 1) % N)
    return min(indice) + 1, ans_max

if __name__ == "__main__":
    N = int(input())
    DNAs = input().split()
    first_cnt, min_cnt = first_sweep()

    total_min = 0
    for k in min_cnt:
        if first_cnt[k] == 0 and min_cnt[k] == 0:
            total_min += 1

    ans_idx, ans_max = second_sweep(total_min)
    if ans_idx:
        print(ans_idx, ans_max)
    else:
        print(1, 0)
import sys

input = sys.stdin.readline

INF = float('inf')

def solution():
    n = int(input())
    seg = [tuple(map(int, input().split())) for _ in range(n)]

    l_min = INF
    l_min_cost = INF
    r_max = -INF
    r_min_cost = INF

    lr_dic = {}

    for i in range(n):
        l, r, c = seg[i]
        if l < l_min:
            l_min = l
            l_min_cost = c
        elif l == l_min:
            if c < l_min_cost:
                l_min_cost = c
        if r_max < r:
            r_max = r
            r_min_cost = c
        elif r == r_max:
            if c < r_min_cost:
                r_min_cost = c
        if (l, r) in lr_dic:
            lr_dic[(l, r)] = min(lr_dic[(l, r)], c)
        else:
            lr_dic[(l, r)] = c
        if (l_min, r_max) in lr_dic:
            print(min(lr_dic[(l_min, r_max)], l_min_cost + r_min_cost))
        else:
            print(l_min_cost + r_min_cost)




if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()
from sys import stdin
input = stdin.readline

def can_pass(caves, power, sweep):
    for _, i in sweep:
        for a in caves[i]:
            if a >= power:
                return False
            power += 1
    return True


def solution():
    n = int(input())
    caves = [list(map(int, input().split()))[1:] for _ in range(n)]
    sweep = []
    for i in range(n):
        cave = caves[i]
        cur = 0
        for j in range(len(cave)):
            cur = max(cur, cave[j] + 1 - j)
        sweep.append((cur, i))
    sweep.sort()
    l = 0
    r = 2000000000
    while l + 1 < r:
        mid = (l + r) // 2
        if can_pass(caves, mid, sweep):
            r = mid
        else:
            l = mid
    print(r)


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()
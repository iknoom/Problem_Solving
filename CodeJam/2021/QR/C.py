from sys import stdin
input = stdin.readline

def solution():
    N, C = map(int, input().split())
    if C < N - 1:
        print("IMPOSSIBLE")
        return
    if N * (N + 1) // 2 - 1 < C:
        print("IMPOSSIBLE")
        return
    C -= N - 1
    answer = [0] * N
    l = 0
    r = N - 1
    toggle = 0
    for i in range(1, N + 1):
        diff = N - i
        if diff > C:
            if toggle:
                answer[r] = i
                r -= 1
            else:
                answer[l] = i
                l += 1
            continue
        C -= diff
        if toggle:
            answer[l] = i
            l += 1
            toggle ^= 1
        else:
            answer[r] = i
            r -= 1
            toggle ^= 1
    print(*answer)

if __name__ == '__main__':
    T = int(input())
    for case in range(1, T + 1):
        print("Case #"+str(case) + ": ", end='')
        solution()
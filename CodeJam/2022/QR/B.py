import sys
input = sys.stdin.readline

def solution():
    arr = [tuple(map(int, input().split())) for _ in range(3)]
    c = min(arr[i][0] for i in range(3))
    m = min(arr[i][1] for i in range(3))
    y = min(arr[i][2] for i in range(3))
    k = min(arr[i][3] for i in range(3))
    if c + m + y + k < 1000000:
        return "IMPOSSIBLE"
    else:
        r = 1000000
        answer = [c, m, y, k]
        for i in range(4):
            answer[i] = min(r, answer[i])
            r = max(0, r - answer[i])
        return ' '.join(map(str, answer))


if __name__ == '__main__':
    T = int(input())
    for case in range(1, T + 1):
        print("Case #"+str(case) + ":", solution())
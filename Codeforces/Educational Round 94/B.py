import sys
input = sys.stdin.readline


def solution():
    p, f = map(int, input().split())
    cnt_s, cnt_w = map(int, input().split())
    s, w = map(int, input().split())
    if s > w:
        s, w = w, s
        cnt_s, cnt_w = cnt_w, cnt_s

    ans = 0

    for i in range(cnt_s + 1):
        j = cnt_s - i
        if i * s > p: break

        p_s = i
        f_s = min(j, f // s)
        p0 = p - p_s * s
        f0 = f - f_s * s

        ret = min(cnt_w, p0 // w + f0 // w) + p_s + f_s
        ans = max(ans, ret)

    print(ans)



if __name__ == "__main__":
     T = int(input())
     for _ in range(T):
         solution()
import sys

input = sys.stdin.readline

def solution():
    l, r = map(int, input().split())

    a = list(map(int, input().split()))
    b = [i for i in range(l, r + 1)]
    bits1 = [0] * 18
    bits2 = [0] * 18
    for c in a:
        for i in range(18):
            if c & (1 << i):
                bits1[i] += 1
    for c in b:
        for i in range(18):
            if c & (1 << i):
                bits2[i] += 1
    ans = 0
    for i in range(18):
        if bits1[i] != bits2[i]:
            ans += (1 << i)
    print(ans)


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()
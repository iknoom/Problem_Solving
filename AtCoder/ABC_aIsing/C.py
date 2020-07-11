import sys
input = sys.stdin.readline


N = int(input())

ans = [0] * 10001

for x in range(1, 101):
    for y in range(1, 101):
        for z in range(1, 101):
            ret = x * x + y * y + z * z + x * y + y * z + z * x
            if ret < 10001:
                ans[ret] += 1

for i in range(1, N + 1):
    print(ans[i])
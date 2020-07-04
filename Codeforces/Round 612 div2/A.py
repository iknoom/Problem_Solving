import sys
input = sys.stdin.readline

for _ in range(int(input())):
    N = int(input())
    T = input().rstrip()
    cnt = 0
    ans = 0
    flag = False
    for t in T:
        if t == 'A':
            flag = True
        if not flag:
            continue
        if t == 'P':
            cnt += 1
        if t == 'A':
            ans = max(ans , cnt)
            cnt = 0
    ans = max(ans, cnt)
    print(ans)
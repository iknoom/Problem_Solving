from sys import stdin
input = stdin.readline

def solution(N):
    S = 0
    count = 1
    while True:
        S += count
        count += 1
        if (N - S) < count:
            print("IMPOSSIBLE")
            return
        if (N - S) % count == 0:
            a = (N - S) // count
            ans = [str(N), '=']
            for i in range(count):
                ans.append(str(a + i))
                ans.append('+')
            print(*ans[:-1])
            return

T = int(input())
for _ in range(T):
    N = int(input())
    solution(N)
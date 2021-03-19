from sys import stdin
input = stdin.readline

def ru(n, c):
    rsum = 0
    usum = 0
    rcnt = 0
    ucnt = 0
    rmin = float('inf')
    umin = float('inf')
    answer = float('inf')
    for i in range(n):
        if i % 2 == 0:
            rsum += c[i]
            rcnt += 1
            rmin = min(rmin, c[i])
        else:
            usum += c[i]
            ucnt += 1
            umin = min(umin, c[i])
        if i > 0:
            ret = 0
            ret += rmin * (n - (rcnt - 1))
            ret += umin * (n - (ucnt - 1))
            answer = min(answer, ret + rsum + usum - rmin - umin)
    return answer


def solution():
    n = int(input())
    c = list(map(int, input().split()))
    print(ru(n, c))

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()

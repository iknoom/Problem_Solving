import sys
input = sys.stdin.readline

def solution():
    N = int(input())
    S = list(map(int, input().split()))
    S.sort()
    answer = 0
    for c in S:
        if c > answer:
            answer += 1
    return answer


if __name__ == '__main__':
    T = int(input())
    for case in range(1, T + 1):
        print("Case #"+str(case) + ":", solution())
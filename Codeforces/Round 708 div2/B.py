from sys import stdin
input = stdin.readline

def solution():
    N, M = map(int, input().split())
    A = list(map(int, input().split()))
    R_list = [0] * M
    for a in A:
        R_list[a % M] += 1

    answer = 0
    # zero
    if R_list[0]:
        answer += 1

    # even
    if M % 2 == 0:
        for i in range(1, M // 2):
            a, b = R_list[i], R_list[M - i]
            if a > b:
                a, b = b, a
            if not a:
                answer += b
                continue
            if a + 1 >= b:
                answer += 1
            else:
                answer += 1
                answer += b - (a + 1)
        if R_list[M // 2]:
            answer += 1
    # odd
    else:
        for i in range(1, M // 2 + 1):
            a, b = R_list[i], R_list[M - i]
            if a > b:
                a, b = b, a
            if not a:
                answer += b
                continue
            if a + 1 >= b:
                answer += 1
            else:
                answer += 1
                answer += b - (a + 1)
    print(answer)

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()
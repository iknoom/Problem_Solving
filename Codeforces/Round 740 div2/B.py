from sys import stdin
input = stdin.readline


def sub_solution(a, b, a_win, b_win):
    ret = set()
    serve_a = a
    serve_b = b
    break_a = 0
    break_b = 0
    while serve_a > a_win:
        serve_a -= 1
        break_b += 1
    while serve_b > b_win:
        serve_b -= 1
        break_a += 1

    all_break = break_a + break_b
    ret.add(all_break)
    C = min(serve_a, serve_b)
    for i in range(1, C + 1):
        ret.add(all_break + i * 2)
    return ret

def solution():
    a, b = map(int, input().split())
    n = a + b
    answer = set()
    answer |= sub_solution(n//2, n - n//2, a, b)
    answer |= sub_solution(n - n//2, n//2, a, b)
    print(len(answer))
    print(*sorted(answer))


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()
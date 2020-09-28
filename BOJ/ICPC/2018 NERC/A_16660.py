from sys import stdin
input = stdin.readline

def make_match(A_win, B_win, a_score, b_score):
    N = A_win + B_win
    A = [0] * N
    B = [0] * N

    # fill score to win (25 or 15)
    a_score -= 25 * A_win
    b_score -= 25 * B_win
    for i in range(A_win):
        A[-i - 1] += 25
    for i in range(B_win):
        B[i] += 25
    if N == 5:
        if A_win > B_win:
            A[-1] -= 10
            a_score += 10
        else:
            B[0] -= 10
            b_score += 10

    # if (a < 0 or b < 0) -> it's impossible
    if a_score < 0 or b_score < 0:
        return ""

    # draw until (a == 0 or b == 0)
    if (B_win > 0 and a_score >= B[0] - 2) and (A_win > 0 and b_score >= A[-1] - 2):
        if a_score > b_score:
            A[0] += B[0] - 2
            a_score -= B[0] - 2
            while a_score > 0 and b_score > 0:
                A[0] += 1
                B[0] += 1
                a_score -= 1
                b_score -= 1
        else:
            B[-1] += A[-1] - 2
            b_score -= A[-1] - 2
            while a_score > 0 and b_score > 0:
                A[-1] += 1
                B[-1] += 1
                a_score -= 1
                b_score -= 1
    elif B_win > 0 and a_score >= B[0] - 2:
        A[0] += B[0] - 2
        a_score -= B[0] - 2
        while a_score > 0 and b_score > 0:
            A[0] += 1
            B[0] += 1
            a_score -= 1
            b_score -= 1
    elif A_win > 0 and b_score >= A[-1] - 2:
        B[-1] += A[-1] - 2
        b_score -= A[-1] - 2
        while a_score > 0 and b_score > 0:
            A[-1] += 1
            B[-1] += 1
            a_score -= 1
            b_score -= 1

    # finally fill score to lose (23 or 15)
    for i in range(B_win):
        diff = B[i] - A[i] - 2
        A[i] += min(a_score, diff)
        a_score -= min(a_score, diff)
    for i in range(A_win):
        diff = A[-i - 1] - B[-i - 1] - 2
        B[-i - 1] += min(b_score, diff)
        b_score -= min(b_score, diff)

    # if (a > 0 or b > 0) -> it's impossible
    if a_score > 0 or b_score > 0:
        return ""

    if A_win > B_win:
        return ' '.join(f'{x}:{y}' for x, y in zip(A, B))
    else:
        return ' '.join(f'{x}:{y}' for x, y in zip(A[::-1], B[::-1]))

def solution(a, b):
    # (l, r, string)
    result = []
    for l in range(4):
        for r in range(4):
            if l == r: continue
            if l != 3 and r != 3: continue
            match = make_match(l, r, a, b)
            if match:
                result.append((l, r, match))
    if not result:
        print("Impossible")
        return
    result.sort(key=lambda x: x[0] - x[1])
    x, y, match = result[-1]
    print(f'{x}:{y}')
    print(match)

if __name__ == "__main__":
    m = int(input())
    for _ in range(m):
        a, b = map(int, input().split())
        solution(a, b)
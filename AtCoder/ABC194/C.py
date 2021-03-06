from sys import stdin
input = stdin.readline

if __name__ == '__main__':
    N = int(input())
    A = list(map(int, input().split()))
    A_2 = [a * a for a in A]
    S = A[0]
    S_2 = A_2[0]
    answer = 0
    for i in range(1, N):
        answer += A_2[i] * i
        answer += S_2
        answer -= 2 * A[i] * S
        S += A[i]
        S_2 += A_2[i]
    print(answer)
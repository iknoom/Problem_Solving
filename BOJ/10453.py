from sys import stdin
input = stdin.readline


def solution(A, B):
    Aa = []
    Ba = []
    for i in range(len(A)):
        if A[i] == 'a':
            Aa.append(i)
        if B[i] == 'a':
            Ba.append(i)
    if len(Aa) != len(Ba):
        return -1
    return sum(abs(Aa[i] - Ba[i]) for i in range(len(Aa)))

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        A, B = input().split()
        answer = solution(A, B)
        print(answer)

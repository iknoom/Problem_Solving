
if __name__ == '__main__':
    # input
    N = int(input())
    A = list(map(int, input().split()))
    X = int(input())

    # solution
    A.sort()
    answer = 0
    j = N - 1
    for i in range(N):
        while i < j and A[i] + A[j] > X:
            j -= 1
        if i == j:
            break
        if A[i] + A[j] == X:
            answer += 1
    print(answer)
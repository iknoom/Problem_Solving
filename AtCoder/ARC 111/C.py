from sys import stdin

input = stdin.readline

if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    P = list(map(int, input().split()))
    A_to = [-1] * N
    B_to = [-1] * N
    for i in range(N):
        j = P[i] - 1
        A_to[i] = j
        B_to[j] = i


    sweep = [(A[i], i) for i in range(N)]
    sweep.sort()

    ans = []
    flag = True

    for _, i in sweep:
        j = A_to[i]
        if i == j:
            continue
        if A[i] <= B[j]:
            flag = False
            break
        ans.append((i + 1, B_to[i] + 1))
        k = B_to[i]
        A_to[k] = A_to[i]
        B_to[j] = k
        B_to[i] = i
        A_to[i] = i
    if flag:
        print(len(ans))
        for a, b in ans:
            print(a, b)
    else:
        print(-1)
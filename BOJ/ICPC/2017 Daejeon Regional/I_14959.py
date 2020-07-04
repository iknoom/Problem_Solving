def solve(arr, N):
    k = N - 1
    p = 1
    j = 0
    fail = [0] * N
    for i in range(1, N):
        while j > 0 and arr[i] != arr[j]: j = fail[j - 1]
        if arr[i] == arr[j]: j += 1; fail[i] = j
        if (k + p) > (N - fail[i]):
            k, p = N - 1 - i, i - fail[i] + 1
    return k, p

if __name__ == "__main__":
    N = int(input())
    arr = list(map(int, input().split()))[::-1]
    ans_k, ans_p = solve(arr, N)
    print(ans_k, ans_p)
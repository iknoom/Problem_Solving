def sol(N, arr):
    answer = float('inf')
    j = N - 1
    for i in range(N):
        while i < j and arr[i] + arr[j] >= 0:
            if abs(answer) > abs(arr[i] + arr[j]):
                answer = arr[i] + arr[j]
            j -= 1
        if i >= j: break
        if abs(answer) > abs(arr[i] + arr[j]):
            answer = arr[i] + arr[j]
    return answer

if __name__ == '__main__':
    N = int(input())
    arr = list(map(int, input().split()))
    print(sol(N, arr))
def sol(arr, depth):
    if len(arr) == 1:
        answer[depth].append(arr[0])
        return
    mid = len(arr) // 2
    answer[depth].append(arr[mid])
    sol(arr[:mid], depth + 1)
    sol(arr[mid + 1:], depth + 1)


if __name__ == '__main__':
    K = int(input())
    arr = list(map(int, input().split()))
    answer = [[] for _ in range(K)]
    sol(arr, 0)
    for i in range(K):
        print(*answer[i])
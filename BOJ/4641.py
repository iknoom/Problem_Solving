while True:
    arr = list(map(int, input().split()))
    if arr[0] == -1:
        break
    answer = 0
    for a in arr[:-1]:
        if a * 2 in arr:
            answer += 1
    print(answer)
all_str = input()
for i in range(1, 1000):
    arr = ""
    cnt = i
    while len(arr) < len(all_str):
        arr += str(cnt)
        cnt += 1
    if arr == all_str:
        print(i, cnt - 1)
        break
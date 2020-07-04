def solve(arr):
    if sum(arr) != N * (N - 1) // 2: return False
    mi = 0
    mx = N - 1

    for x in arr:
        if x < mi:
            return False
        elif x == mi:
            mi += 1
        else:
            break

    for y in reversed(arr):
        if y > mx:
            return False
        elif y == mx:
            mx -= 1
        else:
            break
    return True

if __name__ == "__main__":
    N = int(input())
    arr = sorted(map(int, input().split()))
    answer = solve(arr)
    print(1 if answer else -1)
from sys import stdin
input = stdin.readline

def solution():
    k = int(input())
    arr = list(map(int, input().rstrip()))
    nums = set(arr)
    for x in [1, 4, 6, 8, 9]:
        if x in nums:
            print(1)
            print(x)
            return

    for i in range(k - 1):
        for j in range(i + 1, k):
            if arr[j] == 2:
                print(2)
                print(str(arr[i]) + str(arr[j]))
                return
            if arr[i] == 3 and arr[j] == 5:
                print(2)
                print(35)
                return
            if arr[i] == 5 and arr[j] == 7:
                print(2)
                print(57)
                return
            if arr[i] == 7 and arr[j] == 5:
                print(2)
                print(75)
                return
            if arr[i] == 2 and arr[j] == 7:
                print(2)
                print(27)
                return
            if arr[i] == 2 and arr[j] == 5:
                print(2)
                print(25)
                return
            if arr[i] == arr[j]:
                print(2)
                print(arr[i] * 11)
                return

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()
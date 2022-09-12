def solution(n):
    for r in range(2, 1000000):
        arr = [1, r]
        cur = r
        b = 1 + r
        for _ in range(40):
            cur *= r
            arr.append(cur)
            b += cur
            if b > n:
                break
            if n % b == 0:
                a = n // b
                for i in range(len(arr)):
                    arr[i] *= a
                print(len(arr))
                print(*arr)
                return
    print(-1)

N = int(input())
solution(N)
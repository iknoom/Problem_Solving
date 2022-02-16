import sys

input = sys.stdin.readline


def solution():
    n = int(input())
    A = sorted(set(map(int, input().split())))

    count = [0, 0, 0]
    for k in A[:-1]:
        count[k % 3] += 1

    a = A[-1] // 3
    b = A[-1] % 3
    answer = a + int(b != 0)

    # ok
    if count[1] == 0 and count[2] == 0:
        print(answer)
        return
    # ok
    if b == 0:
        print(answer + 1)
        return
    # ok
    if b == 2:
        if count[1] == 0:
            print(answer)
            return
        else:
            print(answer + 1)
            return

    if b == 1:
        # 1
        if count[2] == 0:
            print(answer)
            return
        # 1 2
        if count[1] > 0:
            if len(A) > 1 and A[-1] - A[-2] == 1:
                print(answer + 1)
                return
            if 1 in A:
                print(answer + 1)
                return
            else:
                print(answer)
                return
        # 2
        if len(A) > 1 and A[-1] - A[-2] == 1:
            print(answer + 1)
            return
        else:
            print(answer)
            return


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()
from sys import stdin
input = stdin.readline

inv = {
    1: 3,
    3: 1,
    2: 4,
    4: 2
}

def is_same(A, B):
    for i in range(len(A)):
        if A[i] != B[i]:
            return False
    return True

if __name__ == '__main__':
    N = int(input())
    arr = list(map(int, input().split()))
    inv_arr = list(map(lambda x:inv[x], arr))
    inv_arr.reverse()

    answer = []
    Q = int(input())
    for _ in range(Q):
        sample = list(map(int, input().split()))
        flag = False
        for i in range(N):
            rotated_sample = sample[i:] + sample[:i]
            if is_same(arr, rotated_sample) or is_same(inv_arr, rotated_sample):
                flag = True
        if flag:
            answer.append(sample)
    print(len(answer))
    for sample in answer:
        print(*sample)
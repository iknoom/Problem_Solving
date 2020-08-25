import sys
input = sys.stdin.readline


def solution():
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0

    cnt_L = [0] * (n + 1)
    for j in range(1, n - 2):
        # insert a[j -1] to L
        cnt_L[a[j - 1]] += 1

        current_sum = 0
        cnt_R = [0] * (n + 1)
        for l in range(j + 2, n):
            # insert a[l - 1] to R
            current_sum -= cnt_L[a[l - 1]] * cnt_R[a[l - 1]]
            cnt_R[a[l - 1]] += 1
            current_sum += cnt_L[a[l - 1]] * cnt_R[a[l - 1]]
            # print(j, l)
            # print(cnt_L)
            # print(cnt_R)
            # print()
            if a[j] == a[l]:
                # add to ans
                ans += current_sum
    print(ans)

if __name__ == "__main__":
     T = int(input())
     for _ in range(T):
         solution()
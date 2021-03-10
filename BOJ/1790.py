# 1자리 : 1 ~ 9 = 9개 * 1
# 2자리 : 10 ~ 99 = 90개 * 2
# 3자리 : 100 ~ 999 = 900개 * 3
# ...
# i자리 : (i - 1) ** 10개 * i * 9

# def sol(N, k):
#     s = ''
#     for i in range(1, N + 1):
#         s = s + str(i)
#     if len(s) < k:
#         return -1
#     return int(s[k - 1])

def my_sol(N, k):
    curNum = 1
    curLength = 1
    # 현재 숫자가 몇자리 숫자인지 판별
    while True:
        S = curNum * 9 * curLength
        if k <= S:
            break
        k -= S
        curNum *= 10
        curLength += 1
    # i자리 숫자 중에서 몇번째 숫자인지 판별
    diff = k // curLength
    curNum += diff
    k -= diff * curLength
    if k == 0:
        curNum -= 1
        if curNum > N:
            return -1
        return curNum % 10
    else:
        if curNum > N:
            return -1
        return int(str(curNum)[k - 1])

if __name__ == '__main__':
    N, k = map(int, input().split())
    print(my_sol(N, k))
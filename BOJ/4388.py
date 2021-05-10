while True:
    A, B = map(int, input().split())
    if A + B == 0:
        break

    answer = 0
    carry = 0
    a = str(A)[::-1]
    b = str(B)[::-1]
    for i in range(max(len(a), len(b))):
        S = carry
        if i < len(a):
            S += int(a[i])
        if i < len(b):
            S += int(b[i])
        if S >= 10:
            carry = 1
            answer += 1
        else:
            carry = 0
    print(answer)
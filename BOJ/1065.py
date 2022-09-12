def is_hansu(n):
    digits = []
    while n > 0:
        digits.append(n % 10)
        n //= 10
    digits_diff = []
    for i in range(len(digits) - 1):
        digits_diff.append(digits[i + 1] - digits[i])
    for i in range(len(digits_diff) - 1):
        if digits_diff[i + 1] != digits_diff[i]:
            return False
    return True


N = int(input())
answer = 0
for i in range(1, N + 1):
    if is_hansu(i):
        answer += 1
print(answer)
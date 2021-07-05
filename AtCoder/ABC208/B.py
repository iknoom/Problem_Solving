P = int(input())

fac = []
S = 1
for i in range(1, 100):
    S *= i
    if S > P:
        break
    fac.append(S)

answer = 0
for c in fac[::-1]:
    answer += P // c
    P %= c
print(answer)
N = int(input())
answer = []
while N:
    answer.append(N % 2)
    N //= 2
answer.reverse()
print(''.join(map(str, answer)))
K = int(input())
S = input()
answer = []
for i in range(0, len(S), K):
    answer.append(S[i])
print(''.join(answer))
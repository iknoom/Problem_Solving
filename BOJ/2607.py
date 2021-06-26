from collections import Counter

def is_similar(a, b):
    C1 = Counter(list(a))
    C2 = Counter(list(b))
    if sum((C1 - (C1 & C2)).values()) > 1:
        return False
    if sum((C2 - (C1 & C2)).values()) > 1:
        return False
    return True


N = int(input())
words = [input() for _ in range(N)]
answer = 0
for i in range(1, N):
    A = words[0]
    B = words[i]
    if is_similar(A, B):
        answer += 1
print(answer)
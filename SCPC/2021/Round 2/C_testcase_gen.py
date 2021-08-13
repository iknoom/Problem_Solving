import random
import sys
sys.stdout = open("sample7.txt", 'w')

N = 50
K = [1, 2, 3, 25, 26, 45, 47, 48, 49, 50]

print(len(K))
for k in K:
    print(N, k)
    for _ in range(N):
        arr = [random.randint(1, 1) for _ in range(N)]
        print(*arr)

sys.stdout.close()
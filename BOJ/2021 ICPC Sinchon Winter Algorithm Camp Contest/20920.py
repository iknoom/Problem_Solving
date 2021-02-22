from collections import Counter
from sys import stdin
input = stdin.readline

if __name__ == "__main__":
    N, M = map(int, input().split())
    dic = Counter()
    for _ in range(N):
        word = input().rstrip()
        if len(word) >= M:
            dic[word] += 1
    answer = list(dic.keys())
    answer.sort(key=lambda word : (-dic[word], -len(word), word))
    print(*answer, sep='\n')
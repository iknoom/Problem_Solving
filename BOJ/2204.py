from sys import stdin
input = stdin.readline

while True:
    N = int(input())
    if N == 0:
        break
    words = []
    for i in range(N):
        word = input().rstrip()
        words.append((word, word.lower()))
    words.sort(key=lambda x: x[1])
    print(words[0][0])

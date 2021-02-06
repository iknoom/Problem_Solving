from sys import stdin
input = stdin.readline

N_str, S = input().split()
N = int(N_str)
chat = [input().split() for _ in range(N)]
cnt = 0
flag = False
answer = ""
for i in range(N):
    p, t = chat[-i - 1]
    if flag and t == answer:
        cnt += 1
    if p == S:
        flag = True
        answer = t

print(cnt)
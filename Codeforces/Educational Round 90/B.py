import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    S = input().rstrip()
    zero = 0
    one = 0
    for i in range(len(S)):
        if S[i] == '0':
            zero += 1
        else:
            one += 1
    X = min(zero, one)
    if X & 1:
        print("DA")
    else:
        print("NET")
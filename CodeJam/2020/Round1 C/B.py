import sys
# input = sys.stdin.readline
f = open("sample.in.txt")
input = f.readline

T = int(input())

for case in range(1, T + 1):
    U = int(input())
    query = set()
    ans = [''] * 10
    for _ in range(10000):
        Mi, Ri = input().split()
        query.add((int(Mi), Ri))

    S = set()
    for M, R in sorted(query):
        print(M, R)

    print("Case #" + str(case) + ": " + ''.join(ans))
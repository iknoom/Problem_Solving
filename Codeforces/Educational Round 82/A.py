import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    X = input().rstrip()
    if '1' not in X:
        print(0)
    else:
        print(len(X) - X[::-1].find('1') - X.find('1') - X.count('1'))
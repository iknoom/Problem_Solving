import sys
input = sys.stdin.readline

X = int(input())

if X < 600:
    print(8)
elif X < 800:
    print(7)
elif X < 1000:
    print(6)
elif X < 1200:
    print(5)
elif X < 1400:
    print(4)
elif X < 1600:
    print(3)
elif X < 1800:
    print(2)
else:
    print(1)
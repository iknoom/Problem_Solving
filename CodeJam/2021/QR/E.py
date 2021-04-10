from sys import stdin
from decimal import *
input = stdin.readline

def inv_nomal(y):
    l = Decimal(0.11503128)
    r = Decimal(0.88489739)
    return (Decimal(y) - r) * Decimal(6) / (r - l) + Decimal(3)

def inv_cheat(y):
    l = Decimal(0.9424373)
    r = Decimal(0.55753072)
    return (Decimal(y) - r) * Decimal(6) / (r - l) + Decimal(3)

def solution():
    y = []
    for i in range(100):
        y.append(sum(x == '1' for x in input().rstrip())/10000)
    ret = []
    for i in range(100):
        S = Decimal(0)
        for j in range(100):
            if i == j: S += inv_cheat(y[j])
            else: S += inv_nomal(y[j])
        if S < 0:
            ret.append((-S, i + 1))
        else:
            ret.append((abs(S), i + 1))
    return min(ret)[1]

if __name__ == '__main__':
    T = int(input())
    P = int(input())
    for case in range(1, T + 1):
        answer = solution()
        print("Case #"+str(case) + ":", answer)
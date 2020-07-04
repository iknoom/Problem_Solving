import sys
from collections import Counter
input = sys.stdin.readline

T = int(input())

def case1():
    for a in A:
        if Cnt[a] == 2 and a != max_A: return True
    return False

def case2():
    for a in A:
        if a * 2 in set_A:
            return True
    return False


for case in range(1, T + 1):
    N, D = map(int, input().split())
    A = list(map(int, input().split()))
    set_A = set(A)
    A.sort()
    Cnt = Counter(A)
    max_A = max(A)
    ans = -1
    if D == 2:
        if N == 1: ans = 1
        else:
            max_cnt = max(Cnt.values())
            if max_cnt > 1: ans = 0
            else: ans = 1
    elif D == 3:
        if N == 1: ans = 2
        elif N == 2:
            if A[0] * 2 == A[1]: ans = 1
            else: ans = 2
        else:
            max_cnt = max(Cnt.values())
            if max_cnt > 2: ans = 0
            elif max_cnt == 2 and case1(): ans = 1
            elif case2(): ans = 1
            else: ans = 2




    print("Case #" + str(case) + ":", ans)
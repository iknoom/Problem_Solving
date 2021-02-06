from itertools import combinations
from collections import Counter

def solution(orders, course):
    answer = []
    C = [Counter() for _ in range(11)]
    for order in orders:
        for n in course:
            if n > len(order): continue
            for sub in combinations(order, n):
                s = ''.join(sorted(sub))
                C[len(s)][s] += 1
    for n in course:
        max_count = -1
        ret = []
        for key in C[n].keys():
            if C[n][key] < 2: continue
            if max_count == C[n][key]: ret.append(key)
            elif max_count < C[n][key]:
                max_count = C[n][key]
                ret = [key]
        answer += ret
    return sorted(answer)

if __name__ == "__main__":
    print(solution(["XYZ", "XWY", "WXA"], [2,3,4]))
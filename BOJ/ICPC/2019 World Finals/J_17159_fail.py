import sys
import time

def get_interval(p, h, scores):
    ret = [[] for _ in range(p)]
    for a in range(p - 1):
        for b in range(a + 1, p):
            a_beat = False
            b_beat = False
            prv_dy = 0
            prv_cut = 1
            i = 0
            j = 0
            sum_a = 0
            sum_b = 0
            for cut in sorted(set(scores[a] + scores[b])):
                while i < h and scores[a][i] < cut:
                    sum_a += scores[a][i]
                    i += 1
                while j < h and scores[b][j] < cut:
                    sum_b += scores[b][j]
                    j += 1
                score_a = sum_a + (h - i) * cut
                score_b = sum_b + (h - j) * cut
                next_dy = abs(score_a - score_b)
                dx = cut - prv_cut

                if score_a < score_b:
                    if b_beat:
                        a_beat = True
                        b_beat = False
                        diff = dx * prv_dy // (prv_dy + next_dy)
                        ret[a].append((prv_cut + diff + 1, 1))
                        ret[b].append((prv_cut + diff + int((prv_dy + next_dy) * diff != dx * prv_dy), -1))
                    elif not a_beat:
                        a_beat = True
                        ret[a].append((prv_cut + 1, 1))
                elif score_a > score_b:
                    if a_beat:
                        a_beat = False
                        b_beat = True
                        diff = dx * prv_dy // (prv_dy + next_dy)
                        ret[a].append((prv_cut + diff + int((prv_dy + next_dy) * diff != dx * prv_dy), -1))
                        ret[b].append((prv_cut + diff + 1, 1))
                    elif not b_beat:
                        b_beat = True
                        ret[b].append((prv_cut + 1, 1))
                elif score_a == score_b and a_beat:
                    a_beat = False
                    ret[a].append((cut, -1))
                elif score_a == score_b and b_beat:
                    b_beat = False
                    ret[b].append((cut, -1))

                prv_dy = next_dy
                prv_cut = cut
    return ret

def sweep(intervals):
    ret = 0
    cur = 0
    for _, diff in sorted(intervals):
        cur += diff
        ret = max(ret, cur)
    return ret

def pre_submit():
    for case in range(3, 26):
        ans = []
        start_time = time.time()
        with open(f'testcase\secret-{case:02}.in', 'r') as sys.stdin:
            p, h = map(int, input().split())
            scores = [sorted(map(int, input().split())) for _ in range(p)]
            intervals = get_interval(p, h, scores)
            for i in range(p):
                ans.append(p - sweep(intervals[i]))
        end_time = time.time()
        flag = True
        with open(f'testcase\secret-{case:02}.ans', 'r') as sys.stdin:
            for i in range(p):
                tmp = int(input())
                if ans[i] != tmp:
                    flag = False
        if flag:
            print(f"case {case:02}: OK | {end_time - start_time : 0.4f}sec")
        else:
            print(f"case {case:02}: WA | {end_time - start_time : 0.4f}sec")

def solution():
    p, h = map(int, input().split())
    scores = [sorted(map(int, input().split())) for _ in range(p)]
    intervals = get_interval(p, h, scores)
    for i in range(p):
        print(p - sweep(intervals[i]))

if __name__ == "__main__":
    # pre_submit()
    solution()
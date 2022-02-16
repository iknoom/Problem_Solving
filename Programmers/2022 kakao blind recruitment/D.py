from itertools import combinations_with_replacement

def get_diff(apeach_info, lion_info):
    apeach_point = 0
    lion_point = 0
    for i in range(10):
        if apeach_info[i] == 0 and lion_info[i] == 0:
            continue
        if apeach_info[i] >= lion_info[i]:
            apeach_point += 10 - i
        else:
            lion_point += 10 - i
    return lion_point - apeach_point

def solution(n, info):
    max_diff = 0
    answer = []
    for selected in combinations_with_replacement(range(11), n):
        print(selected)
        lion_info = [0] * 11
        for i in selected:
            lion_info[i] += 1
        cur_diff = get_diff(info, lion_info)
        if cur_diff <= 0:
            continue

        if max_diff < cur_diff:
            max_diff = cur_diff
            answer = lion_info

        elif max_diff == cur_diff:
            if list(reversed(answer)) < list(reversed(lion_info)):
                answer = lion_info
    if not answer:
        return [-1]
    return answer

if __name__ == '__main__':
    print(solution(5, [2,1,1,1,0,0,0,0,0,0,0]))
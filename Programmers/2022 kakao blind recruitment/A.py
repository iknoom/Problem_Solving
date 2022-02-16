from collections import defaultdict

def solution(id_list, report, k):
    report = list(set(report))
    to_counter = defaultdict(int)
    for row in report:
        _from, _to = row.split()
        to_counter[_to] += 1

    from_counter = defaultdict(int)
    for row in report:
        _from, _to = row.split()
        if to_counter[_to] >= k:
            from_counter[_from] += 1
    answer = []
    for id in id_list:
        answer.append(from_counter[id])
    return answer

if __name__ == '__main__':
    print(solution(["muzi", "frodo", "apeach", "neo"],	["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"], 2))
# 비어있는 사진틀이 없는 경우에는 현재까지 추천 받은 횟수가 가장 적은 학생의 사진을 삭제
# 두 명 이상일 경우에는 게시된 지 가장 오래된 사진을 삭제

from collections import defaultdict

if __name__ == '__main__':
    N = int(input())
    d = defaultdict(int)
    last = {}

    M = int(input())
    A = list(map(int, input().split()))
    for i in range(M):
        if not A[i] in d:
            last[A[i]] = i
        if not A[i] in d and len(d) >= N:
            tmp = []
            for k in d.keys():
                tmp.append((d[k], last[k], k))
            _cnt, _l, min_k = min(tmp)
            d.pop(min_k)
        d[A[i]] += 1

    print(*sorted(d.keys()))
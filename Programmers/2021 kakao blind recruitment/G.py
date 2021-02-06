from sys import setrecursionlimit
setrecursionlimit(10**6)

def dfs(u, sales, childs):
    in_leader = sales[u]
    not_in_leader = 0
    diff = float('inf')
    for child in childs[u]:
        a, b = dfs(child, sales, childs)
        not_in_leader += min(a, b)
        in_leader += min(a, b)
        diff = min(diff, a - b)
    if childs[u]:
        not_in_leader += max(0, diff)
    return in_leader, not_in_leader

def solution(sales, links):
    n = len(sales)
    childs = [list() for _ in range(n)]
    for p, c in links:
        childs[p - 1].append(c - 1)
    a, b = dfs(0, sales, childs)
    return min(a, b)

if __name__ == "__main__":
    print(solution([14, 17, 15, 18, 19, 14, 13, 16, 28, 17],[[10, 8], [1, 9], [9, 7], [5, 4], [1, 5], [5, 10], [10, 6], [1, 3], [10, 2]]))
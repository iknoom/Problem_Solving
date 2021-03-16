
def solution(query, pattern):
    if len(query) < len(pattern) - 1:
        return "NE"
    L, R = pattern.split('*')
    if query[:len(L)] != L:
        return "NE"
    if query[-len(R):] != R:
        return "NE"
    return "DA"


if __name__ == '__main__':
    N = int(input())
    pattern = input()
    for _ in range(N):
        query = input()
        answer = solution(query, pattern)
        print(answer)
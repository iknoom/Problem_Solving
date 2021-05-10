def is_valid(paper):
    N = len(paper)
    if N == 1:
        return True
    mid = N // 2
    for i in range(mid):
        if paper[i] == paper[-i - 1]:
            return False
    return is_valid(paper[:mid])


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        paper = input()
        if is_valid(paper):
            print("YES")
        else:
            print("NO")
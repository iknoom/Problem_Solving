import sys

input = sys.stdin.readline


def solution():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))

    # solution
    stacks = [[] for _ in range(n + 1)]
    last_idx = [-1] * (n + 1)
    answer = []
    for i in range(n):
        if a[i] == b[i]:
            last_idx[b[i]] = i
        else:
            stacks[b[i]].append(i)
    c.reverse()
    last = -1
    for x in c:
        if stacks[x]:
            last = stacks[x].pop()
        else:
            if last < 0:
                if last_idx[x] < 0:
                    print("NO")
                    return
                else:
                    last = last_idx[x]
        answer.append(last + 1)

    for i in range(n + 1):
        if stacks[i]:
            print("NO")
            return
    else:
        print("YES")
        print(*reversed(answer))

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()
import sys

input = sys.stdin.readline


def solution():
    q = int(input())
    ty = []
    arr = []
    repl = []
    for _ in range(q):
        query = list(map(int, input().split()))
        if query[0] == 1:
            ty.append(1)
            arr.append(query[1])
        else:
            ty.append(2)
            repl.append(query[1:])
    answer = []
    dic = {}
    for t in reversed(ty):
        if t == 1:
            k = arr.pop()
            if k in dic:
                answer.append(dic[k])
            else:
                answer.append(k)
        else:
            a, b = repl.pop()
            if b in dic:
                dic[a] = dic[b]
            else:
                dic[a] = b
    print(*reversed(answer))



if __name__ == "__main__":
    solution()
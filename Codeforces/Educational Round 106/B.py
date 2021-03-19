from sys import stdin
input = stdin.readline

def solution():
    s = list(map(int, input().rstrip()))
    is_one = False
    last = -1000
    for i in range(len(s)):
        if is_one:
            if s[i] == 1:
                continue
            if last + 1 < i:
                last = i
            else:
                print("NO")
                return
        else:
            if s[i] == 0:
                continue
            if last + 1 < i:
                last = i
            else:
                is_one = True
    print("YES")


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()

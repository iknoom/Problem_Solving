import sys

input = sys.stdin.readline

def solution():
    N = int(input())
    count = [0] * 26
    for i in range(N):
        for k in input().rstrip():
            count[ord(k) - ord('a')] += 1
    flag = True
    for i in range(26):
        if count[i] % N != 0:
            flag = False
    if flag:
        print("YES")
    else:
        print("NO")


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()
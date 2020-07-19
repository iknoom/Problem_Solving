import sys

input = sys.stdin.readline


def check(N, S, k):
    ABA = "abacaba"
    for j in range(7):
        S[k + j] = ABA[j]
    ans = 0
    for i in range(N - 6):
        c_flag = True
        for j in range(7):
            if S[i + j] != ABA[j]:
                c_flag = False
        if c_flag:
            ans += 1
    if ans == 1:
        print("Yes")
        for i in range(N):
            if S[i] == '?':
                S[i] = 'z'
        print(''.join(S))
        return True

    return False

def solution():
    N = int(input())
    S = list(input().rstrip())
    ABA = "abacaba"
    idx = []
    for i in range(N - 6):
        c_flag = True
        for j in range(7):
            if S[i + j] != "?" and S[i + j] != ABA[j]:
                c_flag = False
        if c_flag:
            idx.append(i)
    for i in idx:
        if check(N, S[:], i):
            return
    print("No")




if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()

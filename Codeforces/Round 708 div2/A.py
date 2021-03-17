from sys import stdin
input = stdin.readline

def solution():
    N = int(input())
    A = list(map(int, input().split()))
    vst = [False] * 105
    L = []
    R = []
    for a in A:
        if not vst[a]:
            L.append(a)
            vst[a] = True
        else:
            R.append(a)
    print(*(sorted(L) + R))

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()
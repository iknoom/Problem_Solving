from sys import stdin

input = stdin.readline

if __name__ == "__main__":
    N = int(input())
    ALL = set()
    pset = set()
    nset = set()
    for _ in range(N):
        S = input().rstrip()
        if S[0] == "!":
            S = S[1:]
            nset.add(S)
        else:
            pset.add(S)
        ALL.add(S)
    flag = True
    for a in ALL:
        if a in pset and a in nset:
            print(a)
            flag = False
            break
    if flag:
        print("satisfiable")
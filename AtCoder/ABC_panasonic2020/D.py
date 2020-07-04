N = int(input())
al = [chr(i + 97) for i in range(N)]
def sol(S):
    if len(S) == N:
        print(S)
        return
    for i in range(len(set(S)) + 1):
        sol(S + al[i])
sol('')
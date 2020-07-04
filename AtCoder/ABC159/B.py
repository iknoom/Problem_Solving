S = input()
N = len(S)

def is_pal(X):
    ret = True
    for i in range(len(X)//2+1):
        if X[i] != X[-i-1]:
            ret = False
    return ret


if is_pal(S) and is_pal(S[:N//2]) and is_pal(S[N//2+1:]):
    print("Yes")
else:
    print("No")
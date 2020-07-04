A, P = map(int, input().split())
vst = set([A])
def get_next(x):
    ret = 0
    while x:
        k = x % 10
        ret += k ** P
        x //= 10
    return ret
while True:
    A = get_next(A)
    if A in vst: break
    vst.add(A)
while A in vst:
    vst.discard(A)
    A = get_next(A)
print(len(vst))
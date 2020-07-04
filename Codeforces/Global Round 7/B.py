N = int(input())
B = list(map(int, input().split()))
a = [B[0]]
k = B[0]
for b in B[1:]:
    if b <= 0:
        a.append(k + b)
    else:
        a.append(k + b)
        k += b
print(*a)
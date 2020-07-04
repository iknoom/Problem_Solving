def is_pal(A):
    for i in range(len(A)//2 + 1):
        if A[i] != A[-i-1]: return 'no'
    return 'yes'

while True:
    A = input()
    if A == '0': break
    print(is_pal(A))
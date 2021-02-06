from collections import Counter as C
N=int(input())
A=C(map(int,input().split()))
A[0]=0
B=C(A.values())
m=max(B.keys())
if m and B[m]==1:
    for k in A.keys():
        if A[k]==m:print(k)
else:print("skipped")
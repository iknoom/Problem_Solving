from itertools import combinations as cb
diff = {0}
A = list(map(int,input().split()))
B = list(map(int,input().split()))
for i in range(10):
	for j in range(10):
		diff.add(B[j]-A[i])
for a1,a2 in cb(A,2):
	for b1,b2 in cb(B,2):
		diff.add(b1+b2-a1-a2)
print(len(diff))

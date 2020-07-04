n = int(input())
x = sorted(map(int,input().split()))
ans = 0

if n <= 3:
	print(1)
	exit()

i = 1
while i < n:
	ans += 1
	p = q = i
	while p < n-1 and x[p]-x[p-1] <= x[p+1]-x[p]: p += 1
	while q < n-1 and x[q]-x[q-1] > x[q+1]-x[q]: q += 1
	if p == n-1: p += 1
	i = max(p, q+1)
					
print(ans)

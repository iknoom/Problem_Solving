import sys
input = sys.stdin.readline

N = int(input())
I = [tuple(map(int,input().split())) for _ in range(N)]
I.sort()

a1, b1 = I[0]
a0, b0 = I[0]
ans = 0
diff = b1 - a1

for a, b in I[1:]:
	if b0 < a:
		ans += b0 - a0
		a0, b0 = a, b
	elif b0 < b:
		b0 = b
	
	diff = min(diff,b-a)
	if a <= a1 and b1 <= b:
		diff = 0
	elif a1 <= a and b <= b1:
		diff = 0
	elif b1 <= a:
		a1, b1 = a, b
	else:
		diff = min(diff, a - a1)
		diff = min(diff, b - b1)
		a1, b1 = b1, b
		
ans += b0 - a0
print(ans - diff)

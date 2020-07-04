n = int(input())
s = 1
a = 0
b = 0

for i in range(2,n+1):
	x = i
	while x % 2 == 0:
		x //= 2
		a += 1
	while x % 5 == 0:
		x //= 5
		b += 1
	s *= x
	s %= 10

if a == b:
	print(s)

elif a < b:
	print(5)

else:
	a -= b
	x = (a-1)%4
	s *= 2**(x+1)
	print(s%10)
	

a,b,c = sorted(map(int,input().split()))
p = c - b - 1
q = b - a - 1
t = 2
if p == 1 or q == 1: t = 1
r = max(p,q)
print(min(t,r))
print(r)

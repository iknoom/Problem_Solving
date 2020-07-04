L = int(input())
S = input()
r = 31
M = 1234567891
ret = 0
for i in range(L):
    ret += (ord(S[i])- 96) * (r**i)
    ret %= M
print(ret)
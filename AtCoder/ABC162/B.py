N = int(input())

a = N//3
b = N//5
c = N//15
print(N*(N + 1)//2 - a*(a+1)//2*3 - b*(b+1)//2*5 + c*(c+1)//2*15)
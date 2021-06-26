N=int(input())+1
print(N*N-1)
for i in range(N*2):
 for c in range(1,N)[max(0,i-N):i+1]:print(i%2+1,c)
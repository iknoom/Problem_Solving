C=[*range(1,21)]
for _ in range(10):a,b=map(int,input().split());C=C[:a-1]+C[a-1:b][::-1]+C[b:]
print(*C)
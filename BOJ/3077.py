N = int(input())
arr = input().split()
dic = {arr[i] : i for i in range(N)}
arr2 = input().split()
a = 0
b = 0
for i in range(N - 1):
    for j in range(i + 1, N):
        b += 1
        if dic[arr2[i]] < dic[arr2[j]]:
            a += 1
print(f'{a}/{b}')
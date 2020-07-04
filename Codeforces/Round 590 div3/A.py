for _ in range(int(input())):
    N = int(input())
    K = sum(map(int,input().split()))
    if(K%N == 0): print(K//N)
    else: print(K//N+1)
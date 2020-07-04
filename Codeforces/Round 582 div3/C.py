for _ in range(int(input())):
    n, m = map(int,input().split())
    Q = [(i*m)%10 for i in range(1,11)]
    x = n//m
    print( (x//10) * sum(Q) +  sum(Q[:x%10]) )
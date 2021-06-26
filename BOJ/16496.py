from functools import cmp_to_key

def my_cmp(x, y):
    return int(str(y) + str(x)) - int(str(x) + str(y))

N = int(input())
A = list(map(int, input().split()))
A.sort(key=cmp_to_key(my_cmp))
print(int(''.join(map(str, A))))
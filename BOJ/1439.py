A = input()
a = ('0' + A).count('01')
b = ('1' + A).count('10')
print(min(a, b))
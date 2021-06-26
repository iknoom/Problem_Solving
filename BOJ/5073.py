while True:
    abc = sorted(map(int, input().split()))
    if sum(abc) == 0:
        break
    a, b, c = abc
    if a + b <= c:
        print("Invalid")
    elif a == b == c:
        print("Equilateral")
    elif a == b or b == c:
        print("Isosceles")
    else:
        print("Scalene")
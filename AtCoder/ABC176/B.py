N = input()

S = sum(map(int, N))


if S % 9 == 0:
    print("Yes")
else:
    print("No")

from sys import stdin
input = stdin.readline

if __name__ == '__main__':
    A, B = map(int, input().split())
    solid = A + B
    fat = B

    if solid >= 15 and fat >= 8:
        print(1)
    elif solid >= 10 and fat >= 3:
        print(2)
    elif solid >= 3:
        print(3)
    else:
        print(4)
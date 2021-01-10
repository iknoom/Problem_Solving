from sys import stdin
input = stdin.readline

if __name__ == "__main__":
    X, Y = map(int, input().split())
    if abs(X - Y) < 3:
        print("Yes")
    else:
        print("No")


from sys import stdin
input = stdin.readline

if __name__ == "__main__":
    D, T, S = map(int, input().split())
    if D > T * S: print("No")
    else:print("Yes")
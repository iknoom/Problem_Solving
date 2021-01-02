from sys import stdin
input = stdin.readline

if __name__ == "__main__":
     A, B = input().split()
     print(max(sum(map(int, A)), sum(map(int, B))))

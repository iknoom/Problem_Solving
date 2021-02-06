from sys import stdin
input = stdin.readline

if __name__ == "__main__":
    SET = 0
    M = int(input())
    for _ in range(M):
        query = input().split()

        if query[0] == "add":
            x = int(query[1]) - 1
            SET |= (1 << x)

        elif query[0] == "remove":
            x = int(query[1]) - 1
            if SET & (1 << x):
                SET -= (1 << x)
            # 또는 SET &= ~(1 << x)

        elif query[0] == "toggle":
            x = int(query[1]) - 1
            SET ^= (1 << x)

        elif query[0] == "check":
            x = int(query[1]) - 1
            if SET & (1 << x):
                print(1)
            else:
                print(0)

        elif query[0] == "all":
            SET = (1 << 20) - 1

        elif query[0] == "empty":
            SET = 0
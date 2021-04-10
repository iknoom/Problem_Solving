def is_pal(S):
    for i in range(len(S)):
        if S[i] != S[-i-1]:
            return False
    return True

def main():
    S = input()
    for i in range(len(S)):
        if is_pal(S[i:]):
            print(len(S) + i)
            return

if __name__ == '__main__':
    main()

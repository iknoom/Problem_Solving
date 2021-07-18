N = int(input())
# good or bad

S = input()
for i in range(len(S)):
    if S[i] == '1':
        if i % 2:
            print("Aoki")
        else:
            print("Takahashi")
        break
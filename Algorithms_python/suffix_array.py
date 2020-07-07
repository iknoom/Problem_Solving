from functools import cmp_to_key

class SA_constructor:
    def __init__(self, S):
        self.S = S
        self.d = 1
        self.N = len(self.S)
        self.sa = [i for i in range(self.N)]
        self.pos = [self.S[i] for i in range(self.N)]
        self.lcp = [0] * self.N

    def _expon(self):
        self.d *= 2

    def _func(self, i, j):
        if self.pos[i] != self.pos[j]:
            if self.pos[i] < self.pos[j]:
                return -1
            elif self.pos[i] > self.pos[j]:
                return 1
            else:
                return 0
        i += self.d
        j += self.d
        if i < self.N and j < self.N:
            if self.pos[i] < self.pos[j]:
                return -1
            elif self.pos[i] > self.pos[j]:
                return 1
            else:
                return 0
        else:
            if i > j:
                return -1
            elif i < j:
                return 1
            else:
                return 0

    def construct_SA(self):
        while True:
            self.sa.sort(key=cmp_to_key(self._func))
            temp = [0] * self.N
            for i in range(self.N - 1):
                if self._func(self.sa[i], self.sa[i + 1]) == -1:
                    temp[i + 1] = temp[i] + 1
                else:
                    temp[i + 1] = temp[i]
            for i in range(self.N):
                self.pos[self.sa[i]] = temp[i]
            if temp[-1] == self.N - 1:
                break
            self._expon()

    def construct_LCP(self):
        k = 0
        for i in range(self.N):
            if self.pos[i] == self.N - 1: continue
            j = self.sa[self.pos[i] + 1]
            while i + k < self.N and j + k < self.N and S[i + k] == S[j + k]: k += 1
            self.lcp[self.pos[i]] = k
            k = max(k - 1, 0)


if __name__ == "__main__":
    S = input()
    constructor = SA_constructor(S)
    constructor.construct_SA()
    constructor.construct_LCP()

    for i in range(len(S)):
        print(constructor.sa[i] + 1, end=' ')
    print()

    print('x', end=' ')
    for i in range(len(S) - 1):
        print(constructor.lcp[i], end=' ')
    print()
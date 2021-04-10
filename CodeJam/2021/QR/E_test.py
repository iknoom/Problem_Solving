import random
import matplotlib.pyplot as plt
from math import exp
from sys import stdin
input = stdin.readline
TEST = 100000

def sigmoid(x):
    return 1 / (1 + exp(-x))

def rand_float():
    return 3 - random.random() * 6

def get_p(s):
    count = 0
    for _ in range(TEST):
        Q_j = rand_float()
        p = sigmoid(s - Q_j)
        if random.random() <= p:
            count += 1
    return count / TEST

def get_cheat_p(s):
    count = 0
    for _ in range(TEST):
        if random.random() <= 0.5:
            count += 1
            continue
        Q_j = rand_float()
        p = sigmoid(s - Q_j)
        if random.random() <= p:
            count += 1
    return count / TEST

def make_plot():
    x = []
    nomal = []
    cheat = []
    for s in range(-300, 301):
        S_i = s / 100
        x.append(S_i)
        nomal.append(get_p(S_i))
        cheat.append(get_cheat_p(S_i))
    plt.plot(x, nomal)
    plt.plot(x, cheat)
    plt.show()
    print("nomal: ", get_p(3), get_p(-3))
    print("cheat: ", get_cheat_p(3), get_cheat_p(-3))


if __name__ == '__main__':
    make_plot()
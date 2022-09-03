#Created by Jeffrey Daniel to show the Collatz Conjecture

import numpy as np
import matplotlib.pyplot as plt

def collatz(i):
    numbers = []
    numbers.append(i)
    while(i > 1):
        if(i%2 == 0):
            i = i / 2
        else:
            i = 3*i + 1
        numbers.append(i)
    return numbers


xaxis = []
power2curve = []
collatzcurve = []
for i in range(0,10):
    xaxis.append(i)
    power2curve.append(2**i)
    collatzcurve.append(3*i + 1)

plt.plot(xaxis, collatzcurve, power2curve)
plt.xlabel('Natural numbers')
plt.ylabel('Powers of 2 and 3n+1 graphs')
plt.legend(['3n+1', '2^n'])
plt.title('2^n and 3n+ 1 curves')
plt.show()

collatzjump = []
plt.plot(xaxis)
for i in range(0, 500):
    plt.plot(collatz(i))
plt.legend()
plt.show()


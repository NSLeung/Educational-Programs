import numpy as np
# print(np.exp(2))
x = [1, 2, 3, 4, 5, 6, 7]
y = np.zeros(2*len(x) - 1)
print("hello", x)
y[::2] = x
print(y)

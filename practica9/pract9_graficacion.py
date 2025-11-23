
from numpy import linspace, sin

import matplotlib.pyplot as plt

from mpl_toolkits.mplot3d import Axes3D

x = linspace (0, 5, 20)

fig, ax = plt.subplots(facecolor='purple', edgecolor='blue')

ax.plot(x, sin(x), marker="o", color="red", linestyle='None')

ax.grid(True)
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.grid(True)
ax.legend(["y = x**2"])

plt.title('puntos :3')
plt.show()

fig.savefig("grafica.png")

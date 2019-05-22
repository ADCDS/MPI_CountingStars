'''
======================
3D surface (color map)
======================

Demonstrates plotting a 3D surface colored with the coolwarm color map.
The surface is made opaque by using antialiased=False.

Also demonstrates using the LinearLocator and custom formatting for the
z axis tick labels.
'''

import pandas
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from matplotlib import cm
from matplotlib.ticker import LinearLocator, FormatStrFormatter
import numpy as np

data = pandas.read_csv('results.txt')

fig = plt.figure(figsize=(20,10))
ax = fig.gca(projection='3d')
ax.set_xlabel('Número de processadores')
ax.set_ylabel('Tamanho do bloco (bytes)')
ax.set_zlabel('Tempo de execução (microsegundos)')
# ax.plot_wireframe(cParams, gammas, avg_errors_array)
# ax.plot3D(cParams, gammas, avg_errors_array)
# ax.scatter3D(cParams, gammas, avg_errors_array, zdir='z',cmap='viridis')

data.microseconds *= 20
# data.microseconds /= 1000000

data.to_latex('local2.tex')
surf = ax.plot_trisurf(data.processor_num, data.block_size, data.microseconds, cmap=cm.jet, linewidth=5)
fig.colorbar(surf, aspect=50)
plt.show()

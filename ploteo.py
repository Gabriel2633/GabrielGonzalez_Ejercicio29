import numpy as np
import matplotlib.pyplot as plt
import os

from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm
os.system("g++ correr.cpp")
os.system("./a.out")

pinocho = np.loadtxt("datos.dat")

a=np.linspace(0,len(pinocho[0]),len(pinocho[0]))



fig = plt.figure()
ax = Axes3D(fig)
x, y = np.mgrid[0:pinocho.shape[0],0:pinocho.shape[1]]
surfe=ax.plot_surface(x,y,pinocho,rstride=1,cstride=1,cmap=cm.coolwarm,linewidth=0,antialiased=False)
fig.colorbar(surfe, shrink=0.5, aspect=5)
plt.ylabel("Posicion [metros]")
plt.xlabel("Tiempo [segundos]")
plt.savefig("graficas.png")

plt.figure()
plt.plot(a,pinocho[0],label="tiempo inicial")
plt.plot(a,pinocho[-1],label="tiempo final")
plt.legend()
plt.xlabel("Posicion [metros]")
plt.ylabel("Desplazamiento [metros]")
plt.savefig("graficas2.png")


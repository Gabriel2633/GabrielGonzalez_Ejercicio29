import numpy as np 
import matplotlib.pyplot as plt
import os
from mpl_toolkits.mplot3d import Axes3D

os.system("g++ c.cpp")
os.system("./a.out")

pinocho = np.loadtxt("datos.dat")

a=np.linspace(1,len(pinocho[0]),len(pinocho[0]))

plt.subplot(121)

fig = plt.figure()
ax = Axes3D(fig)
ax.imshow(pinocho)
ax.colorbar()
plt.ylabel("Posicion [metros]")
plt.xlabel("Tiempo [segundos]")

plt.subplot(122)
plt.plot(a,pinocho[0])
plt.plot(a,pinocho[-1])
plt.ylabel("Temperatura")
plt.xlabel("Indice X")
plt.legend()

plt.savefig("graficas.png")
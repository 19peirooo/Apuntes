import numpy as np
from timeit import default_timer as timer
import matplotlib.pyplot as plt


#start = timer()
#length = 10000000
#l = np.array(range(0,length), dtype = np.int64)
#end = timer()

#print(f"La suma es {np.sum(l)}")
#print ("Tiempo: " + str(end - start))

x = np.arange(0,7,0.1)
y = np.cos(x)

plt.plot(x,y)
plt.show()

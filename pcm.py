import math
import numpy as np
import matplotlib.pyplot as plt
time=np.arange(0,60,0.015)
qntz_level=np.arange(-3,4,0.4)
pcm_val=np.arange(-3,4,0.4)
mt=np.cos(2*np.pi*1*time)
initial_qntz = np.digitize(mt, qntz_level) - 1
quantz = pcm_val[initial_qntz]
plt.subplot(3, 1, 1)
plt.plot(time, mt)
plt.title('Message Signal',color='blue')
plt.xlabel('Time(s) ',color='blue')
plt.ylabel('Amplitude(V) ',color='red')
plt.xlim([0, 25])
plt.subplot(3, 1, 2)
plt.plot(time, quantz,color="black")
plt.title('Quantized Signal',color='blue')
plt.xlabel('Time(s)',color='blue')
plt.ylabel('Amplitude(V)',color='red')
plt.xlim([0, 25])
y = np.uint8((quantz - pcm_val[0]) / (pcm_val[1] - pcm_val[0]))
plt.subplot(3, 1, 3)
plt.plot(time, y,color="red")
plt.title('PCM Signal',color="blue")
plt.xlabel('Time(s) ')
plt.ylabel('Amplitude(V) ')
plt.xlim([0, 25])
plt.tight_layout()

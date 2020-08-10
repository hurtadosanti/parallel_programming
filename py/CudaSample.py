#%%
import pycuda.autoinit
import pycuda.driver as cuda
print(cuda.Device.count())

#%%
(free, total) = cuda.mem_get_info()
print(free, total)
for dn in range(cuda.Device.count()):
    device = cuda.Device(dn)
    attrs = device.get_attributes()
    print(str(attrs))

# Code Motion (Moves computations that do not change within the loop outside of the loop.)
import time

n = 30000000   # 30 lakh
a = b= d = e = f = g = h = 0
start = time.time()  # Record start time
for i in range(n):
    a = b + i
    c = d + e
    f = g + h   

end = time.time()      # Record end time

print("***** Code Motion ******")
print("Execution Time (Before Code Motion):", end - start, "seconds")


a = b= d = e = f = g = h = 0
start = time.time()  # Record start time

c = d + e   # Moves computations that do not change within the loop outside of the loop.
f = g + h   
for i in range(n):
    a = b + i
end = time.time()      # Record end time

print("Execution Time (After Code Motion):", end - start, "seconds")

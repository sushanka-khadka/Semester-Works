# Loop Jamming (Loop Fusion)  -> is an optimization technique where two or more loops that iterate over the same range are combined into a single loop. This can improve performance by reducing loop overhead and enhancing cache locality.

import time

n = 10000000    # one crore
squares = []
doubles = []

# Separate loops
start = time.time()
for x in range(n):
    squares.append(x ** 2)
for x in range(n):
    doubles.append(x * 2)

end = time.time()

print("***** Code Jamming ******")
print("Execution Time (Before Loop Jamming):", end - start, "seconds")

# Fused loop (loop jamming)
squares = []
doubles = []
start = time.time()
for x in range(n):      # Combines two or more loops that iterate over the same range into a single loop to reduce overhead.
    squares.append(x ** 2)
    doubles.append(x * 2)

end = time.time()
print("Execution Time (After Loop Jamming):", end - start, "seconds")


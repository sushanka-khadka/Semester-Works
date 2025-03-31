from collections import deque

def water_jug_BFS():
    # Initialize the queue with the starting state (0, 0)
    queue = deque([(0, 0)])
    visited = set((0, 0))
    
    while queue:
        a, b = queue.popleft()
        
        # If we have exactly 2 gallons in the 4-gallon jug, return the solution
        if a == 2:
            return True
        
        # Possible states after performing the operations
        states = [
            (4, b),  # Fill the 4-gallon jug
            (a, 3),  # Fill the 3-gallon jug
            (0, b),  # Empty the 4-gallon jug
            (a, 0),  # Empty the 3-gallon jug
            (a - min(a, 3 - b), b + min(a, 3 - b)),  # Pour water from 4-gallon to 3-gallon jug
            (a + min(b, 4 - a), b - min(b, 4 - a))   # Pour water from 3-gallon to 4-gallon jug
        ]
        
        for state in states:
            if state not in visited:
                visited.add(state)
                queue.append(state)
    
    return False

# Run the function
if water_jug_BFS():
    print("Solution found: You can get exactly 2 gallons in the 4-gallon jug.")
else:
    print("No solution exists.")

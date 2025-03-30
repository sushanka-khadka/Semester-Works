import random

def hill_climbing(problem, initial_state):
    current = initial_state
    while True:
        neighbors = problem.get_neighbors(current)
        if not neighbors:
            break
        neighbor = max(neighbors, key=problem.value)
        if problem.value(neighbor) <= problem.value(current):
            break
        current = neighbor
    return current

class Problem:
    def __init__(self, state_space, value_function):
        self.state_space = state_space
        self.value_function = value_function

    def get_neighbors(self, state):
        neighbors = []
        for i in range(len(state)):
            if state[i] > 0:
                neighbor = state[:]
                neighbor[i] -= 1
                neighbors.append(neighbor)
            if state[i] < self.state_space[i] - 1:
                neighbor = state[:]
                neighbor[i] += 1
                neighbors.append(neighbor)
        return neighbors

    def value(self, state):
        return self.value_function(state)

# Example usage
state_space = [10, 10]  # Example state space
initial_state = [random.randint(0, 9), random.randint(0, 9)]

def value_function(state):
    # Example value function: sum of the state values
    return sum(state)

problem = Problem(state_space, value_function)
solution = hill_climbing(problem, initial_state)
print(f"Initial state: {initial_state}")
print(f"Solution: {solution}")
print(f"Value of solution: {problem.value(solution)}")

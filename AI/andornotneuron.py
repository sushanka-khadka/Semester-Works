def AND_gate(x1, x2):
    w1, w2, theta = 1, 1, 1.5
    y = w1 * x1 + w2 * x2
    return 1 if y >= theta else 0

def OR_gate(x1, x2):
    w1, w2, theta = 1, 1, 0.5
    y = w1 * x1 + w2 * x2
    return 1 if y >= theta else 0

def NOT_gate(x):
    w, theta = -1, -0.5
    y = w * x
    return 1 if y >= theta else 0

# Test the gates
if __name__ == "__main__":
    print("AND Gate")
    print(f"AND(0, 0) = {AND_gate(0, 0)}")
    print(f"AND(0, 1) = {AND_gate(0, 1)}")
    print(f"AND(1, 0) = {AND_gate(1, 0)}")
    print(f"AND(1, 1) = {AND_gate(1, 1)}")

    print("\nOR Gate")
    print(f"OR(0, 0) = {OR_gate(0, 0)}")
    print(f"OR(0, 1) = {OR_gate(0, 1)}")
    print(f"OR(1, 0) = {OR_gate(1, 0)}")
    print(f"OR(1, 1) = {OR_gate(1, 1)}")

    print("\nNOT Gate")
    print(f"NOT(0) = {NOT_gate(0)}")
    print(f"NOT(1) = {NOT_gate(1)}")

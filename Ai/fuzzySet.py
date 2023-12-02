import numpy as np
import matplotlib.pyplot as plt

x = np.array([1, 2, 3, 5, 6, 7, 8])

# Task 1: Calculate membership for gamma = 1
gamma = 1
membership_1 = []

print("Gamma = 1:")
for val in x:
    max_x = max(val, 5)
    factor = gamma * abs((5 / max_x) - (val / max_x))

    if factor == 0:
        memvalue = 1
    elif 0 < factor < 1:
        memvalue = 1 - factor
    elif factor >= 1:
        memvalue = 0

    membership_1.append(memvalue)
    print(f"x = {val}, Factor = {factor}, Membership = {memvalue}")

# Task 2: Calculate membership for gamma = 4
gamma = 4
membership_4 = []

print("\nGamma = 4:")
for val in x:
    max_x = max(val, 5)
    factor = gamma * abs((5 / max_x) - (val / max_x))

    if factor == 0:
        memvalue = 1
    elif 0 < factor < 1:
        memvalue = 1 - factor
    elif factor >= 1:
        memvalue = 0

    membership_4.append(memvalue)
    print(f"x = {val}, Factor = {factor}, Membership = {memvalue}")

# Task 3: Plot graph for membership vs x for both cases
plt.figure(figsize=(10, 5))
plt.plot(x, membership_1, label='Gamma = 1', marker='o')
plt.plot(x, membership_4, label='Gamma = 4', marker='x')
plt.xlabel('x')
plt.ylabel('Membership Value')
plt.title('Membership vs x for Different Gamma Values')
plt.legend()
plt.grid(True)
plt.show()

# Task 4: Check convexity and normality
is_convex_1 = False
is_convex_4 = False

for i in range(len(x) - 2):
    x1 = x[i]
    x2 = x[i + 1]
    mem_x1 = membership_1[i]
    mem_x2 = membership_1[i + 1]

    gamma_x1 = gamma * x1 + (1 - gamma) * x2

    min_mem_x1_x2 = min(mem_x1, mem_x2)

    if membership_1[gamma_x1] >= min_mem_x1_x2:
        is_convex_1 = True
        break

for i in range(len(x) - 2):
    x1 = x[i]
    x2 = x[i + 1]
    mem_x1 = membership_4[i]
    mem_x2 = membership_4[i + 1]

    gamma_x1 = gamma * x1 + (1 - gamma) * x2

    min_mem_x1_x2 = min(mem_x1, mem_x2)

    if membership_4[gamma_x1] >= min_mem_x1_x2:
        is_convex_4 = True
        break

is_normal_1 = max(membership_1) == 1
is_normal_4 = max(membership_4) == 1


print(f"For Gamma = 1: Convex = {is_convex_1}, Normal = {is_normal_1}")
print(f"For Gamma = 4: Convex = {is_convex_4}, Normal = {is_normal_4}")

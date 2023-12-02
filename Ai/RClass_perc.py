import numpy as np
import matplotlib.pyplot as plt

def signum(x):
    return 1 if x >= 0 else -1

T = np.array([[0.1, 0.1, -1, 0],
              [0.2, 0.1, -1, 0],
              [0.5, 0.1, -1, 1],
              [0.6, 0.1, -1, 1],
              [0.3, 0.3, -1, 2],
              [0.4, 0.3, -1, 2]])

W = np.array([[-0.1, 0.15, 0.2],
              [-0.2, 0.11, 0.17],
              [0.17, 0.16, 0.11]])

D = np.array([[1, -1, -1],
              [-1, 1, -1],
              [-1, -1, 1]])

learning_rate = 1
epochs = 100  # Number of epochs

c = 0  # Counter for training cycles
P = 6  # Number of training pairs
error_list = []  # List to store errors for each cycle

for epoch in range(epochs):
    c += 1
    E = 0  # Error for the current training cycle

    for p in range(P):
        x1, x2, bias, d = T[p]

        y = np.zeros(3)
        o = np.zeros(3)

        for i in range(3):
            y[i] = x1 * W[i][0] + x2 * W[i][1] + bias * W[i][2]
            o[i] = signum(y[i])

        d = int(d)  # Convert d to an integer

        for i in range(3):
            if o[i] != D[d][i]:
                for j in range(3):
                    W[i][j] += 0.5 * learning_rate * (D[d][i] - o[i]) * T[p][j]
                E += 0.5 * (D[d][i] - o[i]) ** 2

        print(f"Updated Weight Matrix (W) after X{p + 1} = [{x1:.3f}, {x2:.3f}]:")
        print(W)
        print(f"Error after processing X{p + 1} = [{x1:.3f}, {x2:.3f}]: {E:.3f}\n")

    error_list.append(E)

    if E == 0:
        print(f"Training completed in epoch {epoch + 1}/{epochs}.")
        break

# Plotting the error graph
plt.plot(range(1, c + 1), error_list, marker='o')
plt.xlabel('Cycle')
plt.ylabel('Error')
plt.title('Error vs. Cycle')
plt.grid(True)
plt.show()

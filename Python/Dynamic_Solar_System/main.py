import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import solve_ivp

# Constants
G = 6.67430e-11  # Gravitational constant (m^3 kg^-1 s^-2)

# Positions of the planets at the initial time [m]
positions = [
    np.array([0, 0, 0]),
    np.array([-4.6e10, 0, 0]),
    np.array([-1.05e11, 0, 0]),
    np.array([1.5e11, 0, 0]),
    np.array([2.2e11, 0, 0]),
    np.array([7.78e11, 0, 0]),
    np.array([1.43e12, 0, 0]),
    np.array([2.87e12, 0, 0]),
    np.array([4.49e12, 0, 0])
]

# Velocities of the planets at the initial time [m/s]
velocities = [
    np.array([0, 0, 0]),
    np.array([-4.6e3, 0, 0]),
    np.array([-3.5e3, 0, 0]),
    np.array([3.0e3, 0, 0]),
    np.array([2.4e3, 0, 0]),
    np.array([1.33e4, 0, 0]),
    np.array([9.7e3, 0, 0]),
    np.array([6.8e3, 0, 0]),
    np.array([5.4e3, 0, 0])
]

# Masses of the planets [kg]
M = {
    'sun': 1.989e30,
    'mercury': 3.30e23,
    'venus': 4.87e24,
    'earth': 5.97e24,
    'mars': 6.42e23,
    'jupiter': 1.9e27,
    'saturn': 5.68e26,
    'uranus': 8.68e25,
    'neptune': 1.02e26
}

# Convert the positions and velocities to a list of arrays
pos = [positions[i] for i in range(8)]
vel = [velocities[i] for i in range(8)]

# Concatenate the positions and velocities to create the initial state vector
y0 = np.concatenate([pos, vel], axis=1)

# Time span for the simulation
t_span = (0, 30 * 365 * 24 * 60 * 60)  # 30 years

# Define the function that calculates the derivative of the state vector
def force(t, y, M, G):
    forces = np.zeros((8, 3))
    for i in range(8):
        for j in range(i+1, 8):
            r = y[i] - y[j]
            r_norm = np.linalg.norm(r)
            f = G * M[list(M.keys())[i]] * M[list(M.keys())[j]] / r_norm**3
            forces[i] -= f * r / r_norm
            forces[j] += f * r / r_norm
    return np.concatenate([forces, np.zeros((8, 3))])

# Solve the initial value problem
solution = solve_ivp(lambda t, y: force(t, y, M, G), t_span, y0, method='RK45')

# Extract the positions and velocities from the solution
positions = solution.y[:, :8]
velocities = solution.y[:, 8:]

# Plot the orbits of the planets
for i in range(8):
    plt.plot(positions[i][0], positions[i][1], label=list(M.keys())[i])

# Plot the Sun at the center
plt.plot(0, 0, 'ko', markersize=10)

# Add a legend
plt.legend()

# Add labels and title
plt.xlabel('x (m)')
plt.ylabel('y (m)')
plt.title('Orbits of the planets in the Solar System')

# Show the plot
plt.show()

# Test the accuracy of the simulation
for i in range(8):
    print(f'Relative error in the position of {list(M.keys())[i]}: {np.linalg.norm(positions[i] - positions[i][0]) / np.linalg.norm(positions[i][0])}')
    print(f'Relative error in the velocity of {list(M.keys())[i]}: {np.linalg.norm(velocities[i] - velocities[i][0]) / np.linalg.norm(velocities[i][0])}')
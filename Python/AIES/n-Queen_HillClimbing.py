# Experiment No 2
# Author: Amaan Shaikh
# Branch: TYCSE-A
# PRN: 1032221184
# File name: n-Queen_HillClimbing.py


import random
import tkinter as tk

# Function to check if a queen can be placed at a given position
def is_valid(board, row, col):
    # Check if there is a queen in the same column
    for i in range(row):
        if board[i] == col:
            return False
        # Check if there is a queen in the diagonal
        if abs(board[i] - col) == abs(i - row):
            return False
    return True

# Function to solve the N-Queen problem using the hill climbing algorithm
def solve_n_queen(n):
    if n < 4:
        return []

    board = [-1] * n
    # Place a queen in each row
    for row in range(n):
        # Generate all possible positions for the queen in the current row
        candidates = []
        for col in range(n):
            if is_valid(board, row, col):
                candidates.append(col)
        # Randomly select a position from the candidates
        if candidates:
            board[row] = random.choice(candidates)
        else:
            # If no valid position found, restart the algorithm
            return solve_n_queen(n)
    return board

# Function to display the N-Queen solution using Tkinter
def display_solution(board):
    n = len(board)
    window = tk.Tk()
    window.title("N-Queen Solution")
    window.geometry(f"{n * 70}x{n * 45}")  # Set window size based on board size

    for row in range(n):
        for col in range(n):
            if board[row] == col:
                label = tk.Label(window, text="X", font=("Arial", 16), fg="red")
            else:
                label = tk.Label(window, text=f"({row}, {col})", font=("Arial", 16))
            label.grid(row=row, column=col, padx=5, pady=5)

    window.mainloop()

# Take the value of N as input
n = int(input("Enter the value of N: "))

# Solve the N-Queen problem for the given value of N
solution = solve_n_queen(n)
display_solution(solution)

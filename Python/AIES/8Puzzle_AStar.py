# Experiment No 1
# Author: Amaan Shaikh
# Branch: TYCSE-A
# PRN: 1032221184
# File name: 8Puzzle_AStar.py


import queue

# Define the PuzzleNode class to represent puzzle states
class PuzzleNode:
    def __init__(self, state, parent=None, move=None, g=0):
        self.state = state
        self.parent = parent
        self.move = move
        self.g = g  # Cost to reach this state
        self.h = self.calculate_heuristic()  # Heuristic value
        self.f = self.g + self.h  # Total priority value (f = g + h)

    def calculate_heuristic(self):
        # Misplaced tiles heuristic (Hamming distance)
        misplaced_tiles = sum(1 for i in range(9) if self.state[i] != i)
        return misplaced_tiles

    def __lt__(self, other):
        return self.f < other.f

# Function to get the initial puzzle state from user input
def get_input_state():
    print("Enter the initial state of the 8-puzzle (0 represents the empty tile):")
    state = []
    for _ in range(9):
        row = input().split()
        state.extend(map(int, row))
    return state

# Function to find the index of the blank tile (0) in the puzzle state
def get_blank_index(state):
    return state.index(0)

# Function to find valid moves based on the index of the blank tile
def get_valid_moves(blank_index):
    valid_moves = []
    if blank_index >= 3:
        valid_moves.append(blank_index - 3)  # Move Up
    if blank_index % 3 > 0:
        valid_moves.append(blank_index - 1)  # Move Left
    if blank_index % 3 < 2:
        valid_moves.append(blank_index + 1)  # Move Right
    if blank_index < 6:
        valid_moves.append(blank_index + 3)  # Move Down
    return valid_moves

# Function to generate a new state after a tile move
def get_new_state(state, old_blank_index, new_blank_index):
    new_state = state[:]
    new_state[old_blank_index], new_state[new_blank_index] = new_state[new_blank_index], new_state[old_blank_index]
    return new_state

# Function to solve the puzzle using A* algorithm
def solve_puzzle(initial_state):
    open_queue = queue.PriorityQueue()  # Priority queue to store nodes
    closed_set = set()  # Set to keep track of visited states

    # Convert the initial state into a PuzzleNode object and add it to the open queue
    initial_node = PuzzleNode(initial_state)
    open_queue.put(initial_node)

    goal_state = [1, 2, 3, 4, 0, 5, 6, 7, 8]  # Updated goal state

    while not open_queue.empty():
        current_node = open_queue.get()

        if current_node.state == goal_state:
            # Goal state found, reconstruct and return the solution path
            path = []
            while current_node:
                path.append(current_node.state)
                current_node = current_node.parent
            return path[::-1]  # Reverse the path to get initial to goal

        closed_set.add(tuple(current_node.state))

        blank_index = get_blank_index(current_node.state)
        valid_moves = get_valid_moves(blank_index)

        for move_index in valid_moves:
            new_state = get_new_state(current_node.state, blank_index, move_index)

            if tuple(new_state) not in closed_set:
                new_g = current_node.g + 1  # Increment the cost to reach new state
                new_node = PuzzleNode(new_state, current_node, move_index, new_g)
                open_queue.put(new_node)

    return None  # No solution found

if __name__ == "__main__":
    # Get the initial state from user input
    initial_state = get_input_state()

    # Solve the puzzle using A* algorithm
    solution = solve_puzzle(initial_state)

    if solution:
        # Print the steps to reach the goal state
        for step, state in enumerate(solution):
            print(f"Step {step}:")
            for i in range(0, 9, 3):
                print(state[i:i+3])
            print()
    else:
        print("No solution found.")

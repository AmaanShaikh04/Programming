import random

def print_board(board):
    for row in board:
        print("   |   ".join(row))
        print("-" * 18)

def check_winner(board, player):
    for row in board:
        if all(cell == player for cell in row):
            return True
    for col in range(3):
        if all(board[row][col] == player for row in range(3)):
            return True
    if all(board[i][i] == player for i in range(3)):
        return True
    if all(board[i][2-i] == player for i in range(3)):
        return True
    return False

def is_board_full(board):
    for row in board:
        for cell in row:
            if cell == " ":
                return False
    return True

def get_player_move(board):
    while True:
        try:
            row = int(input("Enter the row (1-3): ")) - 1
            col = int(input("Enter the column (1-3): ")) - 1
            if 0 <= row <= 2 and 0 <= col <= 2 and board[row][col] == " ":
                return row, col
            print("Invalid move. Try again.")
        except ValueError:
            print("Invalid input. Please enter numbers.")

def get_computer_move(board):
    while True:
        row = random.randint(0, 2)
        col = random.randint(0, 2)
        if board[row][col] == " ":
            return row, col

def main():
    board = [[" " for _ in range(3)] for _ in range(3)]
    players = ["X", "O"]
    player_turn = 0

    print("Welcome to Tic-Tac-Toe!")
    print_board(board)

    while True:
        player = players[player_turn]
        if player == "X":
            row, col = get_player_move(board)
        else:
            print("Computer's turn:")
            row, col = get_computer_move(board)

        board[row][col] = player
        print_board(board)

        if check_winner(board, player):
            print(f"{player} wins!")
            break

        if is_board_full(board):
            print("It's a tie!")
            break

        player_turn = (player_turn + 1) % 2

if __name__ == "__main__":
    main()

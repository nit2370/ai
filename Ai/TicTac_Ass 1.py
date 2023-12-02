def possible_move_gen(board, x, o):
    turn = int(input("\nWhose turn it is: "))
    pos_no = 9 - x - o
    print("Possible combinations for next move:", pos_no)
    matrix = []
    winning_combinations = [
        [0,1,2],
        [3,4,5],
        [6,7,8],
        [0,3,6],
        [1,4,7],
        [2,5,8],
        [0,4,8],
        [2,4,6]
    ]

    for i in range(9):
        if board[i] == 0:
            temp_board = board.copy()
            temp_board[i] = turn
            temp_board.append(0)
            # print(temp_board)
            # Evaluation
            for combination in winning_combinations:
                if all(temp_board[pos] == turn for pos in combination):
                    temp_board[9] = 100
                    break
                elif all(temp_board[pos] == abs(turn - 3) for pos in combination):
                    temp_board[9] = 50
                    break
                else:
                    temp_board[9] = 2 if i in [1,3,5,7] else (3 if i in [0,2,6,8] else 4)
      
            matrix.append(temp_board)
    return matrix


def checking_board(board, x, o):
    if abs(x - o) > 1:
        return -1
    num = 0
    power = len(board) - 1
    for bit in board:
        if bit == 1:
            num += (3 ** power)
        elif bit == 2:
            num += 2 * (3 ** power)
        power -= 1

    return num


board = []
x = 0
o = 0
for i in range(9):
    print(f"Enter {i}th position (1/2/0): ", end="")
    temp = int(input())
    board.append(temp)
    if temp == 1:
        x += 1
    elif temp == 2:
        o += 1

num = checking_board(board, x, o)
if num == -1:
    print("Invalid")
else:
    print(num)

next_moves = possible_move_gen(board, x, o)
for move in next_moves:
    print(*move)

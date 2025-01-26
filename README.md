# Connect 4 Game

This is a C++ implementation of the classic Connect 4 game. The game can be played by two players or a player against the computer. The goal is to connect four of your pieces horizontally, vertically, or diagonally on the game board.

## Features

- Two game modes:
  1. Player vs Player
  2. Player vs Computer
- Easy-to-use console-based interface.
- Board display updates after every move.
- Automatic win and draw detection.

## How to Play

1. At the start, the program asks you to select a game mode.
2. Players take turns choosing a column (1-7) to drop their piece ('U' for User or 'C' for Computer).
3. The piece is dropped to the lowest available row in the selected column.
4. The first player to connect four pieces in a row horizontally, vertically, or diagonally wins the game.
5. If the board is full and no player has connected four pieces, the game ends in a draw.

## Installation

1. Clone or download this repository.
2. Ensure you have a C++ compiler installed (e.g., g++, clang).
3. Compile the code using the following command:
   ```
   g++ connect4.cpp -o connect4
   ```
4. Run the program:
   ```
   ./connect4
   ```

## Code Overview

### Classes and Functions

1. **Connect4 Class**
   - Manages the game board and game logic.
   - Functions include:
     - `displayBoard()`: Displays the current state of the board.
     - `makeMove(int col, char player)`: Allows a player to drop a piece in a column.
     - `isWinningMove(char player)`: Checks if the current move leads to a win.
     - `isDraw()`: Checks if the game is a draw.

2. **playGame()**
   - Manages the flow of the game.
   - Alternates turns between players and handles input validation.

3. **main()**
   - Entry point of the program.
   - Displays a welcome message and starts the game loop.

## Example Gameplay

```
Welcome to Connect 4!
+ - - - - - - - - +
| 1 2 3 4 5 6 7 |
| = = = = = = = |
| 0 0 0 0 0 0 0 |
| 0 0 0 0 0 0 0 |
| 0 0 0 0 0 0 0 |
| 0 0 0 0 0 0 0 |
| 0 0 0 0 0 0 0 |
| 0 0 0 0 0 0 0 |
+ - - - - - - - - +
Player U, enter column (1-7): 4
...
```

## Future Enhancements

- Add a graphical user interface.
- Implement advanced AI strategies for the computer.
- Support for saving and loading games.

## License

This project is open-source and available under the MIT License.

## Author's comment 
- Used another person's repositry as the base code and made some changes and added new functions.

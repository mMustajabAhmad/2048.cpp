# 2048.cpp
2048 cpp Game
This is a simple console-based implementation of the popular 2048 game in C++. The game follows the standard rules of combining matching tiles to reach the tile with the value of 2048.

**How to Play**
1. Run the program.
2. Use the following keys to make moves:
    - Press 'a' or 'A' for leftward move.
    - Press 'd' or 'D' for rightward move.
    - Press 'w' or 'W' for upward move.
    - Press 's' or 'S' for downward move.
3. Combine tiles with the same value to reach the tile with the value of 2048.
4. The game ends when you win by reaching 2048 or lose when there are no more possible moves.

**Game Features**
- Random generation of new tiles after each move.
- Score tracking.
- Maximum score tracking (saved in "maxscore.txt").
- Total moves tracking.
- Exiting the game by pressing '0'.
- Rules and instructions displayed at the beginning.

**File Descriptions**
- 2048.cpp: Main C++ source code file containing the game logic.
- maxscore.txt: Text file to store the maximum score achieved.

**Build and Run**
To build and run the game, you need a C++ compiler. Open a terminal or command prompt, navigate to the project directory, and execute the following commands:

- g++ 2048.cpp -o 2048
- ./2048

Ensure you have a C++ compiler installed on your system.

Have fun playing 2048!

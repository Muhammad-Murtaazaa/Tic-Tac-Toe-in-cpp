# Tic-Tac-Toe Game in C++

This project is a command-line Tic-Tac-Toe game built in C++. It features both single-player (vs AI) and two-player modes, timed moves, a scoring system, and game history that records player names, scores, and results of each game to a text file.

## Features

### 1. **Single-Player Mode**
- Play against the computer (AI).
- The AI randomly chooses moves, providing a simple challenge for players.

### 2. **Two-Player Mode**
- Play against another player on the same device.
- Both players take turns making their moves.

### 3. **Timed Moves**
- Each player has a time limit of 10 seconds to make a move.
- If a player takes too long, they automatically lose the round.

### 4. **Scoring System**
- After each game, the scores for Player 1 and the AI (or Player 2 in two-player mode) are updated.
- The scores are displayed after every game, and the final score is shown before exiting the program.

### 5. **Game History**
- The game results (including player names, scores, and game outcomes) are stored in a text file (`game_history.txt`).
- The history can be viewed at any time by selecting the "View Game History" option from the main menu.

### 6. **Player Names**
- Player names are customizable. In single-player mode, Player 2 is automatically set as "AI."

### 7. **Game Tie**
- If no player wins after all slots are filled, the game is declared a tie, and the result is stored in the history.

## How to Play

1. **Run the Program**:
   Compile and run the program on a system with C++.

   ```bash
   g++ game.cpp -o game
   ./tictactoe
   ```

2. **Choose Game Mode**:
   You will be prompted to select a game mode:
   - **1**: Single-player mode (Player vs AI)
   - **2**: Two-player mode (Player 1 vs Player 2)
   - **3**: View game history

3. **Timed Moves**:
   Each player has 10 seconds to make a move. If the player does not respond within this time frame, the other player wins the round automatically.

4. **Making a Move**:
   - Choose a number from 1 to 9 corresponding to the positions on the board.
   - The board layout looks like this:

     ```
     1 | 2 | 3
     4 | 5 | 6
     7 | 8 | 9
     ```

5. **View Game History**:
   - Choose the option to view game history from the main menu to see the names, scores, and results of previously played games.

## Game Controls

- Input the slot number (1-9) to place your marker.
- The game checks for a winner after every move.
- If no winner is found and all slots are filled, the game ends in a tie.

## How It Works

- **placeMarker()**: Simplified logic to place the marker on the board based on user input.
- **timedMove()**: Implements the timer to ensure players make their moves within the time limit.
- **aiMove()**: The AI makes a random move in single-player mode.
- **File Handling**: After each game, the scores and player names are saved to `game_history.txt`. The history can be viewed anytime.
  
## Game Flow

1. Start the game by choosing a mode.
2. Players choose their markers and start placing them on the board.
3. The game checks for a winner after every move.
4. Scores are updated and saved at the end of each round.
5. The game resets for the next round, and you can choose to play again or view the final score.
6. If you choose to view the history, the game will display all previously played games, including player names, scores, and results.

## Example of Game History

```
Player 1 (Name: John) | Player 2 (Name: AI)
Final Scores: Player 1: 3 | AI: 1
Result: Player 1 Wins!
-----------------------------------
Player 1 (Name: Jane) | Player 2 (Name: AI)
Final Scores: Player 1: 2 | AI: 2
Result: It's a Tie!
-----------------------------------
```

## Requirements

- A C++ compiler (e.g., g++).
- Compatible with Unix-based systems (e.g., Linux, macOS) and Windows.

## Future Improvements

- Smarter AI using decision trees or minimax algorithm for a more challenging single-player experience.
- Graphical User Interface (GUI) to replace the command-line interface.
- Online multiplayer mode for remote gameplay.

## Author
- Muhammad Murtaza.(This project was created as part of a learning exercise in C++).

---

By following the instructions above, you should be able to compile, run, and enjoy the Tic-Tac-Toe game on your system.

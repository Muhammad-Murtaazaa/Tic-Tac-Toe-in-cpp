
#include <iostream>
#include <ctime>   // for time()
#include <cstdlib> // for rand() and srand()
#include <fstream> // for file handling
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}; // Tic-Tac-Toe board
char current_marker;
int current_player, player_score = 0, ai_score = 0;
const int time_limit = 15;  // set the time limit for each move in seconds 
string player1_name, player2_name = "AI";

// Function to display the main menu
void showMainMenu();

// Function to draw the current state of the board
void drawBoard() {
    cout << "Tic-Tac-Toe Board:\n\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    } 
    cout << endl;
}

// Function to place marker on the board
bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    // Checking if the chosen slot is occupied or not
    if (board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Slot already occupied! Try again.\n";
        return false;
    }

    // Place the marker (X/O)
    board[row][col] = current_marker;
    return true;
}

// Function to check for the winner
int winner() {
    // Check all the rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return current_player;
        }
    }
    // Check all the columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return current_player;
        }
    }
    // Check all the diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return current_player;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return current_player;
    }
    return 0;
}

// Function to swap player and marker
void swapPlayerAndMarker() {
    if (current_marker == 'X') {
        current_marker = 'O';
    } else {
        current_marker = 'X';
    }

    if (current_player == 1) {
        current_player = 2;
    } else {
        current_player = 1;
    }
}

// Function for timed moves
bool timedMove(int &slot) {
    time_t start_time = time(NULL);
    
    cout << "You have " << time_limit << " seconds to make a move: ";
    cin >> slot;
    
    time_t end_time = time(NULL);
    
    if (difftime(end_time, start_time) > time_limit) {
        cout << "Time's up! You took too long.\n";
        return false;
    }
    return true;
}

void aiMove() {
    srand(time(0));  
    int slot;
    while (true) {
        slot = rand() % 9 + 1;  // generate a random number between 1 and 9
        if (placeMarker(slot)) break;  // If valid, place the marker and break loop
    }
    cout << "AI chose slot " << slot << endl;
}

// Save scores and player names to a file
void saveToFile(string result) {
    ofstream file("game_history.txt", ios::app);
    if (file.is_open()) {
        file << "Player 1 (Name: " << player1_name << ") | Player 2 (Name: " << player2_name << ")\n";
        file << "Final Scores: Player 1: " << player_score << " | AI: " << ai_score << endl;
        file << "Result: " << result << "\n";
        file << "-----------------------------------\n";
        file.close();
    } else {
        cout << "Unable to open file to save history.\n";
    }
}

// Show the history of games from file
void showHistory() {
    ifstream file("game_history.txt");
    string line;
    if (file.is_open()) {
        cout << "Game History:\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "No game history available.\n";
    }
    cout << "\nReturning to Home...\n";
    showMainMenu();
}

// Update score after game
void updateScore(int winner) {
    string result;
    if (winner == 1) {
        player_score++;
        cout << "Player 1 wins! Congratulations!\n";
        result = "Player 1 Wins!";
    } else if (winner == 2) {
        ai_score++;
        cout << "Player 2 (AI) wins! Better luck next time!\n";
        result = "AI Wins!";
    }
    cout << "Score - Player 1: " << player_score << " | AI: " << ai_score << endl;

    saveToFile(result); // Save the game result to file
}

// Reset the board after each round
void resetBoard() {
    char init_board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = init_board[i][j];
}

// Function to display the About section
void showAbout() {
    cout << "\n--- About the Developer ---\n";
    cout << "Developer: Muhammad Murtaza\n";
    cout << "Email: muhammad.murtaazaa@gmail.com\n";
    cout << "I am a Computer Science student with a love and passion for coding. "
         << "If you're interested in collaborating on a project or building a custom solution, "
         << "feel free to contact me at the above email.\n";
    cout << "\nReturning to Home...\n";
    showMainMenu();
}

// Main game logic
void game(bool isSinglePlayer) {
    cout << "Player 1, choose your marker (X or O): ";
    char marker_p1;
    cin >> marker_p1;

    current_player = 1;
    current_marker = marker_p1;

    int player_won = 0;
    drawBoard();

    for (int i = 0; i < 9; i++) {
        int slot;

        if (current_player == 1) {
            if (!timedMove(slot)) {
                cout << "You took too long! You lose this round.\n";
                player_won = 2;
                break;
            }

            if (slot < 1 || slot > 9 || !placeMarker(slot)) {
                cout << "Invalid move! Try again.\n";
                i--;
                continue;
            }
        } else if (isSinglePlayer) {
            aiMove();
        } else {
            cout << "It's player " << current_player << "'s turn. Enter your slot: ";
            cin >> slot;
            if (slot < 1 || slot > 9 || !placeMarker(slot)) {
                cout << "Invalid move! Try again.\n";
                i--;
                continue;
            }
        }

        drawBoard();
        player_won = winner();
        if (player_won != 0) {
            updateScore(player_won);
            break;
        }
        swapPlayerAndMarker();
    }

    if (player_won == 0) {
        cout << "It's a tie!\n";
        saveToFile("It's a Tie!"); // Save the result if it’s a tie
    }

    resetBoard();
}

// Main Menu
void showMainMenu() {
    cout << "Welcome to Tic-Tac-Toe!\n";
    cout << "Developed by: Muhammad Murtaza\n";
    cout << "Choose an option:\n";
    cout << "1. Single Player (vs AI)\n";
    cout << "2. Two Player\n";
    cout << "3. View Game History\n";
    cout << "4. About\n";
    cout << "5. Exit\n";
    
    int choice;
    cin >> choice;

    if (choice == 3) {
        showHistory();  // Show game history
    } else if (choice == 4) {
        showAbout();    // Show About section
    } else if (choice == 5) {
        cout << "Exiting the game. Goodbye!\n";
        exit(0);
    } else {
        bool isSinglePlayer = (choice == 1);

        if (!isSinglePlayer) {
            cout << "Enter Player 2 name: ";
                        cin >> player2_name;
        }

        char play_again;
        do {
            game(isSinglePlayer);
            cout << "Do you want to play again? (y/n): ";
            cin >> play_again;
        } while (play_again == 'y');
        
        cout << "Final Scores - Player 1: " << player_score << " | AI: " << ai_score << endl;
        cout << "Thanks for playing!\n";
        showMainMenu();  // Return to main menu
    }
}

int main() {
    showMainMenu();  // Display the main menu
    return 0;
}

           
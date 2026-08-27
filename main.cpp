#include <iostream>
using namespace std;

char board[3][3];

// Initialize the board
void initializeBoard()
{
    char value = '1';

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = value++;
        }
    }
}

// Display the game board
void displayBoard()
{
    cout << "\n";
    cout << "-------------\n";

    for (int i = 0; i < 3; i++)
    {
        cout << "| ";

        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " | ";
        }

        cout << "\n-------------\n";
    }
}

// Check whether a player has won
bool checkWin(char player)
{
    // Rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
        {
            return true;
        }
    }

    // Columns
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == player &&
            board[1][j] == player &&
            board[2][j] == player)
        {
            return true;
        }
    }

    // Diagonals
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
    {
        return true;
    }

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
    {
        return true;
    }

    return false;
}

// Check for draw
bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] >= '1' && board[i][j] <= '9')
            {
                return false;
            }
        }
    }

    return true;
}

// Make a player's move
bool makeMove(int position, char player)
{
    if (position < 1 || position > 9)
    {
        return false;
    }

    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O')
    {
        return false;
    }

    board[row][col] = player;
    return true;
}

// Play one game
void playGame()
{
    initializeBoard();

    char currentPlayer = 'X';
    int position;

    cout << "\n===== TIC TAC TOE =====\n";

    while (true)
    {
        displayBoard();

        cout << "\nPlayer " << currentPlayer;
        cout << ", enter position (1-9): ";
        cin >> position;

        if (!makeMove(position, currentPlayer))
        {
            cout << "\nInvalid move! Try again.\n";
            continue;
        }

        if (checkWin(currentPlayer))
        {
            displayBoard();
            cout << "\nPlayer " << currentPlayer << " wins!\n";
            break;
        }

        if (checkDraw())
        {
            displayBoard();
            cout << "\nIt's a draw!\n";
            break;
        }

        // Switch player
        if (currentPlayer == 'X')
            currentPlayer = 'O';
        else
            currentPlayer = 'X';
    }
}

int main()
{
    char replay;

    do
    {
        playGame();

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> replay;

    } while (replay == 'Y' || replay == 'y');

    cout << "\nThanks for playing Tic Tac Toe!\n";

    return 0;
}
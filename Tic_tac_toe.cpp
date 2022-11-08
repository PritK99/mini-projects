// This program aims at creating a tic tac toe game
#include <iostream>

using namespace std;

bool tie_flag = 0;
bool game_is_still_possible = 0 ;

void show_board(char board[3][3])
{
    // This code simply displays the board and current status
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool check(char board[3][3])
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                game_is_still_possible = 1 ;
                break ;
            }
        }
        if (game_is_still_possible == 1)
        {
            break ;
        }
    }
    if (game_is_still_possible == 0)
    {
        tie_flag == 1 ;
    }

    if (((board[0][0] == board[0][1]) && (board[0][1] == board[0][2])) || ((board[1][0] == board[1][1]) && (board[1][1] == board[1][2])) || ((board[2][0] == board[2][1]) && (board[2][1] == board[2][2]))) // This checks row wise
    {
        return true;
    }
    else if (((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) || ((board[2][0] == board[1][1]) && (board[1][1] == board[0][2]))) // this checks the diagonals
    {
        return true;
    }
    else if (((board[0][0] == board[1][0]) && (board[1][0] == board[2][0])) || ((board[0][1] == board[1][1]) && (board[1][1] == board[2][1])) || ((board[0][2] == board[1][2]) && (board[1][2] == board[2][2]))) // this checks the coloumns
    {
        return true;
    }
    else
    {
        return false;
    }
}

void call_user(int user, char board[3][3])
{
    int row, col;
    do
    {
        cout << "Please enter the row where you wish to play : ";
        cin >> row;
        cout << "Please enter the column where you wish to play : ";
        cin >> col;
    } while (board[row - 1][col - 1] == 'X' || board[row - 1][col - 1] == 'O' || row < 1 || row > 3 || col < 1 || col > 3); // Keep prompting the user if the input is invalid

    if (user == 1)
    {
        // giving X for the first user and O for the second user
        board[row - 1][col - 1] = 'X';
    }
    else
    {
        board[row - 1][col - 1] = 'O';
    }

    /*Checking the tie condition*/
    if (tie_flag == 1)
    {
        cout << "game ends as tie" << endl;
        exit(0);
    }

    /*Checking if a user won*/
    if (check(board))
    {
        show_board(board);
        cout << "user" << user << " wins the game" << endl;
        exit(0);
    }
}

int main()
{
    int user;
    char board[3][3] = {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}};

    while (1)
    {
        user = 1;
        call_user(user, board);
        show_board(board);
        user = 2;
        call_user(user, board);
        show_board(board);
    }
    return 0;
}

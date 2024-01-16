#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <ctime>
#include <string>
using namespace std;
int matrix[4][4];
void board();
void mainFunction();
void mainDisplay();
bool win();
bool gameOverCheck();
void randomgeneration();
void upward();
void downward();
void leftward();
void rightward();
void initializeArray();
int score = 0, maximumScore, totalmoves = 0;
bool gameLost = 0;
int main()
{
    mainFunction();
    system("pause");
    return 0;
}
void mainFunction()
{
    int row, col;
    int result, result1;
    char ch;
    while (true)
    {
        cout << "Rules for game are as follows:" << endl;
        cout << "Press a/A for left move" << endl;
        cout << "Press d/D for right move" << endl;
        cout << "Press w/W for up move" << endl;
        cout << "Press s/S for down move" << endl;
        cout << "\n!!!Press 1 to play 2048 game and 0 to exit!!!" << endl;
        cin >> ch;

        if (ch == '0')
        {
            break; // Exit the loop and end the program
        }
        else if (ch != '1')
        {
            cout << "Make a valid choice" << endl;
            continue;
        }

        initializeArray();
        for (int i = 1; i < 3; i++)
        {
            row = rand() % 4;
            col = rand() % 4;
            matrix[row][col] = 2;
        }
        board();

        while (true)
        {
            string move;
            cin >> move;

            if (move != "a" && move != "A" && move != "s" && move != "S" && move != "w" && move != "W" && move != "d" && move != "D")
            {
                cout << "Play with A,S,D,W as mentioned" << endl;
                cin.get();
                continue;
            }

            char c = move[0];
            switch (c)
            {
                case 'a':
                case 'A':
                    leftward();
                    break;
                case 's':
                case 'S':
                    downward();
                    break;
                case 'w':
                case 'W':
                    upward();
                    break;
                case 'd':
                case 'D':
                    rightward();
                    break;
                default:
                    board();
                    break;
            }

            result = win();
            result1 = gameOverCheck();
            if (result == 1 || result1 == 1)
            {
                gameLost = 1;
                break; // Exit the loop if the game is lost
            }
        }

        ofstream output;
        if (result == 1)
        {
            cout << "Congratulations! You win the game!" << endl;
        }
        else if (result1 == 1)
        {
            cout << "You lost the game! Better luck next time" << endl;
        }

        if (score > maximumScore)
        {
            output.open("maximumScore.txt");
            maximumScore = score;
            output << maximumScore;
            output.close();
        }

        if (totalmoves >= 131038)
        {
            cout << "You lose the game because of total moves:" << endl;
        }

        gameLost = 0;
        totalmoves = 0;
        score = 0;
        system("pause");
        system("cls");
    }
}
void initializeArray()
{
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 3; j++)
            matrix[i][j] = 0;
    }
}


void board()
{
    system("cls");
    mainDisplay();
    for (int row = 0; row <= 3; row++)
    {
        for (int col = 0; col <= 3; col++)
        {
            if (matrix[row][col] == 0)
            {
                cout << "|       |";
            }
            else if (matrix[row][col] <= 9)
                cout << "|" << setw(4) << matrix[row][col] << setw(4) << "|";
            else if (matrix[row][col] <= 99)
                cout << "|" << setw(4) << matrix[row][col] << setw(4) << "|";
            else if (matrix[row][col] <= 999)
                cout << "|" << setw(4) << matrix[row][col] << setw(4) << "|";
            else if (matrix[row][col] <= 9999)
                cout << "|" << setw(4) << matrix[row][col] << setw(4) << "|";
            else
                cout << "|  " << matrix[row][col] << "  |";
        }
        cout << endl;
    }
}
void mainDisplay()
{
    ifstream in;
    cout << setw(10) << "THE 2048 GAMEEEE" << endl;
    cout << "The maximum score =" << maximumScore << endl;
    cout << "Your score is =" << score << endl;
    cout << "Your move are =" << totalmoves << " moves" << endl;
    cout << "Your remainig moves are = " << (131038 - totalmoves) << endl;
    cout << "Directions are:  W/w=UP, S/s=DOWN, A/a=LEFT, D=RIGHT" << endl;
    cout << "\n\n\n\n";
    in.open("maxscore.txt");
    in >> maximumScore;
}

bool win()
{
    bool result = 0;
    for (int row = 0; row <= 3; row++)
    {
        for (int col = 0; col <= 3; col++)
        {
            if (matrix[row][col] == 2048)
            {
                result = 1;
                break;
            }
        }
        if (result == 1)
            break;
    }
    return result;
}
void randomgeneration()
{
    if (totalmoves < 131038)
    {
        bool tilePlaced = false;

        while (!tilePlaced) 
        {
            int row = rand() % 4;
            int col = rand() % 4;

            if (matrix[row][col] == 0)
            {
                matrix[row][col] = 2;
                tilePlaced = true; 
            }
        }
    }
    else
    {
        gameLost = true;
    }
}

void upward()
{
    bool validMove = false;

    // Check if upward move is possible
    for (int col = 0; col <= 3; col++)
    {
        for (int row = 1; row <= 3; row++)
        {
            if (matrix[row][col] != 0 && (matrix[row - 1][col] == 0 || matrix[row][col] == matrix[row - 1][col]))
            {
                validMove = true;
                break;
            }
        }
        if (validMove)
            break;
    }

    if (!validMove)
    {
        cout << "Invalid move! Please try again." << endl;
        return;
    }

    for (int col = 0; col <= 3; col++)
    {
        for (int row = 1; row <= 3; row++)
        {
            if (matrix[row][col] != 0)
            {
                int prevRow = row - 1;

                while (prevRow >= 0 && matrix[prevRow][col] == 0)
                {
                    prevRow--;
                }

                if (prevRow >= 0 && matrix[row][col] == matrix[prevRow][col])
                {
                    matrix[prevRow][col] *= 2;
                    matrix[row][col] = 0;
                    score += matrix[prevRow][col];
                }
            }
        }

        for (int row = 3; row >= 0; row--)
        {
            if (matrix[row][col] == 0)
            {
                int nextRow = row + 1;

                while (nextRow <= 3 && matrix[nextRow][col] == 0)
                {
                    nextRow++;
                }

                if (nextRow <= 3)
                {
                    matrix[row][col] = matrix[nextRow][col];
                    matrix[nextRow][col] = 0;
                }
            }
        }
    }

    randomgeneration();
    totalmoves++;
    board();
}

void downward()
{
    bool validMove = false;

    for (int col = 0; col < 4; col++)
    {
        for (int row = 3; row > 0; row--)
        {
            if (matrix[row][col] != 0 && (matrix[row - 1][col] == 0 || matrix[row][col] == matrix[row - 1][col]))
            {
                validMove = true;
                break;
            }
        }
        if (validMove)
            break;
    }

    if (!validMove)
    {
        cout << "Invalid move! Please try again." << endl;
        return;
    }

    for (int col = 0; col < 4; col++)
    {
        for (int row = 3; row > 0; row--)
        {
            if (matrix[row][col] == matrix[row - 1][col] && matrix[row][col] != 0)
            {
                matrix[row][col] *= 2;
                matrix[row - 1][col] = 0;
                score += matrix[row][col];
            }
            else if (matrix[row][col] == 0 && matrix[row - 1][col] != 0)
            {
                matrix[row][col] = matrix[row - 1][col];
                matrix[row - 1][col] = 0;
                row = 4;
            }
        }
    }
    randomgeneration();
    totalmoves++;
    board();
}

void leftward()
{
    bool validMove = false;

    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (matrix[row][col] != 0 && (matrix[row][col + 1] == 0 || matrix[row][col] == matrix[row][col + 1]))
            {
                validMove = true;
                break;
            }
        }
        if (validMove)
            break;
    }

    if (!validMove)
    {
        cout << "Invalid move! Please try again." << endl;
        return;
    }

    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (matrix[row][col] == matrix[row][col + 1] && matrix[row][col] != 0)
            {
                matrix[row][col] *= 2;
                matrix[row][col + 1] = 0;
                score += matrix[row][col];
            }
            else if (matrix[row][col] == 0 && matrix[row][col + 1] != 0)
            {
                matrix[row][col] = matrix[row][col + 1];
                matrix[row][col + 1] = 0;
                col = -1;
            }
        }
    }
    randomgeneration();
    totalmoves++;
    board();
}

void rightward()
{
    bool validMove = false;

    // Check if rightward move is possible
    for (int row = 0; row < 4; row++)
    {
        for (int col = 3; col > 0; col--)
        {
            if (matrix[row][col] != 0 && (matrix[row][col - 1] == 0 || matrix[row][col] == matrix[row][col - 1]))
            {
                validMove = true;
                break;
            }
        }
        if (validMove)
            break;
    }

    if (!validMove)
    {
        cout << "Invalid move! Please try again." << endl;
        return;
    }

    for (int row = 0; row < 4; row++)
    {
        for (int col = 3; col > 0; col--)
        {
            if (matrix[row][col] == matrix[row][col - 1] && matrix[row][col] != 0)
            {
                matrix[row][col] *= 2;
                matrix[row][col - 1] = 0;
                score += matrix[row][col];
            }
            else if (matrix[row][col] == 0 && matrix[row][col - 1] != 0)
            {
                matrix[row][col] = matrix[row][col - 1];
                matrix[row][col - 1] = 0;
                col = 4;
            }
        }
    }
    randomgeneration();
    totalmoves++;
    board();
}
bool gameOverCheck();

bool gameOverCheck()
{
    // Check for possible moves
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            // Check right neighbor
            if (col < 3 && (matrix[row][col] == matrix[row][col + 1] || matrix[row][col + 1] == 0))
            {
                return false; // If there's a matching tile on the right or an empty tile, the game is not over
            }

            // Check bottom neighbor
            if (row < 3 && (matrix[row][col] == matrix[row + 1][col] || matrix[row + 1][col] == 0))
            {
                return false; // If there's a matching tile below or an empty tile, the game is not over
            }
        }
    }

    // If no possible moves, the game is over
    return true;
}




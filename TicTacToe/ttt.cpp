#include <iostream>
using namespace std;

void user_move(int board[], int v)
{
    int s;
    while (1)
    {
        cout << "Enter square: ";
        cin >> s;

        if (board[s] == 2)
        {
            board[s] = v;
            break;
            ;
        }
        else
            cout << "Square already filled.\n";
    }
}

int Make2(int board[])
{
    if (board[5] == 2)
        return 5;
    else if (board[2] == 2)
        return 2;
    else if (board[4] == 2)
        return 4;
    else if (board[6] == 2)
        return 6;

    return 8;
}

int Go(int board[], int n, int turn)
{
    if (turn % 2 == 1)
        board[n] = 3;
    else
        board[n] = 5;

    return turn + 1;
}

int blank(int board[])
{
    int i = 1;
    for (; i <= 9; i++)
    {
        if (board[i] == 2)
            break;
    }

    return i;
}

int Posswin(int board[], int v)
{
    for (int i = 1; i < 9; i = i + 3)
    {
        if (board[i] * board[i + 1] * board[i + 2] == 18 && v == 3)
        {
            if (board[i] == 2)
                return i;
            else if (board[i + 1] == 2)
                return i + 1;
            else
                return i + 2;
        }
        else if (board[i] * board[i + 1] * board[i + 2] == 50 && v == 5)
        {
            if (board[i] == 2)
                return i;
            else if (board[i + 1] == 2)
                return i + 1;
            else
                return i + 2;
        }
    }

    for (int i = 1; i < 4; i++)
    {
        if (board[i] * board[i + 3] * board[i + 6] == 18 && v == 3)
        {
            if (board[i] == 2)
                return i;
            else if (board[i + 3] == 2)
                return i + 3;
            else
                return i + 6;
        }
        else if (board[i] * board[i + 3] * board[i + 6] == 50 && v == 5)
        {
            if (board[i] == 2)
                return i;
            else if (board[i + 3] == 2)
                return i + 3;
            else
                return i + 6;
        }
    }

    if (board[1] * board[5] * board[9] == 18 && v == 3)
    {
        if (board[1] == 2)
            return 1;
        else if (board[5] == 2)
            return 5;
        else
            return 9;
    }
    else if (board[1] * board[5] * board[9] == 50 && v == 5)
    {
        if (board[1] == 2)
            return 1;
        else if (board[5] == 2)
            return 5;
        else
            return 9;
    }

    if (board[3] * board[5] * board[7] == 18 && v == 3)
    {
        if (board[3] == 2)
            return 3;
        else if (board[5] == 2)
            return 5;
        else
            return 7;
    }
    else if (board[3] * board[5] * board[7] == 50 && v == 5)
    {
        if (board[3] == 2)
            return 3;
        else if (board[5] == 2)
            return 5;
        else
            return 7;
    }

    return 0;
}

void comp_move(int board[], int turn, int v)
{
    switch (turn)
    {
    case 1:
        turn = Go(board, 1, turn);
        break;

    case 2:
        if (board[5] == 2)
            turn = Go(board, 5, turn);
        else
            turn = Go(board, 1, turn);
        break;

    case 3:
        if (board[9] == 2)
            turn = Go(board, 9, turn);
        else
            turn = Go(board, 3, turn);
        break;

    case 4:
        if (Posswin(board, 3) != 0)
            turn = Go(board, Posswin(board, 3), turn);
        else
            turn = Go(board, Make2(board), turn);
        break;

    case 5:
        if (Posswin(board, 3) != 0)
            turn = Go(board, Posswin(board, 3), turn);
        else if (Posswin(board, 5) != 0)
            turn = Go(board, Posswin(board, 5), turn);
        else if (board[7] == 2)
            turn = Go(board, 7, turn);
        else
            turn = Go(board, 3, turn);
        break;

    case 6:
        if (Posswin(board, 5) != 0)
            turn = Go(board, Posswin(board, 5), turn);
        else if (Posswin(board, 3) != 0)
            turn = Go(board, Posswin(board, 3), turn);
        else
            turn = Go(board, Make2(board), turn);
        break;

    case 7:
        if (Posswin(board, 3) != 0)
            turn = Go(board, Posswin(board, 3), turn);
        else if (Posswin(board, 5) != 0)
            turn = Go(board, Posswin(board, 5), turn);
        else
            turn = Go(board, blank(board), turn);
        break;

    case 8:
        if (Posswin(board, 5) != 0)
            turn = Go(board, Posswin(board, 5), turn);
        else if (Posswin(board, 3) != 0)
            turn = Go(board, Posswin(board, 3), turn);
        else
            turn = Go(board, blank(board), turn);
        break;

    case 9:
        if (Posswin(board, 3) != 0)
            turn = Go(board, Posswin(board, 3), turn);
        else if (Posswin(board, 5) != 0)
            turn = Go(board, Posswin(board, 5), turn);
        else
            turn = Go(board, blank(board), turn);
        break;

    default:
        break;
    }
}

bool Checkwin(int board[], int v)
{
    for (int i = 1; i < 9; i = i + 3)
    {
        if (board[i] == 3 && board[i + 1] == 3 && board[i + 2] == 3 && v == 3)
            return true;
        else if (board[i] == 5 && board[i + 1] == 5 && board[i + 2] == 5 && v == 5)
            return true;
    }

    for (int i = 1; i < 4; i++)
    {
        if (board[i] == 3 && board[i + 3] == 3 && board[i + 6] == 3 && v == 3)
            return true;
        else if (board[i] == 5 && board[i + 3] == 5 && board[i + 6] == 5 && v == 5)
            return true;
    }

    if (board[1] == 3 && board[5] == 3 && board[9] == 3 && v == 3)
        return true;
    else if (board[1] == 5 && board[5] == 5 && board[9] == 5 && v == 5)
        return true;

    if (board[3] == 3 && board[5] == 3 && board[7] == 3 && v == 3)
        return true;
    else if (board[3] == 5 && board[5] == 5 && board[7] == 5 && v == 5)
        return true;

    return false;
}

void display(int board[])
{
    for (int i = 1; i <= 9; i++)
    {
        if (i == 3 || i == 6)
        {
            if (board[i] == 2)
                cout << " \n";
            else if (board[i] == 3)
                cout << "x\n";
            else
                cout << "o\n";

            cout << "---------\n";
        }
        else if (i == 9)
        {
            if (board[i] == 2)
                cout << " \n";
            else if (board[i] == 3)
                cout << "x\n";
            else
                cout << "o\n";
        }
        else
        {
            if (board[i] == 2)
                cout << "  | ";
            else if (board[i] == 3)
                cout << "x | ";
            else
                cout << "o | ";
        }
    }
}

int main()
{
    int board[10] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}, turn = 1;
    char firstMove;

    cout << "Do you want to play first(y/n): ";
    cin >> firstMove;

    if (firstMove == 'y' || firstMove == 'Y')
    {
        // User goes first
        while (turn <= 9)
        {
            user_move(board, 3);
            display(board);
            if (Checkwin(board, 3))
            {
                cout << "User wins!!!\n";
                return 0;
            }
            turn++;

            if (turn > 9)
                break;

            comp_move(board, turn, 5);
            display(board);
            if (Checkwin(board, 5))
            {
                cout << "Computer wins!!!\n";
                return 0;
            }
            turn++;
        }
    }
    else
    {
        // Computer goes first
        while (turn <= 9)
        {
            comp_move(board, turn, 5);
            display(board);
            if (Checkwin(board, 5))
            {
                cout << "Computer wins!!!\n";
                return 0;
            }
            turn++;

            if (turn > 9)
                break; // Check for draw after computer move

            user_move(board, 3);
            display(board);
            if (Checkwin(board, 3))
            {
                cout << "User wins!!!\n";
                return 0;
            }
            turn++;
        }
    }

    cout << "Draw!!!\n";
    return 0;
}

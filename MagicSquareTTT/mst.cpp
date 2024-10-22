#include <iostream>
using namespace std;

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

int Posswin(int board[], int v)
{
    int magic[10] = {0, 8, 3, 4, 1, 5, 9, 6, 7, 2};
    int indexMagic[10] = {0, 4, 9, 2, 3, 5, 7, 8, 1, 6};
    for (int i = 1; i <= 9; i++)
    {
        if (board[i] == v)
        {
            for (int j = i + 1; j <= 9; j++)
            {
                if (board[j] == v)
                {
                    int k = 15 - (magic[i] + magic[j]);
                    if (k > 0 && k < 10 && board[indexMagic[k]] == 2)
                        return indexMagic[k];
                }
            }
        }
    }

    return 0;
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

int main()
{
    int board[10] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}, turn = 1, flag = 0;
    char firstMove;

    cout << "Do you want to play first(y/n): ";
    cin >> firstMove;

    if (firstMove == 'y')
    {
        while (turn < 9)
        {
            user_move(board, 3);
            turn++;
            display(board);
            if (Checkwin(board, 3))
            {
                cout << "User wins!!!\n";
                flag = 1;
                break;
            }

            comp_move(board, turn, 5);
            turn++;
            display(board);
            if (Checkwin(board, 5))
            {
                cout << "Computer wins!!!\n";
                flag = 1;
                break;
            }
        }

        if (!flag)
            cout << "Draw!!!\n";
    }
    else
    {
        while (turn < 9)
        {
            comp_move(board, turn, 3);
            turn++;
            display(board);
            if (Checkwin(board, 3))
            {
                cout << "Computer wins!!!\n";
                flag = 1;
                break;
            }

            user_move(board, 5);
            turn++;
            display(board);
            if (Checkwin(board, 5))
            {
                cout << "User wins!!!\n";
                flag = 1;
                break;
            }
        }

        if (!flag)
        {
            Go(board, blank(board), 9);
            display(board);
            cout << "Draw!!!\n";
        }
    }

    return 0;
}
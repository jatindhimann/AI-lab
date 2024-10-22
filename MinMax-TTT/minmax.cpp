#include <iostream>
#include <vector>
using namespace std;

int MAX_DEPTH = 4;

void display(vector<int> board)
{
    char arr[10];
    for (int i = 1; i <= 9; i++)
    {
        if (board[i] == 2)
            arr[i] = '_';
        else if (board[i] == 5)
            arr[i] = 'o';
        else
            arr[i] = 'x';
    }
    cout
        << arr[1] << "  " << arr[2] << "  " << arr[3] << endl
        << arr[4] << "  " << arr[5] << "  " << arr[6] << endl
        << arr[7] << "  " << arr[8] << "  " << arr[9] << endl;
    cout << endl;
}
int check(char ch, vector<int> board)
{
    int winProduct;
    if (ch == 'o')
        winProduct = 125;
    else
        winProduct = 27;

    int i = 1, j = 2, k = 3;
    // for three rows
    while (i <= 7)
    {
        if (board[i] * board[j] * board[k] == winProduct)
            return winProduct;

        i += 3;
        j += 3;
        k += 3;
    }
    i = 1;
    j = 4;
    k = 7;
    // for three columns
    while (i <= 3)
    {
        if (board[i] * board[j] * board[k] == winProduct)
            return winProduct;

        i += 1;
        j += 1;
        k += 1;
    }
    // for two diagonals
    if (board[1] * board[5] * board[9] == winProduct)
        return winProduct;
    if (board[3] * board[5] * board[7] == winProduct)
        return winProduct;

    return 0;
}
vector<int> makeBoard(vector<int> board, int move, char ch)
{
    if (ch == 'x')
        board[move] = 3;
    else if (ch == 'o')
        board[move] = 5;

    return board;
}
vector<int> moveGenerator(vector<int> board)
{
    vector<int> emptyPlaces;
    for (int i = 1; i <= 9; i++)
    {
        if (board[i] == 2)
            emptyPlaces.push_back(i);
    }

    return emptyPlaces;
}
int rating(vector<int> board)
{

    int i = 1, j = 2, k = 3;
    while (i <= 7)
    {
        if (board[i] == board[j] && board[j] == board[k])
        {
            if (board[i] == 3)
                return 10;
            else if (board[i] == 5)
                return -10;
        }
        i += 3;
        j += 3;
        k += 3;
    }
    // for three columns
    i = 1, j = 4, k = 7;
    while (i <= 3)
    {
        if (board[i] == board[j] && board[j] == board[k])
        {
            if (board[i] == 3)
                return 10;
            else if (board[i] == 5)
                return -10;
        }
        i += 1;
        j += 1;
        k += 1;
    }
    if (board[1] == board[5] && board[5] == board[9])
    {
        if (board[1] == 3)
            return 10;
        else if (board[1] == 5)
            return -10;
    }

    if (board[3] == board[5] && board[5] == board[7])
    {
        if (board[3] == 3)
            return 10;
        else if (board[3] == 5)
            return -10;
    }
    int rating = 0;
    for (int i = 1; i <= 9; i++)
    {
        if (i == 5)
        {
            if (board[i] == 3)
                rating += 5;
            else if (board[i] == 5)
                rating -= 5;
            continue;
        }

        if (i == 1 || i == 3 || i == 7 || i == 9)
        {
            if (board[i] == 3)
                rating += 3;
            else if (board[i] == 5)
                rating -= 3;
            continue;
        }
        if (i == 2 || i == 4 || i == 6 || i == 8)
        {
            if (board[i] == 3)
                rating += 1;
            else if (board[i] == 5)
                rating -= 1;
        }
    }

    return rating;
}
int minimax(vector<int> board, int depth, bool isMax)
{
    int currRating = rating(board);

    if (currRating == 10)
        return currRating;

    if (currRating == -10)
        return currRating;

    if (moveGenerator(board).empty() || depth == MAX_DEPTH)
        return 0;

    vector<int> succ = moveGenerator(board);
    int bestRating;

    if (isMax)
    {
        // computer's turn
        bestRating = -100;
        for (auto x : succ)
        {
            board[x] = 3; // making move
            int curr = minimax(board, depth + 1, !isMax);
            board[x] = 2; // undoing the move

            if (curr > bestRating)
                bestRating = curr;
        } 
    }
    else
    {
        bestRating = 100;
        for (auto x : succ)
        {
            board[x] = 5;
            int curr = minimax(board, depth + 1, !isMax);
            board[x] = 2;
            if (curr < bestRating)
                bestRating = curr;
        }
    }
    return bestRating;
}
int bestMove(vector<int> board)
{
    int best, bestRating = -100;
    vector<int> succ = moveGenerator(board);

    for (auto x : succ)
    {
        board[x] = 3;
        int moveVal = minimax(board, 0, false);
        board[x] = 2;
        if (moveVal > bestRating)
        {
            best = x;
            bestRating = moveVal;
        }
    }
    return best;
}
vector<int> computerMove(vector<int> board)
{
    int move = bestMove(board);
    return makeBoard(board, move, 'x');
}
vector<int> userMove(vector<int> board)
{
    cout << "choose position - ";
    int move;
    cin >> move;

    if (board[move] != 2)
    {
        cout << "Invalid move :(" << endl;
        return userMove(board);
    }

    return makeBoard(board, move, 'o');
}
int main()
{

    vector<int> board = {0, 2, 2, 2, 2, 2, 2, 2, 2, 2};

    char ch;
    cout << "TIC TAC TOE" << endl
         << "COMPUTER - x\nUSER - o" << endl;
    cout << "Depth - 4" << endl;
    cout << "Do you want to play first? y/n" << endl;
    cin >> ch;

    display(board);
    int turn = 1;
    if (ch == 'y')
    {
        while (turn <= 9 && !check('o', board) && !check('x', board))
        {
            // user playes first
            board = userMove(board);
            cout << "turn - " << turn << " (user)" << endl;
            display(board);
            turn++;

            if (check('o', board) == 125)
                break;

            if (turn == 10)
                break;

            board = computerMove(board);
            cout << "turn - " << turn << " (computer)" << endl;
            display(board);
            turn++;

            if (check('x', board) == 27)
                break;
        }
    }
    else
    {
        while (turn <= 9 && !check('o', board) && !check('x', board))
        {
            // computer plays first
            board = computerMove(board);
            cout << "turn - " << turn << " (computer)" << endl;
            display(board);
            turn++;

            if (check('x', board) == 27)
                break;

            if (turn == 10)
                break;

            board = userMove(board);
            cout << "turn - " << turn << " (user)" << endl;
            display(board);
            turn++;

            if (check('o', board) == 125)
                break;
        }
    }
    if (check('o', board) == 125)
        cout << "-----User wins-----" << endl;
    else if (check('x', board) == 27)
        cout << "-----Computer wins-----" << endl;
    else
        cout << "-----DRAW-----" << endl;
}
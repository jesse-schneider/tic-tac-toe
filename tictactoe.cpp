#include <cstdlib>
#include <cctype>
#include <iostream>

using namespace std;

void playGame(int count, int win, int humanSelect, char board[]);
int checkForWin(char board[]);
void printBoard(char board[]);
void computerMove(int *count, char *board);
int checkDiagonal(int *computer, int mod, char *board);
int checkRowD(int *lastMove, char *board);
int checkCol(int *lastMove, char *board);
void reset(int *count, int *win, int *humanSelect, char *board);

int main()
{
   char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
   int count = 9;
   int win = 0;
   int humanSelect = 0;
   string yesNo = "Y";

   while(yesNo == "Y" || yesNo == "Yes" || yesNo == "y")
   {
       reset(&count, &win, &humanSelect, board);
       playGame(count, win, humanSelect, board);
       cout << "do you wish to play again? Y/N" << endl;
       cin >> yesNo;
   } 
    cout << "Thank you for playing!" << endl;
    return EXIT_SUCCESS;  
}

void computerMove(int *count, int *lastMove, char *board)
{
    bool moveMade = false;
    while(moveMade == false)
    {
        if (*lastMove % 2 == 1 && *lastMove != 5)
        {
            switch(*lastMove) {
                case 1:
                    checkRowD(lastMove, board);
                    checkCol(lastMove, board);
                    checkDiagonal(lastMove, 4, board);
                    break;
                case 3:
                    checkRowD(lastMove, board);
                    checkCol(lastMove, board);
                    checkDiagonal(lastMove, 2, board);   
                    break;
                case 7:
                    checkRowD(lastMove, board);
                    checkCol(lastMove, board);
                    checkDiagonal(lastMove, 2, board);   
                    break;
                case 9:
                    checkRowD(lastMove, board);
                    checkCol(lastMove, board);
                    checkDiagonal(lastMove, 4, board);
                    break;
            }   
        }
        else if (*lastMove % 2 == 0)
        {
            switch(*lastMove) {
                case 2:
                    checkCol(lastMove, board);
                    break;
                case 4:
                    checkCol(lastMove, board);
                    break;
                    case 6:
                    checkCol(lastMove, board);
                    break;
                case 8:
                    checkCol(lastMove, board);
                    break;
            }
        }

        if(board[*lastMove] == 'X' || board[*lastMove] == 'O')
        {
            for(int i = 0; i < 9; i++)
            {
                if(isdigit((board[i])) != 0)
                {
                    *lastMove = i;
                }
            }
        }

        board[*lastMove] = 'X';
        moveMade = true;
        *count-= 1;
    }
}

void printBoard(char board[])
{
      for(int i = 0; i < 9; i+=3)
       {
           cout << board[i] << board[i+1] << board[i+2] << endl;
       }
}

void playGame(int count, int win, int humanSelect, char board[])
{
    while(count > 0 && win < 1)
   {
       cout << "Enter your position: ";
       cin >> humanSelect;
       if(board[humanSelect-1] == 'X')
       {
           cout << endl << "That position is already taken! Try again..." << endl << endl;
           printBoard(board);
           continue;
       }          
       board[humanSelect-1] = 'O';
       count--;
  
        win = checkForWin(board);
        if(win > 1)
        {
           break;
        }
        if(count == 0)
        {
           break;
        } 
        computerMove(&count, &humanSelect, board);
        printBoard(board);
        win = checkForWin(board);
        if(win > 1)
        {
           break;
        }
       cout << "win: " << win << " count: " << count << endl;
    }
        if(win == 1)
        {
            cout <<endl << "Computer wins!" << endl;
            printBoard(board);
        }
        else if(win == 2)
        {
            cout <<endl << "You win!" << endl;
            printBoard(board);
        }
        else 
        {
            cout << "No winner from that game" << endl;
            printBoard(board);
        }
}

int checkForWin(char board[])
{
    int win;
    char c;
    if(board[0] == board[1] && board[1] == board[2] 
    || board[0] == board[3] && board[3] == board[6] 
    || board[0] == board[4] && board[4] == board[8])
    {
        c = board[0];
        win = 1;
    }
    else if(board[1] == board[4] && board[4] == board[7]
     || board[2] == board[4] && board[4] == board[6])
    {
        c = board[4];
        win = 1;
    }
    else if(board[2] == board[5] && board[5] == board[8]
     || board[3] == board[4] && board[4] == board[5])
    {
        c = board[5];
        win = 1;
    }
    else if(board[6] == board[7] && board[7] == board[8])
    {
        c = board[6];
        win = 1;
    }
    else 
    {
        win = 0;
    }
    if(c == 'X')
    {
        win = 1;
    }
    else if (c == 'O')
    {
        win = 2;
    }
    return win;
}

void reset(int *count, int *win, int *humanSelect, char *board)
{
    *count = 9;
    *win = 0;
    *humanSelect = 0;
    char newBoard[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for(int i = 0; i < 9; i++)
        board[i] = newBoard[i];
}

int checkDiagonal(int *computer, int mod, char *board)
{
    int diag = *computer - 1;
            while(diag < 9)
            {
                if(diag % mod == 0 && board[diag] == 'O')
                {
                    if(*computer < 5)
                    {
                        *computer = diag + mod;
                    }
                    else 
                    {
                        *computer = diag - mod;
                    }   
                }
                diag++;
            }
            return *computer;
}

int checkRowD(int *computer, char *board)
{
    int row = *computer - 1;
    int counter = 0;
    switch(row % 6){
        case 0:
        if(board[row+1] == 'O')
        {
            *computer = row + 2;

        }
        else if(board[row+2] == 'O')
        {
            *computer = row + 1;
        }
        default:
        if(board[row-1] == 'O')
        {
            *computer = row - 2;

        }
        else if(board[row-2] == 'O')
        {
            *computer = row - 1;
        }
    }
    return *computer;
}

int checkCol(int *computer, char *board)
{
    int col = *computer - 1;
    if(col < 3)
    {
        if(board[col+3] == 'O' || board[col+6] == 'O')
        {
            if(isdigit(board[col+3]) != 0)
            {
                *computer = col + 3;
            }
            else if(isdigit(board[col+6]) != 0)
            {
                *computer = col + 6;
            }
        }
        return *computer;
    }
    else if (col < 6)
    {
        if(board[col+3] == 'O' || board[col-3] == 'O')
        {
            if(isdigit(board[col+3]) != 0)
            {
                *computer = col + 3;
            }
            else if(isdigit(board[col-3]) != 0)
            {
                *computer = col - 3;
            }
        }
        return *computer;

    } else if(col < 9)
    {
        if(board[col-3] == 'O' || board[col-6] == 'O')
        {
            if(isdigit(board[col-3]) != 0)
            {
                *computer = col - 3;
            }
            else if(isdigit(board[col-6]) != 0)
            {
                *computer = col - 6;
            }
        }
        return *computer;
    }
}
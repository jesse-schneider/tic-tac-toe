#include <cstdlib>
#include <iostream>

using namespace std;

void playGame(int count, int win, int humanSelect, char board[]);
int checkForWin(char board[]);
void printBoard(char board[]);
void computerMove(int *count, char *board);
void reset(int *count, int *win, int *humanSelect, char *board);

int main()
{
   char board[9] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
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

int checkForWin(char board[])
{
    int win;
 
    if(board[0] == board[1] && board[1] == board[2])
    {
        if (board[0] == '-')
        {
            return win = 0;
        }
        win = 1;
    }
    else if(board[0] == board[3] && board[3] == board[6])
    {
        if (board[0] == '-')
        {
            return win = 0;
        }
        win = 1;
    }
    else if(board[0] == board[4] && board[4] == board[8])
    {
        if (board[0] == '-')
        {
            return win = 0;
        }
        win = 1;
    }
    else if(board[1] == board[4] && board[4] == board[7])
    {
        if (board[1] == '-')
        {
            return win = 0;
        }
        win = 1;
    }
    else if(board[2] == board[4] && board[4] == board[6])
    {
        if (board[2] == '-')
        {
            return win = 0;
        }
        win = 1;
    }
    else if(board[2] == board[5] && board[5] == board[8])
    {
        if (board[2] == '-')
        {
            return win = 0;
        }
        win = 1;
    }
    else if(board[3] == board[4] && board[4] == board[5])
    {
        if (board[3] == '-')
        {
            return win = 0;
        }
        win = 1;
    }
    else if(board[6] == board[7] && board[7] == board[8])
    {
        if (board[6] == '-')
        {
            return win = 0;
        }
        win = 1;
    }
    else 
    {
        win = 0;
    }
    return win;
}

void computerMove(int *count, int *lastMove, char *board)
{
    int selectedMove = *lastMove + 1;
    
    if(board[selectedMove] == 'O')
    {
        cout << "next move is unable to be done" << endl;

    }
    board[selectedMove] = 'X';
    
    

}

void printBoard(char board[])
{
      for(int i = 0; i < 9; i+=3)
       {
           cout << board[i] << board[i+1] << board[i+2] << endl;
       }
}

//human side is implemented, need to implement computer move inbetween each human turn

void playGame(int count, int win, int humanSelect, char board[])
{
    while(count > 0 || win < 1)
   {
       cout << "Enter your position: ";
       cin >> humanSelect;
       if(board[humanSelect-1] != '-')
       {
           cout << endl << "That position is already taken! Try again..." << endl << endl;
           printBoard(board);
           continue;
       }

       //allow for array starting at zero
       board[humanSelect-1] = 'O';
       computerMove(&count, &humanSelect, board);
       printBoard(board);
       cout << "win: " << win << " count: " << count << endl;
       
        win = checkForWin(board);
        if(win == 1)
            break;
       count--;
    }

        if(win == 1)
        {
            cout << "winner found" << endl;
        }
        else 
        {
            cout << "No winner from that game" << endl;
        }
}

void reset(int *count, int *win, int *humanSelect, char *board)
{
    *count = 9;
    *win = 0;
    *humanSelect = 0;
    for(int i = 0; i < 9; i++)
        board[i] = '-';
}
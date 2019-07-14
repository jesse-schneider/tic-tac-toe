#include <cstdlib>
#include <iostream>

using namespace std;

void playGame(int count, int win, int humanSelect, char board[]);
int checkForWin(char board[]);
void printBoard(char board[]);
void computerMove(int count, char board[]);
void reset(int count, int win, int humanSelect, char board[]);

int main()
{
   char board[9] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
   int currentPlayer = 1;
   int count = 9;
   int win = 0;
   int humanSelect = 0;
   string yesNo = "Y";

   

   while(yesNo == "Y" || yesNo == "Yes" || yesNo == "y")
   {
       reset(count, win, humanSelect, board);
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
        win = 1;
    }
    else if(board[0] == board[3] && board[3] == board[6])
    {
        win = 1;
    }
    else if(board[0] == board[4] && board[4] == board[8])
    {
        win = 1;
    }
    else if(board[1] == board[4] && board[4] == board[7])
    {
        win = 1;
    }
    else if(board[2] == board[4] && board[4] == board[6])
    {
        win = 1;
    }
    else if(board[2] == board[5] && board[5] == board[8])
    {
        win = 1;
    }
    else if(board[3] == board[4] && board[4] == board[5])
    {
        win = 1;
    }
    else if(board[6] == board[7] && board[7] == board[8])
    {
        win = 1;
    }
    else 
    {
        win = 0;
    }

    return win;
}

void computerMove(int count, char board[])
{
    if(count < 4)
    {
        int select = rand() % 9;
        board[select] = 'X';
    }
    count++;

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
       humanSelect -= 1;
       board[humanSelect] = 'O';
       computerMove(count, board);
       printBoard(board);
       cout << "win: " << win << " count: " << count << endl;
       if (count < 5)
       {
           win = checkForWin(board);
       }
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

void reset(int count, int win, int humanSelect, char board[])
{
    count = 9;
    win = 0;
    humanSelect = 0;
    for(int i = 0; i < 9; i++)
        board[i] = '-';
}
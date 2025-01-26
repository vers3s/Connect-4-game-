
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <cstdlib>


using namespace std;
class Connect4 {
private:
    vector<vector<char>> board;
    vector<int> rowHeights;
    int counter;

public:
    Connect4() : counter(0), rowHeights(7, 8) {
        board = {
            {'+', '-', '-', '-', '-', '-', '-', '-', '+'},
            {'|', '1', '2', '3', '4', '5', '6', '7', '|'},
            {'|', '=', '=', '=', '=', '=', '=', '=', '|'},
            {'|', '0', '0', '0', '0', '0', '0', '0', '|'},
            {'|', '0', '0', '0', '0', '0', '0', '0', '|'},
            {'|', '0', '0', '0', '0', '0', '0', '0', '|'},
            {'|', '0', '0', '0', '0', '0', '0', '0', '|'},
            {'|', '0', '0', '0', '0', '0', '0', '0', '|'},
            {'|', '0', '0', '0', '0', '0', '0', '0', '|'},
            {'+', '-', '-', '-', '-', '-', '-', '-', '+'}
        };
    }

    void displayBoard() {
        for (const auto& row : board) {
            for (const auto& cell : row) {
                cout << cell << " ";
            }
            cout << "\n";
        }
    }

    bool makeMove(int col, char player) {
        if (col < 1 || col > 7 || rowHeights[col - 1] <= 2) {
            cout << "Invalid move. Try again.\n";
            return false;
        }

        board[rowHeights[col - 1]][col] = player;
        rowHeights[col - 1]--;
        counter++;
        return true;
    }

    bool isWinningMove(char player) {
        // Check rows, columns, and diagonals
        for (int i = 3; i < 9; ++i) {
            for (int j = 1; j < 8; ++j) {
                if (checkDirection(i, j, 0, 1, player) ||  // Horizontal
                    checkDirection(i, j, 1, 0, player) ||  // Vertical
                    checkDirection(i, j, 1, 1, player) ||  // Diagonal right
                    checkDirection(i, j, 1, -1, player)) { // Diagonal left
                    return true;
                }
            }
        }
        return false;
    }

    bool isDraw() {
        return counter >= 42;
    }

private:
    bool checkDirection(int row, int col, int dRow, int dCol, char player) {
        int count = 0;
        for (int step = 0; step < 4; ++step) {
            int r = row + step * dRow;
            int c = col + step * dCol;
            if (r < 3 || r > 8 || c < 1 || c > 7 || board[r][c] != player) {
                return false;
            }
            count++;
        }
        return count == 4;
    }
};
void playGame() {
    Connect4 game;
    char currentPlayer = 'U';
    bool gameRunning = true;

    while (gameRunning) {
        game.displayBoard();
        cout << "Player " << currentPlayer << ", enter column (1-7): ";

        int col;
        cin >> col;

        if (!game.makeMove(col, currentPlayer)) {
            continue;
        }

        if (game.isWinningMove(currentPlayer)) {
            game.displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            gameRunning = false;
        } else if (game.isDraw()) {
            game.displayBoard();
            cout << "It's a draw!\n";
            gameRunning = false;
        }

        currentPlayer = (currentPlayer == 'U') ? 'C' : 'U';
    }
}

//==========================================================================================================================================================================================================================================

void welcome (char& level) { // WELCOME MESSAGE TO USER AND SELECT LEVEL............................................

	cout << "\n||Welcome to the Connect 4 Game||\n";
	cout << "\n  Avaliable levels:";
	cout << "\n\t -- E for easy.";
	cout << "\n\t -- H for hard.";
	cout << "\n -> Please enter your chosen level: ";
	cin >> level; // cin for the level user chooses...
}

void display (vector <vector <char>>& board) { // DISPLAY THE BOARD
	for(int h = 0; h < 10; ++h) { // horizontal print
        for(int v = 0; v < 9; ++v) { //vertical print	
                cout << board[h][v] << " ";
        }
        cout << "\n";
	}
}          

void cmpt_choice (vector <vector <char>>& board, int cmpt_input, int& row) { // PUTS RANDOM CMPT CHOICE INTO THE BOARD AND CALLS DISPLAY()

		board[row][cmpt_input] = 'C'; // put C into the row and cmpt_input variable that comes into function
		row = row - 1; // subtract row by 1 so we can track if coloumn is full
		display(board); // show updated board
}      

// check if the random seed's value is valid... if not then random again and try. If random is valid proceed and call the cmpt_choice function so that board can be edited
void cmpt_fun_call (int& cmpt_entry, int& row_1, int& row_2, int& row_3, int& row_4, int& row_5, int& row_6, int& row_7, vector <vector <char>>& board){

	int test = 0;

	while (test == 0){


		if (cmpt_entry == 1){ // if the coloumn is one from random
			
			if (row_1 <= 2) { // if the row is full we take random again and go to beg. of loop
				srand (time(NULL)); 
				cmpt_entry = rand() % 7+1;
				continue;
			} else { // if row is not full it calls function which prints onto the board
			cmpt_choice(board, cmpt_entry, row_1);
			test = 1; // set flag as 1 to exit the loop
			}

		} else if (cmpt_entry == 2) { // if the coloumn is two from random
			if (row_2 <= 2) { // if the row is full we take random again and go to beg. of loop
				srand (time(NULL));
				cmpt_entry = rand() % 7+1;
				continue;
			} else { // if row is not full it calls function which prints onto the board
			cmpt_choice(board, cmpt_entry, row_2);
			test = 1; // set flag as 1 to exit the loop

			}
		} else if (cmpt_entry == 3) { // if the coloumn is three from random
			if (row_3 <= 2) { // if the row is full we take random again and go to beg. of loop
				srand (time(NULL));
				cmpt_entry = rand() % 7+1;
				continue;
			} else { // if row is not full it calls function which prints onto the board
			cmpt_choice(board, cmpt_entry, row_3);
			test = 1; // set flag as 1 to exit the loop

			}		
		} else if (cmpt_entry == 4) {// if the coloumn is four from random
			if (row_4 <= 2) { // if the row is full we take random again and go to beg. of loop
				srand (time(NULL));
				cmpt_entry = rand() % 7+1;
				continue;
			} else { // if row is not full it calls function which prints onto the board
			cmpt_choice(board, cmpt_entry, row_4);
			test = 1; // set flag as 1 to exit the loop

			}		
		} else if (cmpt_entry == 5) { // if the coloumn is five from random
			if (row_5 <= 2) { // if the row is full we take random again and go to beg. of loop
				srand (time(NULL));
				cmpt_entry = rand() % 7+1;
				continue;
			} else { // if row is not full it calls function which prints onto the board
			cmpt_choice(board, cmpt_entry, row_5);
			test = 1; // set flag as 1 to exit the loop
			}		
		} else if (cmpt_entry == 6) {// if the coloumn is six from random
			if (row_6 <= 2) { // if the row is full we take random again and go to beg. of loop
				srand (time(NULL));
				cmpt_entry = rand() % 7+1;
				continue;
			} else { // if row is not full it calls function which prints onto the board
			cmpt_choice(board, cmpt_entry, row_6);
			test = 1; // set flag as 1 to exit the loop
			}		
		} else if (cmpt_entry == 7) { // if the coloumn is seven from random
			if (row_7 <= 2) { // if the row is full we take random again and go to beg. of loop
				srand (time(NULL));
				cmpt_entry = rand() % 7+1;
				continue;
			} else { // if row is not full it calls function which prints onto the board
			cmpt_choice(board, cmpt_entry, row_7);
			test = 1; // set flag as 1 to exit the loop
			}		
		} 
	}
}
// if user chooses to play again we clear variable values otherwise close program
void play_again (int& flag, int& user_entry, int& cmpt_entry, int& row_1, int& row_2, int& row_3, int& row_4, int& row_5, int& row_6, int& row_7, int& counter) { 
	char play_again = ' ';
	cout << "Would you like to play again? (Y for yes and any other character for no) ";
	cin >> play_again; // take in users value
	if (play_again =='y' || play_again == 'Y'){ //if they choose yes clear out variables
		flag = 1;
		cmpt_entry = 0;
		user_entry = 0;
		row_1 = 8;
		row_2 = 8;
		row_3 = 8;
		row_4 = 8;
		row_5 = 8;
		row_6 = 8;
		row_7 = 8;
		counter = 0;
	} else { // otherwise close
		cout << "|| Thank you for playing Connect4. Have a good day! ||\n";
	}
}

void userwin_check (const vector <vector <char>>& board, int& win, int& user_check){ // check if user wins the game

	for (int i = 8;i > 2;--i) { //////////HORIZONTAL CHECK IF USER WON ----->
		if ((board[i][1] == 'U' && board[i][2] == 'U' && board[i][3] == 'U' && board[i][4] == 'U') || (board[i][2] == 'U' && board[i][3] == 'U' && board[i][4] == 'U' && board[i][5] == 'U') || (board[i][3] == 'U' && board[i][4] == 'U' && board[i][5] == 'U' && board[i][6] == 'U') || (board[i][4] == 'U' && board[i][5] == 'U' && board[i][6] == 'U' && board[i][7] == 'U')){
			win = 1; // win = 1 means USER WON
			user_check = 0; // set user_check = 0 so that we know won
			break;
		}
		//////////VERTICAL USER CHECK -->
		if ((board[i][1] == 'U' && board[i-1][1] == 'U' && board[i-2][1] == 'U' && board[i-3][1] == 'U') || (board[i][2] == 'U' && board[i-1][2] == 'U' && board[i-2][2] == 'U' && board[i-3][2] == 'U') || (board[i][3] == 'U' && board[i-1][3] == 'U' && board[i-2][3] == 'U' && board[i-3][3] == 'U') || (board[i][4] == 'U' && board[i-1][4] == 'U' && board[i-2][4] == 'U' && board[i-3][4] == 'U') || (board[i][5] == 'U' && board[i-1][5] == 'U' && board[i-2][5] == 'U' && board[i-3][5] == 'U') || (board[i][6] == 'U' && board[i-1][6] == 'U' && board[i-2][6] == 'U' && board[i-3][6] == 'U') || (board[i][7] == 'U' && board[i-1][7] == 'U' && board[i-2][7] == 'U' && board[i-3][7] == 'U')) {
			win = 1;// win = 1 means USER won
			user_check = 0; // set user_check = 0 so that we know won
			break;
		}
		//////////DIAGONAL RIGHT USER CHECK -->
		if ((board[i][1] == 'U' && board[i-1][2] == 'U' && board[i-2][3] == 'U' && board[i-3][4] == 'U') || (board[i][2] == 'U' && board[i-1][3] == 'U' && board[i-2][4] == 'U' && board[i-3][5] == 'U') || (board[i][3] == 'U' && board[i-1][4] == 'U' && board[i-2][5] == 'U' && board[i-3][6] == 'U') || (board[i][4] == 'U' && board[i-1][5] == 'U' && board[i-2][6] == 'U' && board[i-3][7] == 'U')){
			win = 1;// win = 1 means USER won
			user_check = 0; //set user_check = 0 so that we know  won
			break;
		}		
	}
	for (int i = 3;i < 9;++i) { //////////DIAGONAL LEFT USER CHECK -->
		if ((board[i][1] == 'U' && board[i+1][2] == 'U' && board[i+2][3] == 'U' && board[i+3][4] == 'U') || (board[i][2] == 'U' && board[i+1][3] == 'U' && board[i+2][4] == 'U' && board[i+3][5] == 'U') || (board[i][3] == 'U' && board[i+1][4] == 'U' && board[i+2][5] == 'U' && board[i+3][6] == 'U') || (board[i][4] == 'U' && board[i+1][5] == 'U' && board[i+2][6] == 'U' && board[i+3][7] == 'U')){
			win = 1;// win = 1 means USER won
			user_check = 0; //set user_check = 0 so that we know  won
			break;
		}
	}
}

void cmptwin_check (const vector <vector <char>>& board, int& win, int& user_check) { // check if user computer the game

	for (int i = 8;i > 2;--i) { //////////HORIZONTAL CHECK IF COMPUTER WON ----->
		if ((board[i][1] == 'C' && board[i][2] == 'C' && board[i][3] == 'C' && board[i][4] == 'C') || (board[i][2] == 'C' && board[i][3] == 'C' && board[i][4] == 'C' && board[i][5] == 'C') || (board[i][3] == 'C' && board[i][4] == 'C' && board[i][5] == 'C' && board[i][6] == 'C') || (board[i][4] == 'C' && board[i][5] == 'C' && board[i][6] == 'C' && board[i][7] == 'C')){
			win = 2; // win = 2 means COMP WON
			user_check = 0; //set user_check = 0 so that we know  won
			break;
		}
		//////////VERTICAL COMP CHECK -->
		if ((board[i][1] == 'C' && board[i-1][1] == 'C' && board[i-2][1] == 'C' && board[i-3][1] == 'C') || (board[i][2] == 'C' && board[i-1][2] == 'C' && board[i-2][2] == 'C' && board[i-3][2] == 'C') || (board[i][3] == 'C' && board[i-1][3] == 'C' && board[i-2][3] == 'C' && board[i-3][3] == 'C') || (board[i][4] == 'C' && board[i-1][4] == 'C' && board[i-2][4] == 'C' && board[i-3][4] == 'C') || (board[i][5] == 'C' && board[i-1][5] == 'C' && board[i-2][5] == 'C' && board[i-3][5] == 'C') || (board[i][6] == 'C' && board[i-1][6] == 'C' && board[i-2][6] == 'C' && board[i-3][6] == 'C') || (board[i][7] == 'C' && board[i-1][7] == 'C' && board[i-2][7] == 'C' && board[i-3][7] == 'C')) {
			win = 2; // win = 2 means COMP won
			user_check = 0; //set user_check = 0 so that we know  won
			break;
		}
		//////////DIAGONAL RIGHT CMPT CHECK -->
		if ((board[i][1] == 'C' && board[i-1][2] == 'C' && board[i-2][3] == 'C' && board[i-3][4] == 'C') || (board[i][2] == 'C' && board[i-1][3] == 'C' && board[i-2][4] == 'C' && board[i-3][5] == 'C') || (board[i][3] == 'C' && board[i-1][4] == 'C' && board[i-2][5] == 'C' && board[i-3][6] == 'C') || (board[i][4] == 'C' && board[i-1][5] == 'C' && board[i-2][6] == 'C' && board[i-3][7] == 'C')){
			win = 2;// win = 2 means COMP won
			user_check = 0; //set user_check = 0 so that we know  won
			break;
		}	
	}	
	for (int i = 3;i < 9;++i) { //////////DIAGONAL LEFT CMPT CHECK -->
		if ((board[i][1] == 'C' && board[i+1][2] == 'C' && board[i+2][3] == 'C' && board[i+3][4] == 'C') || (board[i][2] == 'C' && board[i+1][3] == 'C' && board[i+2][4] == 'C' && board[i+3][5] == 'C') || (board[i][3] == 'C' && board[i+1][4] == 'C' && board[i+2][5] == 'C' && board[i+3][6] == 'C') || (board[i][4] == 'C' && board[i+1][5] == 'C' && board[i+2][6] == 'C' && board[i+3][7] == 'C')){
			win = 2;// win = 1 means COMP won
			user_check = 0; //set user_check = 0 so that we know  won
			break;
		}
	}
}
////depending on the value of the win variable we give appropriate message and call play again function to give user choice to play again...
void win_message (int win, int& flag, int& user_entry, int& cmpt_entry, int& row_1, int& row_2, int& row_3, int& row_4, int& row_5, int& row_6, int& row_7, int& counter){

	if (win == 1) { // if win = 1 user won
		cout <<  "Congrats!! User Won!\n\n";
		play_again(flag, user_entry, cmpt_entry, row_1, row_2, row_3, row_4, row_5, row_6, row_7, counter);		//play again
	} else if (win == 2) { // if win = 1 user won
		cout << "Good Try!! Computer Won!\n\n";
		play_again(flag, user_entry, cmpt_entry, row_1, row_2, row_3, row_4, row_5, row_6, row_7, counter);		//play again
	} else if (win == 3) { // if win = 1 user won
		cout << "So close!! Its a draw!\n\n";
		play_again(flag, user_entry, cmpt_entry, row_1, row_2, row_3, row_4, row_5, row_6, row_7, counter);		//play again
	}
}

int main () { // MAIN PROGRAM
        int choice;
	char level; // keep track of level
	int row_1 = 8, row_2 = 8, row_3 = 8, row_4 = 8, row_5 = 8, row_6 = 8, row_7 = 8; // VARIABLES TO KEEP TRACK OF CURRENT ROW NUM,,,,
	int user_entry = 0, cmpt_entry = 0; // varibales that keep track of which coloum the user/comp chooses
	int flag = 1; //  flag used for loop purposees
	int counter = 0; // counter is to find out when board is full and no one won (42)
	while (flag == 1) { // while loop flag is one
		cout<<"\tMenu"<<endl;
		cout<<"\t1: Play with friend"<<endl;
		cout<<"\t2: Play with Computer"<<endl;
		cin>>choice;
		
		switch(choice){
          		case 1: 
            		  srand(time(NULL));
                          cout << "Welcome to Connect 4!\n";
                          playGame();
                        break;
		case 2:
		    welcome(level); //CALL WECLOME FUNCTION

		    vector <vector <char>> board = { // MAKE EMPTY PLAYING BOARD
			    {'+', '-', '-', '-', '-', '-', '-', '-', '+'},		
			    {'|', '1', '2', '3', '4', '5', '6', '7', '|'},
			    {'|', '=', '=', '=', '=', '=', '=', '=', '|'},
			    {'|', '0', '0', '0', '0', '0', '0', '0', '|'},
			    {'|', '0', '0', '0', '0', '0', '0', '0', '|'},
			    {'|', '0', '0', '0', '0', '0', '0', '0', '|'},
			    {'|', '0', '0', '0', '0', '0', '0', '0', '|'},
			    {'|', '0', '0', '0', '0', '0', '0', '0', '|'},
			    {'|', '0', '0', '0', '0', '0', '0', '0', '|'},
			    {'+', '-', '-', '-', '-', '-', '-', '-', '+'}	
		    };
		    if (level == 'E' || level == 'e'){ // EASY LEVEL
			    flag = 0; // make flag = 0 so we dont loop and make board again.. only happens when we start or play again...
			    display (board); // show board
			    int win = 0; /// to check if its a win or loss or tie
			    while (win == 0) { // when no one has won yet win =0
				    cout << endl;

				    int user_check = 1; // variable that hcecks iff users column choice is valid
				    while (user_check == 1) { // check if user has entered a valid column selection

					    cout << "\nPlease enter the column number you would like to fill: "; // ask user to fill
					    cin >> user_entry;
					    if (user_entry <= 0 || user_entry >= 8){ // if out of bounds give error
						    cout << "Inavlid Column! Please try again.";
						    user_check = 1; // make user_check = 1 and loop again asking for valid coloum

					    } else if (user_entry == 1){ // so if coloum 1 is chosen

						    if (row_1 <= 2) { // if that is full give error message
							    cout << "|| Column " << user_entry << " is full. Please try a different column!||\n";
							    user_check = 1; // set user_check = 1 so we loop again
							    continue;
						    } else { // if all is good put it into board
							    board[row_1][user_entry] = 'U'; 
							    counter ++; // increase counter
							    row_1 = row_1 - 1; // minus one for row so we know when the coloum is full 
							    user_check = 0; // set it to 0 so we dont loop again
							    break;
						    }
					    } else if (user_entry == 2) { // so if coloum 2 is chosen
						    if (row_2 <= 2) { // if that is full give error message
							    cout << "|| Column " << user_entry << " is full. Please try a different column!||\n";
							    user_check = 1; // set user_check = 1 so we loop again
							    continue;
						    } else { // if all is good put it into board
							    board[row_2][user_entry] = 'U';
							    counter ++; // increase counter
							    row_2 = row_2 - 1; // minus one for row so we know when the coloum is full 
							    user_check = 0; // set it to 0 so we dont loop again
							    break;
						    }
					    } else if (user_entry == 3) { // so if coloum 3 is chosen
						    if (row_3 <= 2) { // if that is full give error message
							    cout << "|| Column " << user_entry << " is full. Please try a different column!||\n";
							    user_check = 1; // set user_check = 1 so we loop again
							    continue;
						    } else { // if all is good put it into board
							    board[row_3][user_entry] = 'U';
							    counter ++; // increase counter
							    row_3 = row_3 - 1; // minus one for row so we know when the coloum is full 
							    user_check = 0; // set it to 0 so we dont loop again
							    break;
						    }					
					    } else if (user_entry == 4) { // so if coloum 4 is chosen
						    if (row_4 <= 2) { // if that is full give error message
							    cout << "|| Column " << user_entry << " is full. Please try a different column!||\n";
							    user_check = 1; // set user_check = 1 so we loop again
							    continue;
						    } else { // if all is good put it into board
							    board[row_4][user_entry] = 'U';
							    counter ++; // increase counter
							    row_4 = row_4 - 1; // minus one for row so we know when the coloum is full 
							    user_check = 0; // set it to 0 so we dont loop again
							    break;
						    }					
					    } else if (user_entry == 5) { // so if coloum 5 is chosen
						    if (row_5 <= 2) { // if that is full give error message
							    cout << "|| Column " << user_entry << " is full. Please try a different column!||\n";
							    user_check = 1; // set user_check = 1 so we loop again
							    continue;
						    } else { // if all is good put it into board
							    board[row_5][user_entry] = 'U';
							    counter ++; // increase counter
							    row_5 = row_5 - 1; // minus one for row so we know when the coloum is full 
							    user_check = 0; // set it to 0 so we dont loop again
							    break;
						    }
					    } else if (user_entry == 6) { // so if coloum 6 is chosen
						    if (row_6 <= 2) { // if that is full give error message
							    cout << "|| Column " << user_entry << " is full. Please try a different column!||\n";
							    user_check = 1; // set user_check = 1 so we loop again
							    continue;
						    } else { // if all is good put it into board
							    board[row_6][user_entry] = 'U';
							    counter ++; // increase counter
							    row_6 = row_6 - 1; // minus one for row so we know when the coloum is full 
							    user_check = 0; // set it to 0 so we dont loop again
							    break;
						    }
					    } else if (user_entry == 7) { // so if coloum 7 is chosen
						    if (row_7 <= 2) { // if that is full give error message
							    cout << "|| Column " << user_entry << " is full. Please try a different column!||\n";
							    user_check = 1; // set user_check = 1 so we loop again
							    continue;
						    } else { // if all is good put it into board
							    board[row_7][user_entry] = 'U';
							    counter ++; // increase counter
							    row_7 = row_7 - 1; // minus one for row so we know when the coloum is full 
							    user_check = 0; // set it to 0 so we dont loop again
							    break;
						    }
					    } 
				    }
				    display(board); // display board
				    
				    userwin_check (board, win, user_check); // call function that checks if user or comp has won the game......................

				    // computer choosing where to put its part
				    if (win != 1) { //only do it when user has not won the game already
					    if (user_entry == 1) { // if user chooses coloum 1
						    cmpt_entry = user_entry + 6; // put it into other side of board
					    } else if (user_entry == 7) { // if user chooses coloum 7
						    cmpt_entry = user_entry -1; // put it one left of user
					    } else { // otherwise
						    cmpt_entry = user_entry - 1; // put it one left of user
					    }
					    cmpt_fun_call(cmpt_entry, row_1, row_2, row_3, row_4, row_5, row_6, row_7, board);	// call the computer function call that places into the board
					    cout << "\nThe computer has chosen to fill column " << cmpt_entry << ".\n\n";
					    counter ++; // add to counter for draw
					    
					    if (counter == 42){ // if counter is 42 and no one has won then board is full
					     	win = 3; // set win to 3 == draw mode
					     	user_check = 0; // sert user check to 0
					    }
				    }
				    cmptwin_check (board, win, user_check); // call function that checks if compuer won,,,,
			    }
		    
			    win_message (win, flag, user_entry, cmpt_entry, row_1, row_2, row_3, row_4, row_5, row_6, row_7, counter); // give win message if it is needed ... win lose or draw./.


		    } else if (level == 'H' || level == 'h'){ // HARD LEVEL

			    flag = 0; // make flag = 0 so we dont loop and make board again.. only happens when we start or play again...
			    display (board); // show board
			    int win = 0; //// to check if its a win or loss or tie
			    while (win == 0) { // when no one has won yet win =0
				    cout << endl;

				    int user_check = 1; // variable that hcecks iff users column choice is valid
				    while (user_check == 1) { // check if user has entered a valid column selection

					    cout << "\nPlease enter the column number you would like to fill: "; // ask user to fill
					    cin >> user_entry;
					    if (user_entry <= 0 || user_entry >= 8){ // if out of bounds give error
						    cout << "Inavlid Column! Please try again.";
						    user_check = 1; // make user_check = 1 and loop again asking for valid coloum

					    } else if (user_entry == 1){ // so if coloum 1 is chosen

						    if (row_1 <= 2) {// if that is full give error message
							    cout << "|| Column " << user_entry << " is full. Please try a different column!||\n";
							    user_check = 1; // set user_check = 1 so we loop again
							    continue;
						    } else { // if all is good put it into board
							    board[row_1][user_entry] = 'U';
							    counter ++; // increase counter
							    row_1 = row_1 - 1; // minus one for row so we know when the coloum is full 
							    user_check = 0; // set it to 0 so we dont loop again
							    break;
						    }
					    } else if (user_entry == 2) { // so if coloum 2 is chosen
						    if (row_2 <= 2) { // if that is full give error message
							    cout << "|| Column " << user_entry << " is full. Please try a different column!||\n";
							    user_check = 1; // set user_check = 1 so we loop again
							    continue;
						    } else { // if all is good put it into board
							    board[row_2][user_entry] = 'U';
							    counter ++; // increase counter
							    row_2 = row_2 - 1; // minus one for row so we know when the coloum is full 
							    user_check = 0; // set it to 0 so we dont loop again
							    break;
						    }
					    } else if (user_entry == 3) { // so if coloum 3 is chosen
						    if (row_3 <= 2) { // if that is full give error message
							    cout << "|| Column " << user_entry << " is full. Please try a different column!||\n";
							    user_check = 1; // set user_check = 1 so we loop again
							    continue;
						    } else { // if all is good put it into board
							    board[row_3][user_entry] = 'U';
							    counter ++; // increase counter
							    row_3 = row_3 - 1; // minus one for row so we know when the coloum is full 
							    user_check = 0; // set it to 0 so we dont loop again
							    break;
						    }					
					    } else if (user_entry == 4) { // so if coloum 4 is chosen
						    if (row_4 <= 2) { // if that is full give error message
							    cout << "|| Column " << user_entry << " is full. Please try a different column!||\n";
							    user_check = 1; // set user_check = 1 so we loop again
							    continue;
						    } else { // if all is good put it into board
							    board[row_4][user_entry] = 'U';
							    counter ++; // increase counter
							    row_4 = row_4 - 1; // minus one for row so we know when the coloum is full 
							    user_check = 0; // set it to 0 so we dont loop again
							    break;
						    }					
					    } else if (user_entry == 5) { // so if coloum 5 is chosen
						    if (row_5 <= 2) { // if that is full give error message
							    cout << "|| Column " << user_entry << " is full. Please try a different column!||\n";
							    user_check = 1; // set user_check = 1 so we loop again
							    continue;
						    } else { // if all is good put it into board
							    board[row_5][user_entry] = 'U';
							    counter ++; // increase counter
							    row_5 = row_5 - 1; // minus one for row so we know when the coloum is full 
							    user_check = 0; // set it to 0 so we dont loop again
							    break;
						    }
					    } else if (user_entry == 6) { // so if coloum 6 is chosen
						    if (row_6 <= 2) { // if that is full give error message
							    cout << "|| Column " << user_entry << " is full. Please try a different column!||\n";
							    user_check = 1; // set user_check = 1 so we loop again
							    continue;
						    } else { // if all is good put it into board
							    board[row_6][user_entry] = 'U';
							    counter ++; // increase counter
							    row_6 = row_6 - 1; // minus one for row so we know when the coloum is full 
							    user_check = 0; // set it to 0 so we dont loop again
							    break;
						    }
					    } else if (user_entry == 7) { // so if coloum 7 is chosen
						    if (row_7 <= 2) { // if that is full give error message
							    cout << "|| Column " << user_entry << " is full. Please try a different column!||\n";
							    user_check = 1; // set user_check = 1 so we loop again
							    continue;
						    } else { // if all is good put it into board
							    board[row_7][user_entry] = 'U';
							    counter ++; // increase counter
							    row_7 = row_7 - 1; // minus one for row so we know when the coloum is full 
							    user_check = 0; // set it to 0 so we dont loop again
							    break;
						    }
					    } 
				    }
				    display(board); // show the board
				    userwin_check (board, win, user_check); // call function that checks if user or comp has won the game......................

				    if (win != 1) { //only do it when user has not won the game already
				      	srand (time(NULL)); // set random seed 
					    cmpt_entry = rand() % 7+1; // computer selects randomly
					    cmpt_fun_call(cmpt_entry, row_1, row_2, row_3, row_4, row_5, row_6, row_7, board); // call the computer function call that places into the board
					    cout << "The computer has chosen to fill column " << cmpt_entry << ".\n\n"; 
					    counter ++; // add counter for draw check
					    if (counter == 42){ // if counter is 42 and no one has won then board is full
					     	win = 3; // set win to 3 == draw mode
					     	user_check = 0; // sert user check to 0
					    }
				    }	

				    cmptwin_check (board, win, user_check); // call function that checks if compuer won,,,,

			    }		
			    win_message (win, flag, user_entry, cmpt_entry, row_1, row_2, row_3, row_4, row_5, row_6, row_7, counter); // give win message if it is needed ... win lose or draw./.

		    } else { // if the level entered was not H OR E

			    cout << "Inavlid level choice. Please try again."; //give error message
			    flag = 1; // flag = 1 so we loop again
		    }
	    } 
    }
  }

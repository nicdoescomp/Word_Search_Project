//
//  main.cpp
//  Word Search
//
//  Created by Nicholas Brown on 11/16/24.
//

#include <iostream>
#include <cstring>
using namespace std;

void intro();

void printarray(char wordSearch[][5],int const ROW, int const COL);
// note to self: when passing a 2D array always specify the second  demension's size
void wordSearching (char wordSearch[][5], int const ROW, int const COL, int rowDir[], int colDir[], string answer);

int main() {
    // insert code here...
    intro(); // this is where i would call the intro title sequence form the the intro function
    int const ROW = 5;
    int const COL = 5;
    string answer; // I want the user to give an answer using the one of the key words as one of their answers

    char wordSearch[ROW][COL]{ // actual word search that will display for the user
        'a', 'b','o','b','b',
        'a', 'b','c','d','i',
        't', 'b','c','g','l',
        'a', 'a','c','o','l',
        'a', 'b','c','d','y',};
    
    //This allows me to refer to each string efficiently without copying the data multiple times.

    printarray(wordSearch, ROW, COL); // this will print the wordsearch out for user
    
    cout << "Please input a word to check and see if inside the Word Search: ";
    getline(cin, answer);
    cout << "Your answer was: " << answer << endl;
    

    
    int rowDir[] = {-1, 1, 0, 0, -1, -1, 1, 1}; // Up, Down, Left, Right, Diagonal Up-Left, etc.
    int colDir[] = {0, 0, -1, 1, -1, 1, -1, 1};
    
    wordSearching(wordSearch, ROW, COL, rowDir, colDir, answer);

    return 0;
}

void intro(){
    
    cout << "\tHi, User!" << endl;
    cout << "\tPlease help me solve this problem" << endl;
    
    
    
    
}

void printarray(char wordSearch[][5], int const ROW, int const COL){
    
    
    for (int j = 0; j < ROW ; j++) {
        for (int i = 0; i < COL  ; i++) {
            cout << "\t "<< wordSearch[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;
   
}

// this is the main algorithm that helps the user identify if they found the word or not
void wordSearching(char wordSearch[][5], int const ROW, int const COL, int rowDir[], int colDir[], string answer) {
    
    
    
    int len = answer.length(); // Length of the word to find (really important since we do not want to be given a word with the incorrect size)
    bool found = false; // this is to let me know if the program has found what the user gave me
    
    
    // Iterate over the grid
    
    for (int j = 0; j < ROW; j++) { // iterates all of the CONSTANT  rows
        
        for (int i = 0; i < COL; i++) { // iterates all of the CONSTANT collums
            // Iterate over all 8 possible directions
            for (int dir = 0; dir < 8; dir++) { // this is now checking all of the directions  i passed through the function's parameter
                
                int k; // this is a counter that i will use to identify the user's answer by every single character
                int row = j; // declared this variable to track the CURRENT location of the rows
                int col = i; // declared this variable to track the CURRENT location of the cols
                
                // Check each character of the word with respect to the user's answer's word length
                for (k = 0; k < len; k++) {
                    // Check for out-of-bounds or character mismatch
                    if (row < 0 || row >= ROW || col < 0 || col >= COL || wordSearch[row][col] != answer[k]) {
                        // if any conditions meet true then you are out of the scope of the wordsearch and the loop will end
                        break;
                    }
                    // Move to the next character in the current direction
                    row += rowDir[dir];
                    col += colDir[dir];
                }
                
                // If the entire word is matched
                if (k == len) {
                    found = true;
                    // Iterate through the matched coordinates
                    row = j;
                    col = i;
                    cout << "Found the word \"" << answer << "\" at coordinates:\n";
                    for (k = 0; k < len; k++) {
                        cout << "(" << row << ", " << col << ")\n";
                        
                        row += rowDir[dir];
                        col += colDir[dir];
                    }
                    cout << endl;
                }
            }
        }
    }
    // this is for error handling incase you do not find what you are looking for
    if (!found) {
        cout << "Word \"" << answer << "\" not found in the word search." << endl;
       
    }
}
   



#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<vector<char>> solvedSudoku;

void solveSudoku(vector<vector<char>> &sudoku, int x, int y) {
    if(x==8 && y==8) {
        // here x and y should be indexes that already have numbers filled
        // solution found
        solvedSudoku = sudoku;
        return;
    }
    
    // find an empty place to fill
    int a = -1;
    int b = -1;
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(sudoku[i][j]=='.') {
                a = i;
                b = j;
                break;
            }
        }
        if(a!= -1 && b!= -1) {
            break;
        }
    }

    // if you can't find an empty place, the sudoku is already solved
    if(a==-1 || b==-1) {
        solvedSudoku = sudoku;
        return;
    }

    // find all the numbers that can be filled in that empty place
    vector<char> possibleNumbers;
    
    for(int i=1; i<=9; i++) {
        bool isPresentRow = false;
        for(int j=0; j<9; j++) {
            if(sudoku[a][j]==(char)(i+(int)'0')) isPresentRow = true;
        }

        // if(isPresentRow) cout<<i<<" is present in the row"<<endl;
        if(isPresentRow) continue;

        bool isPresentColumn = false;
        for(int k=0; k<9; k++) {
            if(sudoku[k][b]==(char)(i+(int)'0')) isPresentColumn = true;
        }

        // if(isPresentColumn) cout<<i<<" is present in the column"<<endl;
        if(isPresentColumn) continue;

        bool isPresentBox = false;
        int rowStartIndex = (a/3)*3;
        int columnStartIndex = (b/3)*3;
        for(int l=rowStartIndex; l<rowStartIndex+3; l++) {
            for(int m=columnStartIndex; m<columnStartIndex+3; m++) {
                if(sudoku[l][m]==(char)(i+(int)'0')) isPresentBox = true;
            }
        }
        // if(isPresentBox) cout<<i<<" is present in the box"<<endl;
        if(isPresentBox) continue;

        possibleNumbers.push_back((char)(i+(int)'0'));
    }


    // if there are no possible numbers
    if(!possibleNumbers.size()) return;

    // fill each possible number one by one 

    cout<<"Possible Numbers for a:"<<a<<" and b:"<<b<<" are-> ";
    for(char ch: possibleNumbers) cout<<ch<<" ";
    cout<<endl<<endl;

    for(int i=0; i<possibleNumbers.size(); i++) {
        vector<vector<char>> V(sudoku.begin(), sudoku.end());

        V[a][b] = possibleNumbers[i];

        solveSudoku(V, a, b);
    }

    return;
}

int main() {

    solvedSudoku.clear();

    vector<string> stringSudoku{
    "53..7....", 
    "6..195...", 
    ".98....6.", 
    "8...6...3", 
    "4..8.3..1", 
    "7...2...6", 
    ".6....28.", 
    "...419..5", 
    "....8..79"
    };

    vector<string> stringSudoku1{
    "534678912", 
    "672195348", 
    "198342567", 
    "859761423", 
    "426853791", 
    "713924856", 
    "961537284", 
    "287419635", 
    "345286179"
    };

    vector<vector<char>> sudoku;
    for(string str: stringSudoku) {
        vector<char> v;
        for(char ch: str) v.push_back(ch);
        sudoku.push_back(v);
    }

    solveSudoku(sudoku, 0, 0);
    
    cout<<"given sudoku: "<<endl;
    for(vector<char> vec: sudoku) {
        cout<<"[";
        for(char ch: vec) cout<<ch;
        cout<<"]"<<endl;
    }

    cout<<"solved sudoku: "<<endl;
    for(vector<char> vec: solvedSudoku) {
        cout<<"[";
        for(char ch: vec) cout<<ch;
        cout<<"]"<<endl;
    }

    return 0;
    
}
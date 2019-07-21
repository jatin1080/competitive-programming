#include<iostream>
#include<bits/stdc++.h>

using namespace std;

string justifiedLineFromArray(vector<string> &C, int B) {
    int totalLengthOfAllWords = 0;
    int numberOfWords = C.size();
    
    for(int i=0; i<numberOfWords; i++) {
        totalLengthOfAllWords += C[i].length();
    }
    
    if(B<totalLengthOfAllWords+numberOfWords-1) return "wrong input";
    
    int numberOfSpaces = B - totalLengthOfAllWords;
    
    int numberOfGaps = numberOfWords -1;
    
    int numberOfSpacesAfterEachWord = numberOfGaps? numberOfSpaces/numberOfGaps : numberOfSpaces;

    string spaces = "";

    for(int j=0; j<numberOfSpacesAfterEachWord; j++) {
        spaces += '#';
    }

    cout<<"counting spaces-----> "<<spaces.length();
    
    int extraSpacesRemaining = numberOfGaps ? numberOfSpaces%numberOfGaps : 0;
    
    string str = C[0];

    for(int i=1; i<numberOfWords; i++) {
        string spacesAndNextWord = spaces;
        if(extraSpacesRemaining) {
            spacesAndNextWord += '#';
            extraSpacesRemaining--;
        }
        spacesAndNextWord += C[i];
        str += spacesAndNextWord;
    }

    if(numberOfWords==1) str += spaces;
    return str;
    
}

vector<string> fullJustify(vector<string> &A, int B) {
    int numOfWords = A.size();
    
    vector<string> ans;
    
    int i=0;
    while(i<numOfWords)
    {
        vector<string> wordsInALine;
        int lengthOfWordsInALine = 0;
        for(int j=i; j<numOfWords; j++)
        {
            if(lengthOfWordsInALine) lengthOfWordsInALine++; //for accomodating atleast one space
            if(lengthOfWordsInALine+A[j].length()<=B) //push the word to vector
            {
                wordsInALine.push_back(A[j]);
                lengthOfWordsInALine += A[j].length();
                i++;
                cout<<" inside loop i is   "<<i;
            }
            else
            {
                break;
            }
        }

        cout<<"wordsInALine.size()  "<<wordsInALine.size()<<" and i is "<<i;        
        ans.push_back(justifiedLineFromArray(wordsInALine, B));
        wordsInALine.clear();
    }
    
    return ans;
}

int main() {

    vector<string> A{"This", "is", "an", "example", "of", "text", "justification."};

    // {"This", "is", "an", "example", "of", "text", "justification."}

    for(string str: A) {
        cout<<str<<endl;
    }

    vector<string> C(A.begin(), A.begin()+1);

    string D = justifiedLineFromArray(C, 16);

    cout<<"\n \n \n";

    for(string str: C) {
        cout<<"C "<<str<<endl;
    }

    cout<<"\n D "<<D;

    vector<string> B = fullJustify(A, 16);

    cout<<"\n \n \n";

    for(string str: B) {
        cout<<str<<endl;
    }

}
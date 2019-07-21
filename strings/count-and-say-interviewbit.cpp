#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string nextNumber(string num)
{
    string str = num;
    char previousChar = str[0];
    string number = "";
    int countOfChars = 0;
    for (int j = 0; j < str.length(); j++)
    {
        if (str[j] == previousChar)
        {
            if (j)
                previousChar = str[j];
            countOfChars++;
            // if (j == str.length() - 1)
            // {
            //     string count = to_string(countOfChars);
            //     // cout<<"this is the count: "<<count<<endl;
            //     number += (count + previousChar);
            //     // cout<<"this is the number: "<<number<<endl;
            // }
        }
        else
        {
            string count = to_string(countOfChars);
            number += (count + previousChar);
            previousChar = str[j];
            countOfChars = 1;
        }

        if (j == str.length() - 1)
        {
            string count = to_string(countOfChars);
            // cout<<"this is the count: "<<count<<endl;
            number += (count + previousChar);
            // cout<<"this is the number: "<<number<<endl;
        }
    }

    return number;
}

string nthNumber(int A)
{
    vector<string> numbers;
    numbers.push_back("1");
    if (A == 1)
        return numbers[0];

    for (int i = 1; i < A; i++)
    {
        string str = numbers[i - 1];
        numbers.push_back(nextNumber(str));
    }

    for (string str : numbers)
        cout << "sequence--->" << str << endl;

    return numbers[A - 1];
}

int main()
{

    int a = 4;
    cout << "nextNumber(\"21\")--> " << nextNumber("1239") << "\n";
    // cout << "nthNumber(a)--> " << nthNumber(a) << "\n";
}
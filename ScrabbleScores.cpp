/*
ScrabbleScores.cpp : Create a function that takes an array of words, scores the words based on the Scrabble scoring table below, and returns an array of the highest scoring words.
                     The words on the resulting array should be in the same relative order as the original array.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> bestWords(vector<string> arr)
{
    char letters[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    vector<int> value{1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 2, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int sum = 0, max = 0, size = arr.size();
    vector<int> wordsValue;
    vector<char> toChar;
    
  
    for (int i = 0; i < arr.size(); i++)
    {
        copy(arr[i].begin(), arr[i].end(), back_inserter(toChar));
        for (int j = 0; j < toChar.size(); j++)
        {
            for (int z = 0; z < sizeof(letters); z++)
            {

                if (toChar[j] == letters[z])
                {
                    sum += value[z];
                    wordsValue.push_back(sum);

                }
            }
        }
        toChar.clear();
    }

    max = wordsValue[0];

    for (int i = 1; i < size; i++)
    {
        if (wordsValue[i] > max)
        {
            max = wordsValue[i];
            arr.erase(arr.begin() + i - 1);
            wordsValue.erase(wordsValue.begin() + i - 1);
            i--;
            size--;
        }
        else if (max > wordsValue[i])
        {
            arr.erase(arr.begin() + i);
            wordsValue.erase(wordsValue.begin() + i);
            i--;
            size--;
        }
        else if (max == wordsValue[i])
            continue;
    }

    return arr;
}

int main()
{
    vector<string> arr;
    string x;

    cout << "Enter words (enter 'end' to stop) \n";
    while (cin >> x)
    {
        if (x == "end")
            break;
        arr.push_back(x);
    }

    cout << bestWords(arr).size() << endl;

    cout << "Highest score words are: [ ";
    for (int i = 0; i < bestWords(arr).size(); i++)
        cout << bestWords(arr)[i] << " ";
    cout << "]";
}



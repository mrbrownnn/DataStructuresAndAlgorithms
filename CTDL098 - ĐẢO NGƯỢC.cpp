#include<bits/stdc++.h>
using namespace std;
string reverseWord(string word)
{
    stack<char> charStack;

    for (char c : word)
    {
        charStack.push(c);
    }

    string reversedWord = "";
    while (!charStack.empty())
    {
        reversedWord += charStack.top();
        charStack.pop();
    }
    return reversedWord;
}

string reverseSentence(string sentence)
{
    istringstream iss(sentence);
    string word;
    string reversedSentence = "";

    while (iss >> word)
    {
        reversedSentence += reverseWord(word) + " ";
    }
    return reversedSentence;
}

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        cin.ignore(); 
        string sentence;
        getline(cin, sentence);

        cout << reverseSentence(sentence) << endl;
    }

    return 0;
}
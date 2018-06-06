/* CATE YUK
Project 1: Reads in a file and outputs the total word count, 
the word count of unique words, and the number of occurences 
of a user-entered word. */

#include <iostream>
#include <fstream>
#include <string>
#include <locale>
using namespace std;

int main(int argc, char **argv) {

    //Check number of arguments
    if (argc != 2) {
        cout << "Error: incorrect number of arguments" << endl;
        return 1;
    }


    //Try to open file
    fstream file;
    file.open(argv[1]);
    if(!file.is_open()) {
        cout << "Error: could not open file " << argv[1] << "." << endl;
        return 1;
    }


    //WORD COUNT
    string wordArray[10000];
    string temp;
    char ch;
    int wordCount = 0;

    while (file.get(ch)) {
        ch = tolower(ch); //Convert to lowercase
        if (isalpha(ch)) {
            temp.push_back(ch); //Create temporary string of characters
        }
        else if (!temp.empty()) { //Checks to make sure string isn't empty
            wordArray[wordCount++] = temp; //Adds words to array of strings
            temp = "";
        }
    }

    cout << "The number of words found in the file was " << wordCount << endl;


    //UNIQUE COUNT
    int countUnique = 0;

    for (int i = 0; i < wordCount; i++) {
        int flag = 0;
        for (int j = i+1; j < wordCount-1; j++) {
            if (wordArray[i] == wordArray[j]) {
                flag = 1; //Indicates duplicate word
            }
        }
        if (flag == 1) countUnique++;
    }

    countUnique = wordCount - countUnique;

    cout << "The number of unique words found in the file was "
    << countUnique << endl;


    //INCREMENT COUNTS
    int countArray[10000]; //Stores instances of all words
    string uniqueArray[10000]; //Stores each word once

    for (int a = 0; a < wordCount; a++) {
        countArray[a] = 1; //Assumes presence of all words
        for (int b = a+1; b < wordCount-1; b++) {
            if (wordArray[a] == wordArray[b]) {
                countArray[a]++; //Tracks instances of each word
            }
        }
    }
    for (int t = 0; t < wordCount; t++) {
        if (countArray[t] == 1)
            uniqueArray[t] = wordArray[t]; //Creates array of unique words
    }

    //Update counts of all words to the latest value
    for (int a = 0; a < wordCount; a++) {
        for (int b = a+1; b < wordCount-1; b++) {
            if (wordArray[a] == wordArray[b]) {
                if (countArray[a] > countArray[b])
                    countArray[b] = countArray[a];
                else if (countArray[b] > countArray[a])
                    countArray[a] = countArray[b];
            }
        }
    }



    //USER-ENTERED SEARCH COUNT
    string userWord;
    string stop; //Prevents extra loop in output

    cout << "Please enter a word: ";
    cin >> userWord;

    while (userWord != "END") {
        int wildCount = 0; //Reset variable
        int count = 0; //Reset variable
        for (int i = 0; i < wordCount; i++)
            if (userWord == uniqueArray[i]) count++; //Check 0-instance cases
        for (int i = 0; i < userWord.length(); i++) 
            if (userWord[i] == '?') wildCount++; //Count '?'
        
        //0-instance cases
        if (count == 0 && wildCount == 0) {
           cout << "The word " << userWord;
           cout << " appears 0 times in the document" << endl;
           count = 0;
           wildCount = 0;
        }
        else {
            for (int n = 0; n < wordCount; n++) {
                for (int o = 0; o < uniqueArray[n].length(); o++) {
                    if (uniqueArray[n][0] == userWord[0] 
                    || userWord[0] == '?') { //Check if first character match
                        int matched = 1; //Assume a match
                        for (int p = 0; p < userWord.length(); p++) {
                            //Check character by character
                            if (userWord[p] != uniqueArray[n][o+p]
                                && userWord[p] != '?') {
                                matched = 0; //No match, leave loop
                                break;
                            } 
                        }
                        if (matched == 1
                            && userWord.length() == uniqueArray[n].length()
                            && stop != uniqueArray[n]) {
                            cout << "The word " << uniqueArray[n];
                            cout << " appears " << countArray[n];
                            cout << " times in the doctument" << endl;
                        }
                        stop = uniqueArray[n]; //Prevent looping output
                    }
                } 
            }
        }       
        cout << "Please enter a word: ";
        cin >> userWord;
    }


    file.close();

    return 0;
}


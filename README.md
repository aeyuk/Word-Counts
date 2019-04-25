# Word-Counts

## Description
This program reads in a file and outputs the total number of words and the number of distinct words in the file. 
Following this, the program will also output how many times a user-inputted word is found in the file.

## Specifics
Each word consists strictly of the letters A-Z and a-z. Any whitespace, punctuation, digit, etc. will separate words. 
Each word should be converted to lowercase so that only lowercase letters remain.
When the user enters a word to search for, a ‘?’ character may be present as some of the letters for the search. 
This special character represents the ability to match any non-empty character.
The ? character in the source input file is not a wildcard match. 
In the original source, it is just another non-letter character.
The file sample.txt has been supplied as a test file.

## Downloading and Compiling
Clone the repository from terminal, or download the zip and extract the files.

```bash
git clone https://github.com/aeyuk/Word-Counts
```

Download whatever text file you would like to use in your program to the project directory.

Build the project using `make` and execute using `./wordcounts filename.txt`

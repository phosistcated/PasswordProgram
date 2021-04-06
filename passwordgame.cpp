// parse text file
// store every unique token found in an array
// white space delineated
// strip any trailing punctuation & discard capitalization
// return detected tokens as a std::list of strings

#include <fstream>
#include <iostream>
#include <list>
#include <vector>
#include <cctype>

int getUnique(){
    std::ifstream fileName("password.txt"); // opens file using password.txt for testing

    if (fileName){ // checks if file exists
        std::string temp; // create temp
        std::vector<std::string> tokens; // store unique words

        while (fileName >> temp){ // loops through, reading words
            bool wordRead = false; // checks to see if word already has been read

            for (unsigned int i = 0; i < tokens.size(); i++){ // loops through words
                if (temp == tokens[i]){ // checks to see if word has been stored in temp 
                    wordRead = true; // if the words is already there, it stops
                    break;
                }
            }
            if (not wordRead){  
                tokens.push_back(temp); // adds word to array if not already there
            }
        }
        for(unsigned int i = 0; i < tokens.size(); i++){
            std::cout << tokens[i] << "\n"; // loops through and prints list
        }
    }
    else{
        std::cerr << "\nFile could not be opened" << fileName << "\n"; // presents error if file not detected
    }
}

int main(){
    getUnique();
}

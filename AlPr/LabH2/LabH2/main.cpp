/***************

Anda Šulca, as21271

H2. Read text from given text file. Count words in given text file by length of words. Print result in another text file. Result file must have pairs of numbers - length and number of words in given file with the length (for example, 1 110, 2 406, 3 632). Words are separated with spaces, separators or end of line.

***************/

#include<iostream>
#include<fstream>

#include <string>
#include <vector>
#include <functional>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>


using namespace std;
//function to find first occurence of predefined characters
string::size_type findAllChars(const string& s, string::size_type n) {

   string::size_type j = s.find(' ',n);
    j = std::min(j,s.find('.',n));
    j = std::min(j,s.find(',',n));
    j = std::min(j,s.find(')',n));
    j = std::min(j,s.find('(',n));
    j = std::min(j,s.find('!',n));
    j = std::min(j,s.find('?',n));
    j = std::min(j,s.find('%',n));
    return j;
}

//function to split line into words
void split(const string& s,
           vector<string>& v) {
   string::size_type i = 0;
   //find the beginning of first word
   string::size_type j = findAllChars(s,0);
   //if no delimiter found, whole string is 1 word
   if (j == string::npos) v.push_back(s);
   //while j is not equal to end of string loop through the string
   while (j != string::npos) {
      //add the found word to vector
      v.push_back(s.substr(i, j-i));
      i = ++j;
      //find the beginning of next word
      j = findAllChars(s,j);
      //if no delimiter is found, the remainder of the string is one word
      if (j == string::npos)
         v.push_back(s.substr(i, s.length()));
   }
}

int main() {
    //open intput file
    std::ifstream inputfile("input.txt");
    fstream outputfile;
    //open output file
    outputfile.open("output.txt",ios::out);
    //create array for word counts

    std::map<int,int> mappedArray;

    //set initial array values to 0
   // for (int i = 0; i < 100; i++) {
   //     counter[i] = 0;
   // }


    if (inputfile.is_open()) {
        std::string line;
        //loop through the file line by line
        while (std::getline(inputfile, line)) {
               vector<string> v;
               //split line into words
               split(line, v);
               //add word lengths to counter
               for (int i = 0; i < v.size(); ++i) {
                  //counter[v[i].length()]++;
                  int v_len = v[i].length();
                  if (v_len > 0) {
                        if (mappedArray.count(v_len) > 0) {
                            mappedArray[v_len] = mappedArray[v_len] + 1;
                          } else {
                            mappedArray[v[i].length()] = 1;
                          }
                  }
               }
        }
        //close input file
        inputfile.close();
    }
    //start from 1 because 0 is not valid length

        for (const auto& [key, value] : mappedArray) {
            outputfile << key << " " << value << "\n";
        }
    //close output file
    outputfile.close();
}

/************
 *
 * Input                         | Desired response Result                            | Actual response
 * ------------------------------+----------------------------------------------------+----------------------------------
 * 1.                            |1-letter: 1; 2-letter: 1; 3-letter: 1; 4-letter: 1; |
 * a aa aaa aaaa
 *
 * 2.                            |2-letter: 7;                                        |
 * aa? aa, aa. aa! aa) aa(
 * aa
 *
 * 3.                            |3-letter: 3;                                        |
 * aaa aaa aaa
 *
 * ***********/

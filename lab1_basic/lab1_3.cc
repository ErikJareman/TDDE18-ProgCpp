#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() 
{
    ifstream ifs{"lab1_3.cc"};
    int wordcount{};
    int total_letters{};
    string s{};
    string longest{};
    string shortest{};

    ifs.peek();
    if(ifs.eof()) {
        cout << "Warning: The file is empty!" << endl;
    } else {
        while (ifs >> s) {
            wordcount++;
            total_letters += s.length();
            if (s.length() > longest.length()) {
                longest = s; 
            } else if (s.length() < shortest.length() or shortest == "") {
                shortest = s;
            }
        }
        cout << "There are " << wordcount << " words in the file." << endl;
        cout << "The shortest word was \"" << shortest << "\" with " << shortest.length() << " character(s)." << endl;
        cout << "The longest word was \"" << longest << "\" with " << longest.length() << " character(s)." << endl;
        cout << "The average length was " << total_letters/static_cast<double>(wordcount) << " character(s)." << endl;
    }
    return 0;
}
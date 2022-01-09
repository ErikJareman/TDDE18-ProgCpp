#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    int i{};
    char c{};
    float f{};
    string s{};

//Output 1
    cout << "Enter one integer: ";
    cin >> i;
    cout << "You entered the integer " << i << "\n\n";
    cin.ignore(1000, '\n');
 
//Output 2
    cout << "Enter four integers: ";
    cin >> i;
    cout << "You entered the integers: ";
    cout << i << " ";
    cin >> i;
    cout << i << " ";
    cin >> i;
    cout << i << " ";
    cin >> i;
    cout << i << " " << "\n\n";
    cin.ignore(1000, '\n');
 
//Output 3
    cout << "Enter one integer and one real number: ";
    cin >> i;
    cin >> f;
    cout << "The real is: " << right << setw(11) << fixed << setprecision(3) << f  << " " << endl;
    cout << "The integer is: " << right << setw(8) << i << "\n\n";
    cin.ignore(1000, '\n');

//Output 4
    cout << "Enter one real and one integer number: ";
    cin >> f;
    cin >> i;
    cout << "The real is: " << setfill('.') << right << setw(11) << fixed << setprecision(3) << f  << " " << endl;
    cout << "The integer is: " << right << setw(8) << i << "\n\n";
    cout << setfill(' ');
    cin.ignore(1000, '\n');
 
//Output 5
    cout << "Enter a character: ";
    cin >> c;
    cout << "You entered: " << c << "\n\n";
    cin.ignore(1000, '\n');
 
//Output 6
    cout << "Enter a word: ";
    cin >> s;
    cout << "The word '" << s << "' has " << s.length() << " character(s)." << "\n\n";
    cin.ignore(1000, '\n');
 
//Output 7
    cout << "Enter an integer and a word: ";
    cin >> i;
    cin >> s;
    cout << "You entered '" << i << "' and '" << s << "'." << "\n\n";
    cin.ignore(1000, '\n');
 
//Output 8
    cout << "Enter a character and a word: ";
    cin >> c >> s;
    cout << "You entered the string \"" << s;
    cout << "\" and the character '" << c << "'." << "\n\n";
    cin.ignore(1000, '\n');

//Output 9
    cout << "Enter a word and a real number: ";
    cin >> s;
    cin >> f;
    cout << "Your entered: \"" << s << "\" and \"" << fixed << setprecision(3) << f << "\".\n\n";
    cin.ignore(1000, '\n');

//Output 10
    cout << "Enter a text-line: ";
    getline(cin, s);
    cout << "Your entered: \"" << s << "\"\n\n";

//Output 11
    cout << "Enter a second text-line: ";
    getline(cin, s);
    cout << "Your entered: \"" << s << "\"\n\n";

//Output 12   
    cout << "Enter three words: ";
    cin >> s;
    cout << "You entered: \'" << s << " ";
    cin >> s;
    cout << s << " ";
    cin >> s;
    cout << s << "\'\n\n";
    cin.ignore(1000, '\n');

    return 0;
}
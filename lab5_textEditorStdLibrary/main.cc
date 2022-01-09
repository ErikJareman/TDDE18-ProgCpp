#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>


namespace txt_operations {

    struct occurance_pair
    {
        std::string word;
        int count;
    };

    std::vector<occurance_pair> 
        getOccuranceVector(const std::vector<std::string>& text)
    {
        std::unordered_map<std::string, int> occuranceMap;
        std::for_each(text.begin(), text.end(),
            [&occuranceMap] (std::string word) {
                occuranceMap[word] += 1;
            }
        );

        std::vector<occurance_pair> occuranceVector;
        std::transform(begin(occuranceMap), end(occuranceMap), 
            std::back_inserter(occuranceVector),
            [](auto const& pair) {
                return occurance_pair {pair.first, pair.second};
            });
        return occuranceVector;
    }

    int getLongestWord(const std::vector<std::string>& text) 
    {
        auto longest = std::max_element(text.begin(), text.end(),
            [](const std::string& a, const std::string& b) {
                return a.size() < b.size();
            }
        );
        return longest->size();
    }

    void frequency(const std::vector<std::string>& text)
    {
        std::vector<occurance_pair> occuranceVector = getOccuranceVector(text);
        std::sort(occuranceVector.begin(), occuranceVector.end(), 
            [] (auto a, auto b) {
                if (a.count == b.count) {
                    return a.word < b.word;
                } else {
                    return a.count > b.count;
                }
            }
        );
        const int longestWord = getLongestWord(text);
        std::for_each(occuranceVector.begin(), occuranceVector.end(),
            [&longestWord] (auto pair) {
                std::cout << std::setw(longestWord) << std::right << pair.word
                    << " " << pair.count << std::endl;
            }
        );
    }

    void table(const std::vector<std::string>& text)
    {
        std::vector<occurance_pair> occuranceVector = getOccuranceVector(text);
        std::sort(occuranceVector.begin(), occuranceVector.end(), 
            [] (occurance_pair a, occurance_pair b) {
                return a.word < b.word;
            }
        );
        const int longestWord = getLongestWord(text);
        std::for_each(occuranceVector.begin(), occuranceVector.end(),
            [&longestWord] (auto pair) {
                std::cout << std::setw(longestWord) << std::left << pair.word
                    << " " << pair.count << std::endl;
            }
        );
    }

    void print(const std::vector<std::string>& text)
    {
        std::copy(text.begin(), text.end(), 
            std::ostream_iterator<std::string>{std::cout, " "});
        std::cout << std::endl;
    }

    void substitute(std::vector<std::string>& text, 
        const std::string& parameter)
    {
        const std::string::size_type split = parameter.find('+');
        std::replace(text.begin(), text.end(), 
            std::string(parameter.substr(0, split)), 
            std::string(parameter.substr(split + 1, parameter.size())));
    }

    void remove(std::vector<std::string>& text, const std::string& parameter)
    {
        text.erase(std::remove(text.begin(), text.end(), parameter), 
            text.end());
    }
}

// --- FIXED ---
//TODO: Do not use exit to terminate your program, since when you do
//the destructors for the different variables are not called. If you
//want to end the program when an unknown operation is found use the
//throw catch structure instead. 

void operationSelector(std::vector<std::string>& text, const std::string& flag,
    const std::string& parameter)
{
    using namespace txt_operations;
    if (flag == "--print") { print(text); }
    else if (flag == "--frequency") { frequency(text); }
    else if (flag == "--table") { table(text); }
    else if (flag == "--substitute") { substitute(text, parameter); }
    else if (flag == "--remove") { remove(text, parameter); }
    else {
        throw std::invalid_argument(flag);
    }
}

int main(int argc, char **argv)
{   
    if (argc < 3) {
        std::cerr << "ERROR: Not enough arguments |"
            << " Given: " << argc << " | Minimum: 3\n";
        return 1;
    }

    std::ifstream file (argv[1]);
    std::vector<std::string> text {
        std::istream_iterator<std::string>{file},
        std::istream_iterator<std::string>{}
    };
    file.close();
    if (text.size() == 0) {
        std::cerr << "ERROR: The file '" << argv[1] << "' is empty or non-existent\n";
        return 1;
    }

    std::vector<std::string> arguments( argv + 2, argv + argc );
    try 
    {
        std::for_each(arguments.begin(), arguments.end(), 
            [&text] (std::string &arg) {
                const std::string::size_type splitAt = arg.find('=');
                operationSelector(
                    text,
                    arg.substr(0, splitAt),
                    arg.substr(splitAt + 1, arg.size())
                );
            }
        );
    } 
    catch (const std::invalid_argument& e)
    {
        std::cerr << "ERROR: Invalid argument '" << e.what() << "'\n";
        return 1;
    }
    return 0;
}

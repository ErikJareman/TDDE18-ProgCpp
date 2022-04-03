#include <iostream>
#include <string>
#include <vector>

class List {
public:
    virtual ~List() = default;
    virtual void display() const = 0;
    virtual void push_back(const std::string& str) = 0;
};

class Enumerate : public List {
private:
    std::vector<std::string> elements{};

public:

    void display() const override {
        for (int i = 0; i < elements.size(); i++) {
            std::cout << i << ": " << elements[i] << std::endl;
        }
        std::cout << std::endl;
    };

    void push_back(const std::string& str) override {
        elements.push_back(str);
    }
};

class Description : public List {
private:
    std::vector<std::pair<std::string, std::string>> entries{};

public:

    void display() const override {
        for (auto it: entries) {
            std::cout << it.first << ":  " << it.second << std::endl;
        }
        std::cout << std::endl;
    };

    void push_back(const std::string& str) override {
        const std::string::size_type splitAt = str.find(' ');
        std::pair<std::string, std::string> tmp{str.substr(0, splitAt), 
            str.substr(splitAt+1, str.length())};
        entries.push_back(tmp);
    };
};



int main()
{
    // Remember to delete any allocated memory

    Enumerate l1{};
    Description l2{};
    std::vector<List*> html_lists{&l1, &l2};
    html_lists[0]->push_back("Nemesis");
    html_lists[0]->push_back("Gloomhaven");
    html_lists[0]->push_back("VirginQueen");
    /*Call push_back on enumerate with "Nemesis"*/
    /*Call push_back on enumerate with "Gloomhaven"*/
    /*Call push_back on enumerate with "VirginQueen"*/


    html_lists[1]->push_back("Nemesis SciFi survival horror games");
    html_lists[1]->push_back("Gloomhaven Fantasy legacy game");
    html_lists[1]->push_back("VirginQueen GMT wargame set in the Elizabethian era");
    /*Call push_back on description with "Nemesis SciFi survival horror games"*/
    /*Call push_back on description with "Gloomhaven Fantasy legacy game"*/
    /*Call push_back on description with "VirginQueen GMT wargame set in the Elizabethian era"*/

    for (List* it: html_lists) {
        it->display();
    }
    /*Iterate through html_lists and call display on each element*/
}

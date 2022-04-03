#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iterator>


int main() {

    std::ifstream file("cipher.txt");

    std::vector<char> container {
        std::istreambuf_iterator<char>{file},
        std::istreambuf_iterator<char>{}
    };
    file.close();

    std::stable_partition(container.begin(), container.end(),
        [] (int n) {return n < 96;});

    std::replace(container.begin(), container.end(), '|', ' ');

    std::copy(container.begin(), container.end(),
        std::ostream_iterator<char>{std::cout, ""});
    
}

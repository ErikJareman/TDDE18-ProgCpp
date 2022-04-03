#include "optimizer.h"
#include <iostream>

Optimizer::Optimizer(const int& init)
    : minimum{init} {}

Optimizer::Optimizer()
    : minimum{0} {}

void Optimizer::set_limit(const int& val) {
    minimum = val;
}

void Optimizer::read(const std::vector<long unsigned int>& ids) {
    for(auto id: ids) {
        count[id] += 1;
    }
}

void Optimizer::print() const {
    for (const auto& [key, value]: count) {
        if (value >= minimum) {
            std::cout << "File " << key << ": " 
                << value << std::endl;
        }
    }
    std::cout << std::endl;
}



int main()
{   
    Optimizer opt{2};
    std::vector<unsigned long int> file_ids1{1, 2, 1, 4, 128, 1, 2, 4};
    std::vector<unsigned long int> file_ids2{4, 1, 1, 4, 128, 128, 5, 1, 4};

    opt.read(file_ids1);
    opt.print();
    opt.set_limit(3);
    opt.print();
    opt.read(file_ids2);
    opt.set_limit(0);
    opt.print();
}

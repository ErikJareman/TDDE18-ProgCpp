#ifndef OPTIMIZER_H
#define OPTIMIZER_H
#include <map>
#include <vector>

class Optimizer{
private:
    std::map<unsigned long int, int> count{};
    int minimum;

public:
    Optimizer(const int& init);
    Optimizer();
    ~Optimizer() = default;

    void set_limit(const int& val);
    void read(const std::vector<long unsigned int>& ids);
    void print() const;
};


#endif //OPTIMIZER.H
#ifndef CIRCUIT_H
#define CIRCUIT_H
#include "component.h"
#include <unordered_map>
#include <vector>

class Circuit
{
    std::string m_name;
    std::vector<Component*> m_components;
    std::unordered_map<std::string, double> m_connectionPoints;
public:
    Circuit(const std::string& name);
    void simulate(const int& iterations, const int& linesToPrint, 
        const double& timeStep);
    void addComponent(Component* component);
    void addConnectionPoint(const std::string& key);
    void printTableHeader() const;
    void printTableRow() const;
};

#endif //CIRCUIT_H

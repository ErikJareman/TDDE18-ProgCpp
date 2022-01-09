#include "circuit.h"
#include <iostream>
#include <iomanip>

Circuit::Circuit(const std::string& name)
{
    m_name = name;
    m_components = std::vector<Component*>();
    m_connectionPoints = std::unordered_map<std::string, double>();
}

void Circuit::simulate(const int& iterations, const int& linesToPrint, 
    const double& timeStep)
{
    printTableHeader();
    int printCount = 0;
    int printStep = iterations / linesToPrint;
    for (int i = 0; i < iterations; i++)
    {
        for (Component* it: m_components)
        {
            it->simulateStep(timeStep); // should only take in timestep
        }
        if (i == printCount) {
            printTableRow();
            printCount += printStep;
        }
    }
    std::cout << std::endl;
}

void Circuit::addComponent(Component* component)
{
    component->targetConnectionPoints(m_connectionPoints[component->
        getPositiveName()], m_connectionPoints[component->getNegativeName()]);
    m_components.push_back(component);
}

void Circuit::addConnectionPoint(const std::string& key) 
{
    m_connectionPoints[key] = 0.0;
}

void Circuit::printTableHeader() const
{
    using std::cout;
    using std::endl;
    for (Component* it: m_components) 
    {
        cout << std::setw(12) << it->getComponentName();
    }
    cout << endl;
    for (int i = 0; i < m_components.size(); i++)
    {
        cout << std::setw(12) << "Volt  Curr";
    }
    cout << endl;
}

void Circuit::printTableRow() const
{
    using std::cout;
    using std::endl;
    cout << std::setprecision(2) << std::fixed;
    for (Component* it: m_components)
    {
        cout << std::setw(6) << it->getVoltage() << "  " << it->getCurrent();
    }
    cout << endl;
}

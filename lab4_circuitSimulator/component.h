#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>

class Component
{
    std::string m_name;
    std::string m_positive_name;
    std::string m_negative_name;
protected:
    double* m_ptr_positive;
    double* m_ptr_negative;
public:
    Component(const std::string& name, const std::string& positive_name, 
        const std::string& negative_name);
    std::string getPositiveName() const;
    std::string getNegativeName() const;
    std::string getComponentName() const;
    double getVoltage() const;
    virtual double getCurrent() = 0;
    virtual void simulateStep(const double& timeStep) = 0;
    void targetConnectionPoints(double& positive, double& negative);
};

#endif //COMPONENT_H
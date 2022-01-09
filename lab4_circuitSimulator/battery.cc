#include "component.h"
#include "battery.h"
#include <iostream>

Battery::Battery(const std::string& name, const std::string& positive, 
    const std::string& negative, const double& voltage)
    : Component(name, positive, negative)
    {
        m_voltage = voltage;
    }

void Battery::simulateStep(const double& timeStep) 
{
    *m_ptr_positive = m_voltage;
    *m_ptr_negative = 0;

}

double Battery::getCurrent()
{
    return 0.0;
}

#include "component.h"
#include "resistor.h"
#include <iostream>

Resistor::Resistor(const std::string& name, const std::string& positive,
    const std::string& negative, const double& resistance)
    : Component(name, positive, negative)
    {
        m_resistance = resistance;
    }

void Resistor::simulateStep(const double& timeStep)
{
    double potentialDiff = *m_ptr_positive - *m_ptr_negative;
    double chargeToMove = potentialDiff / m_resistance * timeStep;
    *m_ptr_positive -= chargeToMove;
    *m_ptr_negative += chargeToMove;
}

double Resistor::getCurrent()
{
    return getVoltage() / m_resistance;
}

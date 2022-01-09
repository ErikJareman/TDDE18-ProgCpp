#include "component.h"
#include "capacitor.h"
#include <iostream>

Capacitor::Capacitor(const std::string& name, const std::string& positive,
    const std::string& negative, const double& capacitance)
    : Component(name, positive, negative)
    {
        m_capacitance = capacitance;
        m_charge = 0;
    }

void Capacitor::simulateStep(const double& timeStep) {
    double potentialDiff = *m_ptr_positive - *m_ptr_negative;
    double chargeToStore = m_capacitance * (potentialDiff - m_charge) * timeStep;
    *m_ptr_positive -= chargeToStore;
    *m_ptr_negative += chargeToStore;
    m_charge += chargeToStore;
}

double Capacitor::getCurrent()
{
    return m_capacitance * ( getVoltage() - std::abs(m_charge) );
}

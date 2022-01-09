#include "component.h"
#include <iostream>

Component::Component(const std::string& name, const std::string& positive_name,
    const std::string& negative_name)
{
    m_name = name;
    m_positive_name = positive_name;
    m_negative_name = negative_name;
    m_ptr_positive = nullptr;
    m_ptr_negative = nullptr;
}

std::string Component::getPositiveName() const { return m_positive_name; }
std::string Component::getNegativeName() const { return m_negative_name; }
std::string Component::getComponentName() const { return m_name; }

double Component::getVoltage() const
{
    return std::abs(*m_ptr_positive - *m_ptr_negative);
}

void Component::targetConnectionPoints(double& positive, double& negative)
{
    m_ptr_positive = &positive;
    m_ptr_negative = &negative;
}

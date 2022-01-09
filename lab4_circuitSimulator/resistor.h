#include "component.h"

class Resistor : public Component
{
    double m_resistance;
public:
    Resistor(const std::string& name, const std::string& positive,
        const std::string& negative, const double& resistance);
    void simulateStep(const double& timeStep);
    double getCurrent();
};

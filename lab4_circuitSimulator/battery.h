#include "component.h"

class Battery : public Component
{
    double m_voltage;
public:
    Battery(const std::string& name, const std::string& positive,
        const std::string& negative, const double& voltage);
    void simulateStep(const double& timeStep);
    double getCurrent();
};

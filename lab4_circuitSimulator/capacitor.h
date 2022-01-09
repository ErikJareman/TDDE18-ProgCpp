#include "component.h"

class Capacitor : public Component
{
    double m_capacitance;
    double m_charge;
public:
    Capacitor(const std::string& name, const std::string& positive,
        const std::string& negative, const double& capacitance);
    void simulateStep(const double& timeStep);
    double getCurrent();
};

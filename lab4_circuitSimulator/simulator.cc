#include <iostream>
#include "circuit.h"
#include "component.h"
#include "battery.h"
#include "resistor.h"
#include "capacitor.h"

int main(int argc, char **argv)
{   
    int iterations;
    int linesToPrint;
    double timeStep;
    double voltage;

    if (argc != 5) {
    std::cout << "ERROR: Incorrect number of input variables..." << std::endl;
    return 0;
    }
    try { iterations = std::stoi( argv[1] ); }
    catch (...) 
    {
        std::cout << "ERROR: Incorrect number of iterations, ";
        std::cout << "should be int..." << std::endl;
        return 0;
    }
    try { linesToPrint = std::stoi( argv[2] ); }
    catch (...) 
    {
        std::cout << "ERROR: Incorrect number of lines to print, ";
        std::cout << "should be int..." << std::endl;
        return 0;
    }
    try { timeStep = std::stod( argv[3] ); }
    catch (...) 
    {
        std::cout << "ERROR: Incorrect timeStep value, ";
        std::cout << "should be double..." << std::endl;
        return 0;
    }
    try { voltage = std::stod( argv[4] ); }
    catch (...) 
    {
        std::cout << "ERROR: Incorrect voltage value, ";
        std::cout << "should be double..." << std::endl;
        return 0;
    }

    { // Circuit 1
        Circuit C1("C1");
        C1.addConnectionPoint("P");
        C1.addConnectionPoint("R124");
        C1.addConnectionPoint("N");
        C1.addConnectionPoint("notNamed");
        Battery B1("Bat", "P", "N", voltage);
        Resistor R1("R1", "R124", "P", 6);
        Resistor R2("R2", "notNamed", "R124", 4);
        Resistor R3("R3", "N", "notNamed", 8);
        Resistor R4("R4", "N", "R124", 12);
        C1.addComponent(&B1);
        C1.addComponent(&R1);
        C1.addComponent(&R2);
        C1.addComponent(&R3);
        C1.addComponent(&R4);
        C1.simulate(iterations, linesToPrint, timeStep);
    }

    { // Circuit 2
        Circuit C2("C2");
        C2.addConnectionPoint("P");
        C2.addConnectionPoint("L");
        C2.addConnectionPoint("R");
        C2.addConnectionPoint("N");
        Battery B1("Bat", "P", "N", voltage);
        Resistor R1("R1", "L", "P", 150);
        Resistor R2("R2", "R", "P", 50);
        Resistor R3("R3", "R", "L", 100);
        Resistor R4("R4", "N", "L", 300);
        Resistor R5("R5", "N", "R", 250);
        C2.addComponent(&B1);
        C2.addComponent(&R1);
        C2.addComponent(&R2);
        C2.addComponent(&R3);
        C2.addComponent(&R4);
        C2.addComponent(&R5);
        C2.simulate(iterations, linesToPrint, timeStep);
    }

    { // Circuit 3
        Circuit C3("C3");
        C3.addConnectionPoint("P");
        C3.addConnectionPoint("L");
        C3.addConnectionPoint("R");
        C3.addConnectionPoint("N");
        Battery B1("Bat", "P", "N", voltage);
        Resistor R1("R1", "L", "P", 150);
        Resistor R2("R2", "R", "P", 50);
        Capacitor Cap1("C3", "R", "L", 1.0);
        Resistor R3("R4", "N", "L", 300);
        Capacitor Cap2("C5", "N", "R", 0.75);
        C3.addComponent(&B1);
        C3.addComponent(&R1);
        C3.addComponent(&R2);
        C3.addComponent(&Cap1);
        C3.addComponent(&R3);
        C3.addComponent(&Cap2);
        C3.simulate(iterations, linesToPrint, timeStep);
    }
}

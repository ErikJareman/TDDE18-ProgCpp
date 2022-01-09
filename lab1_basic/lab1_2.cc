#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    float price{-1};
    float last{-1};
    float stride{-1};
    float tax{-1};
    cout << "INPUT PART" << endl << "==========" << endl;
    
    cout << "Enter price price: ";
    cin >> price;
    while (price < 0) {
        cout << "ERROR: price price must be at least 0 (zero) SEK" << endl;
        cout << "Enter price price: ";
        cin >> price;
    }

    cout << "Enter last price : ";
    cin >> last;
    while (last < 0) {
        cout << "ERROR: Last price must be at least 0 (zero) SEK" << endl;
        cout << "Enter last price : ";
        cin >> last;
    }

    cout << "Enter stride     : ";
    cin >> stride;
    while (stride < 0.01) {
        cout << "ERROR: Stride must be at least 0.01" << endl;
        cout << "Enter stride     : ";
        cin >> stride;
    }

    cout << "Enter tax percent: ";
    cin >> tax;
    while (tax < 0 || tax > 100) {
        cout << "ERROR: Tax percentage must be between 0 and 100" << endl;
        cout << "Enter tax percent: ";
        cin >> tax;
    }

    cout << fixed << setprecision(2) << right;
    cout << "\nTAX TABLE" << endl << "=========" << endl;
    cout << setw(12) << "Price" << setw(17) << "Tax" << setw(20) << "Price with tax" << endl;
    cout << "-------------------------------------------------" << endl;

    while (price <= last) {
        cout << setw(12) << price << setw(17) << price*tax/100 << setw(20) << price + price*tax/100 << endl;
     price += stride;
    }
    cout << endl;

    return 0;
}
#include<iostream>
#include "Clock.h"

using namespace std;

int main() {
    cout << "Testing Clock class with clock one" << endl;
    Clock one;
    one.show();
    cout << "Using the tick function..." << endl;
    one.tick();
    one.show();
    cout << "Using the toggleFormat function..." << endl;
    one.toggleFormat();
    one.show();
    cout << endl;

    cout << "Testing Clock class with clock two" << endl;
    Clock two(23, 59, 59);
    two.show();
    cout << "Using the tick function..." << endl;
    two.tick();
    two.show();
    cout << "Using the toggleFormat function..." << endl;
    two.toggleFormat();
    two.show();
    cout << endl;

    cout << "Testing Clock class with clock three" << endl;
    Clock three(12, 0, 0);
    three.show();
    cout << "Using the toggleFormat function..." << endl;
    three.toggleFormat();
    three.show();
    cout << endl;

    cout << "Testing Clock class with clock four" << endl;
    Clock four(15, 31, 45);
    four.show();
    cout << "Using the toggleFormat function..." << endl;
    four.toggleFormat();
    four.show();

    return 0;
}

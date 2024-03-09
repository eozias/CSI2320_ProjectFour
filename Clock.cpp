#include "Clock.h"

using namespace std;

int main() {
    cout << "Testing Clock class with clock one" << endl;
    Clock one;
    one.show();
    one.tick();
    one.show();
    one.toggleFormat();
    one.show();

    cout << "Testing Clock class with clock two" << endl;
    Clock two(23, 59, 59);
    two.show();
    two.tick();
    two.show();
    two.toggleFormat();
    two.show();

    cout << "Testing Clock class with clock three" << endl;
    Clock three(12, 0, 0);
    three.show();
    three.toggleFormat();
    three.show();

    cout << "Testing Clock class with clock four" << endl;
    Clock four(15, 31, 45);
    four.show();
    four.toggleFormat();
    four.show();

    return 0;
}
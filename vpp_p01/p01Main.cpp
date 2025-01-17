#include <cmath>
#include <iostream>
#include "komponente.h"
#include "bohrung.h"
#include "fraesung.h"
#include "komponentenelement.h"
#include "komponentenList.h"

using std::cout;
using std::endl;

int main() {
    Bohrung b1{1., 2., 8.};
    Bohrung b2{10., 8., 7.};
    Bohrung b3{7., 2., 5.};
    Bohrung b4{2., 6., 4.};

    Fraesung f1{2., 3., 5., 2.*sqrt(2), 45*M_PI/180};
    Fraesung f2{6., 7., 6., 3., 0};
    Fraesung f3{17., 6., 4., 4.*sqrt(2), 225*M_PI/180};

    b1.output(cout);
    cout << endl;
    f1.output(cout);
    cout << endl;
    b3.output(cout);
    cout << endl;
    f2.output(cout);
    cout << endl;
    b4.output(cout);
    cout << endl;
    f3.output(cout);
    cout << endl;
    b2.output(cout);

};

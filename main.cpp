#include <iostream>
#include "onp_calc.h"
using namespace std;

int main() {
    auto ops = onp_calc<int>::operations();
    cout<<ops['+'](3,4)<<" "<<ops['-'](3,4)<<" "<<ops['*'](3,4)<<" "<<ops['/'](3,4)<<endl;
    try {
        cout << ops['w'](3, 5) << endl;
    } catch (exception& e) {
        cout<<e.what()<<endl;
    }
    return 0;
}
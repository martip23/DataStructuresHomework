#include <iostream> // Provides cout, cin and endl
#include <iomanip>  // Provides setw for setting output width
#include <cstdlib>  // Provides srand and rand
#include <ctime>     // provides time(for random seed)
#include <cassert>
#include "SP18_3358_1_Martinez_Patrick_Hillier_Blake_PG1.cpp"

using namespace std;

int main () {

    int arrayx[] = {2,7,6,9,5,1,4,3,8};
    int arrayy[3][3];
    for (int i = 0, k = 0; i < 3; i++, k++) {
        for (int j = 0; j < 3; j++, k++) {
            array1[i][j] = array2[k];
        }
    }

    isSpecialArray(array1);

    cout << "FINISHED" << endl;

    return 0;
}

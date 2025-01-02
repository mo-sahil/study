#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int sum = 0;
        int counter = 1; 

        while (true) {
            if (counter % 2 != 0) {
                sum -= (2 * counter - 1);
                if (abs(sum) > n) {
                    cout << "Sakurako" << endl;
                    break;
                }
            } else { 
                sum += (2 * counter - 1);
                if (abs(sum) > n) {
                    cout << "Kosuke" << endl;
                    break;
                }
            }
            counter++;
        }
    }
    return 0;
}

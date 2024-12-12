#include <bits/stdc++.h>
using namespace std;

// triangle ki puri width aur depth ko accumulate karne ke liye 2D array
// glasses[i][j] me ith row aur jth coulumn pe stored water level hoga
double glasses[1000][1000];

// iska use karke r rows ko bharenge pura
// K: Total amount of water to pour.
// R: Row number of the target glass (0-based index).
// C: Column number of the target glass (0-based index).
void fillWaterInGlasses(double K, int R) {
    glasses[0][0] = K; // sara pani pahle glass me dala shuru me fir overflow hoke niche jayega

    // ye loops pani bharenge
    // isme outer loop rows ko target karega aur inner loop har ek glass ko
    for (int level = 0; level < R; level++) {
        for (int j = 0; j <= level; j++) {
            if (glasses[level][j] > 1) { 
                // overflow logic: agar pani 1 unit se jyada hai to sara extra pani us glass ke niche ke 2 glass me equally distribute ho jayega
                double extraWater = glasses[level][j] - 1;
                glasses[level][j] = 1; 
                glasses[level + 1][j] += extraWater / 2;    
                glasses[level + 1][j + 1] += extraWater / 2;
            }
        }
    }
}

int main() {
    // ye input hai
    int K, R, C;
    cin >> K >> R >> C;

    // ye function call hai
    fillWaterInGlasses(K, R);

    // ye print kar rahe hen ki kitna pani hai
    // min is liye lagaya kyunki jo glasses full ho gaye hen unme stored to pani jyada hai jo unhe actual mila tha but unhone niche distribute kar diya
    cout << min(1.0, glasses[R][C]) << endl;

    return 0;
}
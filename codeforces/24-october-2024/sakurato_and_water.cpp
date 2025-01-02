#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }

        int ops = 0;

        for (int diag = 0; diag < n; diag++)
        {
            int mn = 10000;
            for (int i = 0, j = diag; j < n; i++, j++)
            {
                if (arr[i][j] < 0)
                {
                    for (int k = 0; i + k < n && j + k < n; k++)
                    {
                        mn = min(mn, arr[i + k][j + k]);
                    }
                }
            }
            
            if (mn < 0)
                ops += -mn;
        }

        cout << ops << endl;
    }

    return 0;
}

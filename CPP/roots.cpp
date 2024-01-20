#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    /* determinant = b*b-4*a*c
    if determinant > 0
        roots = (-b + sqrt(determinant))/2 , (-b - sqrt(determinant))/2
    else if determinant = 0 
        roots = -b/2a (both equal)
    else
        roots imaginary
        real part = -b/2a
        imaginary part = i*(sqrt(-determinant))/2
    */
    float a, b, c, determinant, realpart, imaginarypart, root1, root2;

    cout << "Enter coefficients a, b, c: ";
    cin >> a >> b >> c;

    determinant = b*b - 4*a*c;

    if (determinant > 0)
    {
        root1 = ((-1*b) + sqrt(determinant))/(2*a);
        root2 = ((-1*b) - sqrt(determinant))/(2*a);

        cout << "Roots are " << root1 << " and " << root2 << endl;
    }
    else if ( determinant == 0)
    {
        root1 = -b/(2*a);

        cout << "Both roots are same. root = " << root1;
    }
    else
    {
        realpart = -b/(2*a);
        imaginarypart = (sqrt(-determinant))/(2*a);

        cout << "roots are imaginary. \nRoot1 = " << realpart << " + i*" << imaginarypart << endl << "root2 = " << realpart << " - i*" << imaginarypart;
    }

    return 0;
}
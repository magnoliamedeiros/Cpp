#include<iostream>
using namespace std;

int main()
{
    int x[] = {5,6};

    // Nesses dois cout é apresentado a posição da matriz x normal e somada a 1
    cout<< "X = "<< x << "\n";
    cout << "X + 1 = " << x + 1 << "\n";

    // Nesses dois cout é apresentado os valores contidos na matriz x normal e somado a 1
    cout <<"*X = " << *x << "\n";
    cout <<"*(X + 1) = " << *(x + 1 ) << "\n";

    cout << "Subtraindo 1 da variavel X\n";
    cout << "X + 1 = " << x + 1 << "\n";
    cout << "(X + 1) - 1 = " << (x + 1) - 1 << "\n";
    cout << "*X + 1 = " << *x + 1 << "\n";
    cout << "*(X + 1) - 1 = " << *(x + 1) - 1 << "\n";
    return 0;
}

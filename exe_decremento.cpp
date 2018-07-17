#include <iostream>

using namespace std;

int main ()
{
     int variavel1 = 1;
     int decremento1 = variavel1--;

     cout << "Decremento depois da variável: " << decremento1 << "\n";

     int variavel2 = 1;
     int decremento2 = --variavel2;

     cout << "Decremento antes da variável: " << decremento2 << "\n";

     return 0;
}

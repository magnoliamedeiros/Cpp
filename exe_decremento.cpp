#include <iostream>

using namespace std;

int main ()
{
     // int variavel1 = 1;
     // int decremento1 = variavel1--;
     //
     // cout << "Decremento depois da variável: " << decremento1 << "\n";
     //
     // int variavel2 = 1;
     // int decremento2 = --variavel2;
     //
     // cout << "Decremento antes da variável: " << decremento2 << "\n";

     int v1;
     v1 = 1;

     // Impressão do valor antes do decremento
     cout << "Sem o decremento: " << v1 << endl;

     // Decrementando, lembrando que temos três formas para isto:
     // v1 = v1 - 1;
     // v1-=1;
     v1--;

     //Impressão após o incremento
     cout << "Valor decrementado: " << v1 << endl;
     return 0;
}

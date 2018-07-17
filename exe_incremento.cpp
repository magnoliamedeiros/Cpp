#include <iostream>

using namespace std;

int main(){
     int variavel1 = 1;
     int incremento1 = variavel1++;

     cout << "Incremento depois da variável: " << incremento1 << "\n";

     int variavel2 = 1;
     int incremnto2 = ++variavel2;

     cout << "Incremento antes da variável: " << incremnto2 << "\n";

     return 0;
}

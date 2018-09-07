#include <iostream>

using namespace std;

int main(){
     // int variavel1 = 1;
     // int incremento1 = variavel1++;
     //
     // cout << "Incremento depois da variável: " << incremento1 << "\n";
     //
     // int variavel2 = 1;
     // int incremnto2 = ++variavel2;
     //
     // cout << "Incremento antes da variável: " << incremnto2 << "\n";

     int v1, v2;

     v1 = 1;
     v2 = 10;

     // Impressão do valor antes de incrementar
     cout << "Sem o incremento: " << v1 << endl;

     // Incrementando, lembrando que temos três formas para isto:
     // v1 = v1 + 1;
     // v1+=1;
     v1++;

     //Impressão após o incremento
     cout << "Valor incrementado: " << v1 << endl;

     return 0;
}

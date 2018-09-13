#include<iostream>
using namespace std;
// um variável 'const' são “variáveis” que não podem ter seu valor modificado pelo programa.
const float gravidade = 9.78;
int main(){
     int valor = 5;
     float resultado = valor * gravidade;
     cout << "O resultado obtido deve ser: " << resultado << endl;
     return 0;
}

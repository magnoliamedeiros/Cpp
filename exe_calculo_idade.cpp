#include <iostream>

using namespace std;

int main(){
     int ano_atual, ano_nasc, idade;

     cout << "Em que ano nós estamos? ";
     cin >> ano_atual;

     cout << "Em que ano você nasceu? ";
     cin >> ano_nasc;

     idade = ano_atual - ano_nasc;

     cout << "A sua idade é: " << idade;

     cout << endl << "Acabou!";

     return 0;
}

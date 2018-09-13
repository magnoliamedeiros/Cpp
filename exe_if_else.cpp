#include<iostream>
using namespace std;
int main(){
     // Estado da lâmpada: 0-Apagada, 1-Acesa, qualquer outro valor 'lâmpada com problema'
     int lampada = 1;

     if (lampada == 0) {
          cout << "Lâmpada apagada!";
     } else if (lampada == 1) {
          cout << "Lâmpada acesa!";
     } else {
          cout << "Lâmpada com problema!";
     }
     return 0;
}

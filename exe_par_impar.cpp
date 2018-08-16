#include <iostream>
#include <cstdlib>

using namespace std;

int main (){
    int num;
    int escolha;
    while (escolha != 0) //enquanto sua escolha for diferente de 0
    {
        cout << "Digite um numero: ";
        cin >> num;
        if (num % 2 == 0){
            cout << "Este numero eh par!\n";
       } else {
            cout << "Este numero eh impar!\n";
       }
       cout << "\nDeseja continuar? (Sim, digite 1 - Não digite 0): ";
       cin >> escolha;
    }
    cout << "\nFim!";
}

#include <iostream>

using namespace std;

int main(){
    int vetor[5];
    int aux = 0;

    for(int i = 0; i < 5; i++){
        cout << "Digite um número para a " << i+1 << "ª posição: ";
        cin >> vetor[i];
    }

    cout << "Ordem de leitura: ";

    for(int i = 0; i < 5; i++){
        cout << vetor[i] << " ";
    }

    cout << "\n";

    cout << "Ordem inversa da leitura: ";
    for(int i=4; i >= 0; i--){
        cout << vetor[i] << " ";
    }

    cout << "\n";

    return 0;
}

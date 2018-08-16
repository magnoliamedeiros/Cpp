#include <iostream>
#include <iomanip>

using namespace std;

int main(){

     double reais, dolares;

     cout << "Quantos Reais você têm? R$ ";
     cin >> reais;

     dolares = reais / 3.88;

     cout.precision(4);
     cout << "Você tem US$? " << dolares;

     return 0;
}

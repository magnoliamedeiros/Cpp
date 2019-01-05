#include<iostream>
using namespace std;

int main() {
     int num, i, fat;
     cout << "Digite um numero: ";
     cin >> num;

     fat = 1;

     for (i = 2; i <= num; i++) {
          // fat *= i;
          fat = fat * i;
     }
     cout << "O fatoria de " << num << " eh igual " << fat << endl;
     return 0;
}

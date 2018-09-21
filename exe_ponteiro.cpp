#include<iostream>
using namespace std;
int main(){
     int variavel = 50;
     int *ponteiro = &variavel;
     int *ponteiro2 = ponteiro;

     cout << *ponteiro << "\n" << *ponteiro2 << "\n";
     cout << ponteiro << "\n" << ponteiro2 << "\n";
     return 0;
}

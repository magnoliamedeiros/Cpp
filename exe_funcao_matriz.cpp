#include<iostream>
using namespace std;

// Assinatura do método
int soma(int m[5]);

int main(){
     int mat[5] = {5,2,6,3,1};
     cout << soma(mat);
     cout << "\nFim...";
     return 0;
}

int soma(int m[5]){
     int total = 0;
     for(int i=0; i<5; i++){
          total = total + m[i];
     }
     return total;
}

#include<iostream>

using namespace std;

int main(){
     int linhas, colunas;
     float notas[2][3] = {
          {2,5,8},
          {9,3,5}
     };
     for(linhas=0; linhas<=1; linhas++){
          for(colunas=0; colunas<=2; colunas++){
               cout << notas[linhas][colunas] << " ";
          }
          cout << "\n";
     }
     return 0;
}

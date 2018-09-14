#include<iostream>
using namespace std;
int main(){
     int d1, d2, d3;
     int matriz[2][3][2] = {
          {{2,1},{3,4},{5,7}},
          {{5,6},{7,2},{9,4}}
     };
     for(d1=0; d1<=1; d1++){
          for(d2=0; d2<=2; d2++){
               cout << "\n";
               for(d3=0; d3<=1; d3++){
                    cout << matriz[d1][d2][d3] << " ";
               }
          }
          cout << "\n";
     }
     return 0;
}

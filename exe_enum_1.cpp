
#include<iostream>

using namespace std;

int main()
{
   enum semana
   {
       segunda, terca, quarta, quinta, sexta, sabado, domingo
   };

   semana s;

   s = semana(1);

   if(s == terca)
   {
        cout << "Hoje é terça-feira!";
   }

    return 0;
}

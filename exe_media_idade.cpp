#include<iostream>
using namespace std;
int main()
{
      int idade, , num, media=0, cont=0;

      cout << "Digite quantas idades deseja calcular...: ";
      cin >> num;

      while(cont < num)
      {
           cout << "Digite uma idade...: ";
           cin >> idade;

           media = media + idade;
           cont++;
      }

      cout << "A média das idade informadas é...: " << media / num;

      return 0;
}

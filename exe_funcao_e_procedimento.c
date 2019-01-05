#include<stdio.h>
#include<conio.h>

float fmedia(float n1, float n2) //Função
{
      float m = 0;
      m = (n1 + n2)/2;
      return m;
}

float pmedia() //Procedimento
{
      float n1 = 0, n2 = 0, m = 0;

      printf("Digite a nota 1 do aluno: ");
      scanf("%f", &n1);
      printf("Digite a nota 2 do aluno: ");
      scanf("%f", &n2);

      m = (n1 + n2)/2;
      printf("\n\nA media do aluno foi %6.2f", m);
}

main()
{
      float num1 = 0, num2 = 0;
      int op = 0;

      printf("Escolha uma das duas opcoes abaixo\n");
      printf("\n=========================================\n");
      printf("\nExibir media por Function? Digite 1");
      printf("\nExibir media por Procedure? Digite 2\n");
      scanf("%d", &op);

      switch (op)
      {

       case 1:
            {
                 printf("Digite a nota 1 do aluno: ");
                 scanf("%f", &num1);
                 printf("Digite a nota 2 do aluno: ");
                 scanf("%f", &num2);

                 printf("\n\nA media do aluno foi %6.2f", fmedia(num1, num2));

                 break;
             }

       case 2:
            {
                 pmedia();
                 break;
            }
       }

getch();
}

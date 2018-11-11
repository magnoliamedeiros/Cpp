#include <stdio.h>
#include <iostream>

using namespace std;

struct complexo{
	double real;
	double imaginario;
};

complexo soma(complexo* num1, complexo* num2)
{
	complexo tempsoma;
	tempsoma.real = num1->real + num2->real;
	tempsoma.imaginario = num1->imaginario + num2->imaginario;
	return tempsoma;
}

complexo multiplica(complexo* num1, complexo* num2)
{
	complexo tempmult;
	tempmult.real = num1->real * num2->real - num1->imaginario * num2->imaginario;
	tempmult.imaginario = num1->real * num2->imaginario + num1->imaginario * num2->real;
	return tempmult;
}

complexo inverte(complexo* pnum)
{
	complexo temp;
	temp.real = (-1) * pnum -> real;
	temp.imaginario = (-1) * pnum -> imaginario;
	return temp;
}

void escreve(complexo* num)
{
	printf("%.2f + %.2fi\n", num -> real, num -> imaginario);
}

void setcomplex(complexo* pnum, double real, double imagin)
{
	pnum -> real = real;
	pnum -> imaginario = imagin;
}

int main(){
	complexo comp1;
	complexo comp2;
	double r1,r2;
	printf ("Digite a parte real do n Complexo 1: ");
	cin >> r1;
	printf ("Digite a parte imaginaria do n Complexo 1: ");
	cin >> r2;
	setcomplex(&comp1, r1, r2);
	printf ("Digite a parte real do n Complexo 2: ");
	cin >> r1;
	printf ("Digite a parte imaginaria do n Complexo 2: ");
	cin >> r2;
	setcomplex(&comp2, r1, r2);

	printf ("Complexo 1: ");
	escreve(&comp1);
	printf ("Complexo 2: ");
	escreve(&comp2);

	printf ("Soma de Complexo 1 e Complexo 2: ");
	complexo ress = soma(&comp1, &comp2);
	escreve(&ress);

	printf ("Produto do Complexo 1 e Complexo 2: ");
	complexo resm = soma(&comp1, &comp2);
	escreve(&resm);
	printf ("Negativo do Complexo 1: ");
	complexo resi = inverte(&comp1);
	escreve(&resi);
	printf ("Negativo do Complexo 2: ");
	complexo resi2 = inverte(&comp2);
	escreve(&resi2);

	return 0;
}

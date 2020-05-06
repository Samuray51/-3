#ifndef _Function_H_
#define  _Function_H_
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<errno.h>
#include<windows.h>
typedef struct
{
	int *Bignumber1;
	int *Bignumber2;
	int *Bignumber3;
} BigInt;
int ScanNumber(char *mas);
int ProverkaNaSymbol(char *mas, int i);
void IntNumber(char *mas, int *mas1, int k);
int Comparison(int *p1, int *p2, int k1, int k2);
void Sign(char sign);
void SumMass(int h, int k1, int k2, int k3, BigInt *p);
int RazMass(int h, int sign, int k1, int k2, int k3, BigInt *p);
int Summa(int k1, int k2, BigInt *p);
int Raznost(int k1, int k2, BigInt *p);
void SummaMass(int *mas, BigInt *p, int k3, int k);
void SummaMass(int **mas, int *length, BigInt *p, int k1, int k2, int k);
int Umnojenie(int k1, int k2, BigInt *p);
void SummaMas(int *mas, int k, int *mas1, int k1);
void UmnojenieMas(int **mas, int *length, BigInt *p, int k2, int k, int k3, int *mas1, int k1);
void DelenieStolbikom(int k1, int k2, int k3, BigInt *p);
int Delenie(int k1, int k2, BigInt *p);
void PrintAndFree(int k3, BigInt *p);
#endif


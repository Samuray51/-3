//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<errno.h>
#include<windows.h>
typedef struct
{
	int *Bignumber1;
	int *Bignumber2;
	int *Bignumber3;
} BigInt;

//Ввод длинных чисел с клавиатуры
int ScanNumber(char *mas)
{
	int j = 0, j1 = 0, i = 0;
	while (1)
	{
		scanf_s("%c", &mas[i], 1);
		if (mas[i] == '\n')
		{
			break;
		}
		i = i + 1;
	}
	for (j; j < i; j++)
	{
		if (mas[j] == '-' && j == 0)
		{
			j++;
		}
		if (mas[j] < '0' || mas[j] > '9')
		{
			printf("Не число!\n");
			system("pause");
			exit(1);
		}
	}
	if (mas[0] == '-')
	{
		j1 = i-1;
	}
	else
	{
		j1 = i;
	}
	return j1;
}


//Ввод чисел из файла
int ProverkaNaSymbol(char *mas, int i)
{
	int j = 0, j1 = 0;
	for (j; j < i; j++)
	{
		if (mas[j] == '-' && j == 0)
		{
			j++;
		}
		if (mas[j] < '0' || mas[j] > '9')
		{
			printf("Не число!\n");
			system("pause");
			exit(1);
		}
	}
	if (mas[0] == '-')
	{
		j1 = i - 1;
	}
	else
	{
		j1 = i;
	}
	return j1;
}



//Эта фунеция проверяет на символы
int SYMBOL(FILE *X)
{
	char symbol;
	int pr = 0;
	while (!feof(X))
	{
		fscanf_s(X, "%c", &symbol, 1);
		if ((pr == 32) || (pr == 0) || (pr == 13))
		{
			if (!((symbol == 32) || (symbol == 45) || ((symbol >= 48) && (symbol <= 57))))
			{
				printf("Некорректные символы или файл пуст.\n");
				system("pause");
				exit(1);
			}
		}
		if ((pr >= 48) && (pr <= 57))
		{
			if (!((symbol == 32) || (symbol == 10) || ((symbol >= 48) && (symbol <= 57))))
			{
				printf("Некорректные символы или файл пуст\n");
				system("pause");
				exit(1);
			}
		}
		if (pr == 45) {
			if (!((symbol >= 48) && (symbol <= 57))) {
				printf("Некорректные символы или файл пуст\n");
				system("pause");
				exit(1);
			}
		}
		pr = symbol;
	}
	fseek(X, 0, SEEK_SET);
	return 0;
}




//Эта функция переводит символы в цифра
void IntNumber(char *mas, int *mas1, int k)
{
	int i = 0, j = 0, sign = 1;
	if (mas[0] == '-')
	{
		sign = -1;
		i = 1;
		for (i; i <= k; i++)
		{
			mas1[j] = mas[i] & 0x0F;
			j = j + 1;
		}
	}
	else
	{
		sign = 1;
		i = 0;
		for (i; i < k; i++)
		{
			mas1[j] = mas[i] & 0x0F;
			j = j + 1;
		}
	}
	mas1[0] = mas1[0] * sign;
}



//Эта функция смотрит кто больше
int Comparison(int *p1, int *p2, int k1, int k2)
{
	int i = 0, count = 0, n = 0;
	if (k1 > k2)
	{
		n=1;
	}
	else if (k2 > k1)
	{
		n=2;
	}
	else if (k2 == k1)
	{
		for (i = 0; i < k1; i++)
		{
			if (p1[i] > p2[i])
			{
				n = 1;
				break;
			}
			if (p2[i] > p1[i])
			{
				n = 2;
				break;
			}
			if (p2[i] == p1[i])
			{
				count++;
			}
		}
		if (count == k1)
		{
			n = 0;
		}
	}
	return n;
}



//Эта функция проверяет знак
void Sign(char sign)
{
	if ((sign != '+') && (sign != '-') && (sign != '*') && (sign != '/'))
	{
		printf("Нет такого знака!");
		system("pause");
		exit(1);
	}
}



//Эта фукция складывает массивы для 3 случаев
void SumMass(int h, int k1, int k2, int k3, BigInt *p)
{
	int n = 0;
	if (h == 1)
	{
		while (k2 > -1)
		{
			p->Bignumber3[k3] = p->Bignumber1[k1] + p->Bignumber2[k2] + n;
			n = 0;
			if (p->Bignumber3[k3] > 9)
			{
				p->Bignumber3[k3] = p->Bignumber3[k3] % 10;
				n = 1;
			}
			k3 = k3 - 1;
			k2 = k2 - 1;
			k1 = k1 - 1;
		}
		while (k1 > -1)
		{
			p->Bignumber3[k3] = p->Bignumber1[k1] + n;
			n = 0;
			if (p->Bignumber3[k3] > 9)
			{
				p->Bignumber3[k3] = p->Bignumber3[k3] % 10;
				n = 1;
			}
			k3 = k3 - 1;
			k1 = k1 - 1;
		}
		p->Bignumber3[0] = p->Bignumber3[0] + n;
	}
	else if (h == 2)
	{
		while (k1 > -1)
		{
			p->Bignumber3[k3] = p->Bignumber1[k1] + p->Bignumber2[k2] + n;
			n = 0;
			if (p->Bignumber3[k3] > 9)
			{
				p->Bignumber3[k3] = p->Bignumber3[k3] % 10;
				n = 1;
			}
			k3 = k3 - 1;
			k2 = k2 - 1;
			k1 = k1 - 1;
		}
		while (k2 > -1)
		{
			p->Bignumber3[k3] = p->Bignumber2[k2] + n;
			n = 0;
			if (p->Bignumber3[k3] > 9)
			{
				p->Bignumber3[k3] = p->Bignumber3[k3] % 10;
				n = 1;
			}
			k3 = k3 - 1;
			k2 = k2 - 1;
		}
		p->Bignumber3[0] = p->Bignumber3[0] + n;
	}
	else if (h == 0)
	{
		while (k2 > -1)
		{
			p->Bignumber3[k3] = p->Bignumber1[k1] + p->Bignumber2[k2] + n;
			n = 0;
			if (p->Bignumber3[k3] > 9)
			{
				p->Bignumber3[k3] = p->Bignumber3[k3] % 10;
				n = 1;
			}
			k3 = k3 - 1;
			k2 = k2 - 1;
			k1 = k1 - 1;
		}
		while (k1 > -1)
		{
			p->Bignumber3[k3] = p->Bignumber1[k1] + n;
			n = 0;
			if (p->Bignumber3[k3] > 9)
			{
				p->Bignumber3[k3] = p->Bignumber3[k3] % 10;
				n = 1;
			}
			k3 = k3 - 1;
			k1 = k1 - 1;
		}
		p->Bignumber3[0] = p->Bignumber3[0] + n;
	}
}



//Эта фукция находит разность массивы для 3 случаев
int RazMass(int h, int sign, int k1, int k2, int k3, BigInt *p)
{
	int i = 0, j;
	j = k3 + 1;
	if (h == 1)
	{
		while (k2 > -1)
		{
			if (p->Bignumber1[k1] >= p->Bignumber2[k2])
			{
				p->Bignumber3[k3] = p->Bignumber1[k1] - p->Bignumber2[k2];
			}
			else
			{
				p->Bignumber3[k3] = (p->Bignumber1[k1] + 10) - p->Bignumber2[k2];
				i = k1 - 1;
				while (p->Bignumber1[i] == 0)
				{
					p->Bignumber1[i] = 9;
					i = i - 1;
				}
				p->Bignumber1[i] = p->Bignumber1[i] - 1;
			}
			k2 = k2 - 1;
			k1 = k1 - 1;
			k3 = k3 - 1;
		}
		while (k1 > -1)
		{
			p->Bignumber3[k3] = p->Bignumber1[k1];
			k1 = k1 - 1;
			k3 = k3 - 1;
		}
		if (sign == 1)
		{
			i = 0;
			while (p->Bignumber3[i] == 0)
			{
				i++;
			}
			p->Bignumber3[i] = p->Bignumber3[i] * (-1);
		}
	}
	else if (h == 2)
	{
		while (k1 > -1)
		{
			if (p->Bignumber2[k2] >= p->Bignumber1[k1])
			{
				p->Bignumber3[k3] = p->Bignumber2[k2] - p->Bignumber1[k1];
			}
			else
			{
				p->Bignumber3[k3] = (p->Bignumber2[k2] + 10) - p->Bignumber1[k1];
				i = k2 - 1;
				while (p->Bignumber2[i] == 0)
				{
					p->Bignumber2[i] = 9;
					i = i - 1;
				}
				p->Bignumber2[i] = p->Bignumber2[i] - 1;
			}
			k2 = k2 - 1;
			k1 = k1 - 1;
			k3 = k3 - 1;
		}
		while (k2 > -1)
		{
			p->Bignumber3[k3] = p->Bignumber2[k2];
			k2 = k2 - 1;
			k3 = k3 - 1;
		}
		if (sign == 2)
		{
			i = 0;
			while (p->Bignumber3[i] == 0)
			{
				i++;
			}
			p->Bignumber3[i] = p->Bignumber3[i] * (-1);
		}
	}
	else if (h == 0)
	{
		j = 0;
	}
	return j;
}




//Эта функция смотрит знак чисел и вызывает нужную функцию
int Summa(int k1, int k2, BigInt *p)
{
	int i = 0, j = 0, h, k3, sign;
	if (k1 >= k2)
	{
		k3 = k1+1;
		j = k3;
		p->Bignumber3 = (int*)malloc(k3 * sizeof(int));
	}
	else
	{
		k3 = k2+1;
		j = k3;
		p->Bignumber3 = (int*)malloc(k3 * sizeof(int));
	}
	p->Bignumber3[0] = 0;
	h = Comparison(p->Bignumber1, p->Bignumber2, k1, k2);
	k2 = k2 - 1;
	k1 = k1 - 1;
	k3 = k3 - 1;
	if (p->Bignumber1[0] > 0 && p->Bignumber2[0] > 0)
	{
		SumMass(h, k1, k2, k3, p);
	}
	else if (p->Bignumber1[0] < 0 && p->Bignumber2[0] > 0)
	{
		p->Bignumber1[0] = p->Bignumber1[0] * (-1);
		sign = 1;
		j = RazMass(h,sign, k1, k2, k3, p);
	}
	else if (p->Bignumber1[0] > 0 && p->Bignumber2[0] < 0)
	{
		p->Bignumber2[0] = p->Bignumber2[0] * (-1);
		sign = 2;
		j = RazMass(h, sign, k1, k2, k3, p);
	}
	else if (p->Bignumber1[0] < 0 && p->Bignumber2[0] < 0)
	{
		p->Bignumber1[0] = p->Bignumber1[0] * (-1);
		p->Bignumber2[0] = p->Bignumber2[0] * (-1);
		SumMass(h, k1, k2, k3, p);
		i = 0;
		while (p->Bignumber3[i] == 0)
		{
			i++;
		}
		p->Bignumber3[i] = p->Bignumber3[i] * (-1);
	}
	else if (p->Bignumber1[0] == 0 && k1 == 0 && p->Bignumber2[0] != 0)
	{
		while (k2 > -1)
		{
			p->Bignumber3[k3] = p->Bignumber2[k2];
			k3 = k3 - 1;
			k2 = k2 - 1;
		}
	}
	else if (p->Bignumber1[0] != 0 && k2 == 0 && p->Bignumber2[0] == 0)
	{
		while (k1 > -1)
		{
			p->Bignumber3[k3] = p->Bignumber1[k1];
			k3 = k3 - 1;
			k1 = k1 - 1;
		}
	}
	else if (p->Bignumber1[0] == 0 && k1 == 0 && p->Bignumber2[0] == 0 && k2 == 0)
	{
		j = 0;
	}
	return j;
}



//Эта функция смотрит знак чисел и вызывает нужную функцию
int Raznost(int k1, int k2, BigInt *p)
{
	int i = 0, j = 0, k3, h, sign;
	if (k1 >= k2)
	{
		k3 = k1 + 1;
		j = k3;
		p->Bignumber3 = (int*)malloc(k3 * sizeof(int));
	}
	else
	{
		k3 = k2 + 1;
		j = k3;
		p->Bignumber3 = (int*)malloc(k3 * sizeof(int));
	}
	p->Bignumber3[0] = 0;
	h = Comparison(p->Bignumber1, p->Bignumber2, k1, k2);
	k2 = k2 - 1;
	k1 = k1 - 1;
	k3 = k3 - 1;
	if (p->Bignumber1[0] > 0 && p->Bignumber2[0] > 0)
	{
		sign = 2;
		j = RazMass(h, sign, k1, k2, k3, p);
	}
	else if (p->Bignumber1[0] < 0 && p->Bignumber2[0] > 0)
	{
		p->Bignumber1[0] = p->Bignumber1[0] * (-1);
		SumMass(h, k1, k2, k3, p);
		i = 0;
		while (p->Bignumber3[i] == 0)
		{
			i++;
		}
		p->Bignumber3[i] = p->Bignumber3[i] * (-1);
	}
	else if (p->Bignumber1[0] > 0 && p->Bignumber2[0] < 0)
	{
		p->Bignumber2[0] = p->Bignumber2[0] * (-1);
		SumMass(h, k1, k2, k3, p);
	}
	else if (p->Bignumber1[0] < 0 && p->Bignumber2[0] < 0)
	{
		p->Bignumber1[0] = p->Bignumber1[0] * (-1);
		p->Bignumber2[0] = p->Bignumber2[0] * (-1);
		sign = 1;
		j = RazMass(h, sign, k1, k2, k3, p);
	}
	else if (p->Bignumber1[0] == 0 && k1 == 0 && p->Bignumber2[0] != 0)
	{
		while (k2 > -1)
		{
			p->Bignumber3[k3] = p->Bignumber2[k2];
			k3 = k3 - 1;
			k2 = k2 - 1;
		}
		i = 0;
		while (p->Bignumber3[i] == 0)
		{
			i++;
		}
		p->Bignumber3[i] = p->Bignumber3[i] * (-1);
	}
	else if (p->Bignumber1[0] != 0 && k2 == 0 && p->Bignumber2[0] == 0)
	{
		while (k1 > -1)
		{
			p->Bignumber3[k3] = p->Bignumber1[k1];
			k3 = k3 - 1;
			k1 = k1 - 1;
		}
	}
	else if (p->Bignumber1[0] == 0 && k1 == 0 && p->Bignumber2[0] == 0 && k2 == 0)
	{
		j = 0;
	}
	return j;
}


//Эта функция складывает массивы
void SummaMass(int *mas, BigInt *p, int k3, int k)
{
	int n = 0;
	while (k > -1)
	{
		p->Bignumber3[k3] = p->Bignumber3[k3] + mas[k] + n;
		n = 0;
		if (p->Bignumber3[k3] > 9)
		{
			p->Bignumber3[k3] = p->Bignumber3[k3] % 10;
			n = 1;
		}
		k3 = k3 - 1;
		k = k - 1;
	}
	while (k3 > -1)
	{
		p->Bignumber3[k3] = p->Bignumber3[k3] + n;
		n = 0;
		if (p->Bignumber3[k3] > 9)
		{
			p->Bignumber3[k3] = p->Bignumber3[k3] % 10;
			n = 1;
		}
		k3 = k3 - 1;
	}
	p->Bignumber3[0] = p->Bignumber3[0] + n;
}



//Эта функция записывает в массив числа и вызывает функцию сложения
void UmnojenieMass(int **mas, int *length, BigInt *p, int k1, int k2, int k, int k3)
{
	int i = 0, j = 0, n = 0, l;
	if (k1 >= k2)
	{
		for (i = 0; i < k; i++)
		{
			for (j = 0; j <= length[i]; j++)
			{
				mas[i][j] = 0;
			}
			l = k1;
			while (l > -1)
			{
				mas[i][l + 1] = p->Bignumber1[l];
				l = l - 1;
			}
		}
		l = k2;
		for (i = 0; i < k; i++)
		{
			j = length[i];
			for (j; j>-1; j--)
			{
				mas[i][j] = mas[i][j]*p->Bignumber2[l] + n;
				n = 0;
				if (mas[i][j] > 9)
				{
					n = mas[i][j] / 10;
					mas[i][j] = mas[i][j] % 10;
				}
			}
			l = l - 1;
		}
		for (i = 0; i < k; i++)
		{
			SummaMass(mas[i], p, k3, length[i]);
		}
	}
	else
	{
		for (i = 0; i < k; i++)
		{
			for (j = 0; j <= length[i]; j++)
			{
				mas[i][j] = 0;
			}
			l = k2;
			while (l > -1)
			{
				mas[i][l + 1] = p->Bignumber2[l];
				l = l - 1;
			}
		}
		l = k1;
		for (i = 0; i < k; i++)
		{
			j = length[i];
			for (j; j > -1; j--)
			{
				mas[i][j] = mas[i][j] * p->Bignumber1[l] + n;
				n = 0;
				if (mas[i][j] > 9)
				{
					n = mas[i][j] / 10;
					mas[i][j] = mas[i][j] % 10;
				}
			}
			l = l - 1;
		}
		for (i = 0; i < k; i++)
		{
			SummaMass(mas[i], p, k3, length[i]);
		}
	}
}




//Эта функция смотрит знак чисел и вызывает нужную функцию
int Umnojenie(int k1, int k2, BigInt *p)
{
	int i = 0, j = 0, **mas, k3, k, *length;
	k3 = k1 + k2;
	p->Bignumber3 = (int*)malloc(k3 * sizeof(int));
	for (i = 0; i < k3; i++)
	{
		p->Bignumber3[i] = 0;
	}
	if (k1 >= k2)
	{
		j = k1+1;
		k = k2;
		length = (int*)malloc(k * sizeof(int));
		mas = (int**)malloc(k * sizeof(int*));
		for (i = 0; i < k; i++)
		{
			mas[i] = (int*)malloc(j * sizeof(int));
			length[i] = j-1;
			j = j + 1;
		}
	}
	else
	{
		j = k2+1;
		k = k1;
		length = (int*)malloc(k * sizeof(int));
		mas = (int**)malloc(k * sizeof(int*));
		for (i = 0; i < k; i++)
		{
			mas[i] = (int*)malloc(j * sizeof(int));
			length[i] = j-1;
			j = j + 1;
		}
	}
	k2 = k2 - 1;
	k1 = k1 - 1;
	if (p->Bignumber1[0] > 0 && p->Bignumber2[0] > 0)
	{
		UmnojenieMass(mas, length, p, k1, k2, k, k3-1);
	}
	else if (p->Bignumber1[0] < 0 && p->Bignumber2[0] > 0)
	{
		p->Bignumber1[0] = p->Bignumber1[0] * (-1);
		UmnojenieMass(mas, length, p, k1, k2, k, k3 - 1);
		i = 0;
		while (p->Bignumber3[i] == 0)
		{
			i++;
		}
		p->Bignumber3[i] = p->Bignumber3[i] * (-1);
	}
	else if (p->Bignumber1[0] > 0 && p->Bignumber2[0] < 0)
	{
		p->Bignumber2[0] = p->Bignumber2[0] * (-1);
		UmnojenieMass(mas, length, p, k1, k2, k, k3 - 1);
		i = 0;
		while (p->Bignumber3[i] == 0)
		{
			i++;
		}
		p->Bignumber3[i] = p->Bignumber3[i] * (-1);
	}
	else if (p->Bignumber1[0] < 0 && p->Bignumber2[0] < 0)
	{
		p->Bignumber1[0] = p->Bignumber1[0] * (-1);
		p->Bignumber2[0] = p->Bignumber2[0] * (-1);
		UmnojenieMass(mas, length, p, k1, k2, k, k3 - 1);
	}
	else if (p->Bignumber1[0] == 0 && k1 == 0 && p->Bignumber2[0] != 0)
	{
		k3 = 0;
	}
	else if (p->Bignumber1[0] != 0 && k2 == 0 && p->Bignumber2[0] == 0)
	{
		k3 = 0;
	}
	else if (p->Bignumber1[0] == 0 && k1 == 0 && p->Bignumber2[0] == 0 && k2 == 0)
	{
		k3 = 0;
	}
	free(length);
	for (i = 0; i < k; i++)
	{
		free(mas[i]);
	}
	free(mas);
	return k3;
}





//Эта функция складывает массивы
void SummaMas(int *mas, int k, int *mas1, int k1)
{
	int n = 0;
	while (k > -1)
	{
		mas1[k1] = mas1[k1] + mas[k] + n;
		n = 0;
		if (mas1[k1] > 9)
		{
			mas1[k1] = mas1[k1] % 10;
			n = 1;
		}
		k1 = k1 - 1;
		k = k - 1;
	}
	while (k1 > -1)
	{
		mas1[k1] = mas1[k1] + n;
		n = 0;
		if (mas1[k1] > 9)
		{
			mas1[k1] = mas1[k1] % 10;
			n = 1;
		}
		k1 = k1 - 1;
	}
	mas1[0] = mas1[0] + n;
}




//Эта функция умножает два массива
void UmnojenieMas(int **mas, int *length, BigInt *p, int k2, int k, int k3, int *mas1, int k1)
{
	int i = 0, j = 0, n = 0, l;
	if (k3 >= k2)
	{
		for (i = 0; i < k; i++)
		{
			for (j = 0; j <= length[i]; j++)
			{
				mas[i][j] = 0;
			}
			l = k3;
			while (l > -1)
			{
				mas[i][l+1] = p->Bignumber3[l];
				l = l - 1;
			}
		}
		l = k2;
		for (i = 0; i < k; i++)
		{
			j = length[i];
			for (j; j > -1; j--)
			{
				mas[i][j] = mas[i][j] * p->Bignumber2[l] + n;
				n = 0;
				if (mas[i][j] > 9)
				{
					n = mas[i][j] / 10;
					mas[i][j] = mas[i][j] % 10;
				}
			}
			l = l - 1;
		}
		for (i = 0; i < k; i++)
		{
			SummaMas(mas[i], length[i], mas1, k1);
		}
	}
	else
	{
		for (i = 0; i < k; i++)
		{
			for (j = 0; j <= length[i]; j++)
			{
				mas[i][j] = 0;
			}
			l = k2;
			while (l > -1)
			{
				mas[i][l + 1] = p->Bignumber2[l];
				l = l - 1;
			}
		}
		l = k3;
		for (i = 0; i < k; i++)
		{
			j = length[i];
			for (j; j > -1; j--)
			{
				mas[i][j] = mas[i][j] * p->Bignumber3[l] + n;
				n = 0;
				if (mas[i][j] > 9)
				{
					n = mas[i][j] / 10;
					mas[i][j] = mas[i][j] % 10;
				}
			}
			l = l - 1;
		}
		for (i = 0; i < k; i++)
		{
			SummaMas(mas[i], length[i], mas1, k1);
		}
	}
}



//Жта функция подбирает ответ
void DelenieStolbikom(int k1, int k2, int k3, BigInt *p)
{
	int i = 0, j = 0, k, *length, **mas, h, *mas1, *mas2, i1;
	j = k1 + 1;
	mas1 = (int*)malloc(j * sizeof(int));
	mas2 = (int*)malloc(j * sizeof(int));
	mas2[0] = 0;
	for (i = 1; i < j; i++)
	{
		mas2[i] = p->Bignumber1[i - 1];
	}
	if (k3 >= k2)
	{
		k = k2;
		length = (int*)malloc(k * sizeof(int));
		mas = (int**)malloc(k * sizeof(int*));
		j = k3 + 1;
		for (i = 0; i < k; i++)
		{
			mas[i] = (int*)malloc(j * sizeof(int));
			length[i] = j - 1;
			j = j + 1;
		}
	}
	else
	{
		j = k2 + 1;
		k = k3;
		length = (int*)malloc(k * sizeof(int));
		mas = (int**)malloc(k * sizeof(int*));
		for (i = 0; i < k; i++)
		{
			mas[i] = (int*)malloc(j * sizeof(int));
			length[i] = j - 1;
			j = j + 1;
		}
	}
	k2 = k2 - 1;
	k3 = k3 - 1;
	j = 0;
	while (j <= k3)
	{
		for (i = 1; i <= 9; i++)
		{
			for (i1 = 0; i1 < k1+1; i1++)
			{
				mas1[i1] = 0;
			}
			p->Bignumber3[j] = i;
			UmnojenieMas(mas, length, p, k2, k, k3, mas1, k1);
			h = Comparison(mas2, mas1, k1+1, k1+1);
			if (h == 1)
			{
				p->Bignumber3[j] = i;
			}
			else if (h == 2)
			{
				p->Bignumber3[j] = i-1;
				break;
			}
			else if (h == 0)
			{
				j = i;
				break;
			}
		}
		j = j + 1;
	}
	for (i = 0; i < k; i++)
	{
		free(mas[i]);
	}
	free(mas);
	free(mas1);
	free(mas2);
	free(length);
}




//Эта функция смотрит знаки чисел и вызывает функцию деления
int Delenie(int k1, int k2, BigInt *p)
{
	int i = 0, k3 = 0, h;
	if (k1 >= k2)
	{
		k3 = k1 - k2 + 1;
		p->Bignumber3 = (int*)malloc(k3 * sizeof(int));
		for (i = 0; i < k3; i++)
		{
			p->Bignumber3[i] = 0;
		}
	}
	else
	{
		k3 = 0;
	}
	h = Comparison(p->Bignumber1, p->Bignumber2, k1, k2);
	if (p->Bignumber1[0] > 0 && p->Bignumber2[0] > 0)
	{
		if (h == 1)
		{
			DelenieStolbikom(k1, k2, k3, p);
		}
		else if (h == 2)
		{
			k3 = 0;
		}
		else if (h == 0)
		{
			DelenieStolbikom(k1, k2, k3, p);
		}
	}
	else if (p->Bignumber1[0] < 0 && p->Bignumber2[0] > 0)
	{
		p->Bignumber1[0] = p->Bignumber1[0] * (-1);
		if (h == 1)
		{
			DelenieStolbikom(k1, k2, k3, p);
		}
		else if (h == 2)
		{
			k3 = 0;
		}
		else if (h == 0)
		{
			DelenieStolbikom(k1, k2, k3, p);
		}
		i = 0;
		while (p->Bignumber3[i] == 0)
		{
			i++;
		}
		p->Bignumber3[i] = p->Bignumber3[i] * (-1);
	}
	else if (p->Bignumber1[0] > 0 && p->Bignumber2[0] < 0)
	{
		p->Bignumber2[0] = p->Bignumber2[0] * (-1);
		if (h == 1)
		{
			DelenieStolbikom(k1, k2, k3, p);
		}
		else if (h == 2)
		{
			k3 = 0;
		}
		else if (h == 0)
		{
			DelenieStolbikom(k1, k2, k3, p);
		}
		i = 0;
		while (p->Bignumber3[i] == 0)
		{
			i++;
		}
		p->Bignumber3[i] = p->Bignumber3[i] * (-1);
	}
	else if (p->Bignumber1[0] < 0 && p->Bignumber2[0] < 0)
	{
		p->Bignumber1[0] = p->Bignumber1[0] * (-1);
		p->Bignumber2[0] = p->Bignumber2[0] * (-1);
		if (h == 1)
		{
			DelenieStolbikom(k1, k2, k3, p);
		}
		else if (h == 2)
		{
			k3 = 0;
		}
		else if (h == 0)
		{
			DelenieStolbikom(k1, k2, k3, p);
		}
	}
	else if (p->Bignumber1[0] == 0 && k1 == 1 && p->Bignumber2[0] != 0)
	{
		k3 = 0;
	}
	else if (p->Bignumber1[0] != 0 && k2 == 1 && p->Bignumber2[0] == 0)
	{
		k3 = -1;
	}
	else if (p->Bignumber1[0] == 0 && k1 == 1 && p->Bignumber2[0] == 0 && k2 == 1)
	{
		k3 = -1;
	}
	return k3;
}




//Эта функция выводит результат и очищает память
void PrintAndFree(int k3, BigInt *p)
{
	int i = 0;
	printf("Результат:\n");
	if (k3 > 0)
	{
		while (p->Bignumber3[i] == 0)
		{
			i = i + 1;
		}
		for (i; i < k3; i++)
		{
			printf("%d", p->Bignumber3[i]);
		}
		printf("\n");
	}
	else if (k3 == 0)
	{
		printf("0\n");
	}
	else if (k3 == -1)
	{
		printf("На нуль делить нельзя!\n");
	}
	free(p->Bignumber1);
	free(p->Bignumber2);
	free(p->Bignumber3);
}
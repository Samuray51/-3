//#define _CRT_SECURE_NO_WARNINGS
#include"Function.h"


int main(int argc, char *argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");


	int memory = 100000;
	char *h, *p, *h1, *p1;
	char tmp, sign;
	errno_t err;
	int m, k1, k2, k3;
	BigInt Mas;
	printf("Введите 1, чтобы ввести числа с клавиатуры.\nВведите 2, чтобы взять числа из файла.\nВведите 3, чтобы взять параметры main.\nНажмите 4, чтобы выйти из программы.\n");
	if (scanf_s("%d", &m) == 0)
	{
		printf("Некорректный ввод\n");
		system("pause");
		exit(1);
	}
	if (m == 1)
	{
		h = (char*)malloc(memory * sizeof(char));
		p = (char*)malloc(memory * sizeof(char));
		printf("Введите 1 число:\n");
		scanf_s("%c", &tmp, 1);
		k1 = ScanNumber(h);
		if (k1 == 0)
		{
			printf("Не число!\n");
			system("pause");
			exit(1);
		}
		Mas.Bignumber1 = (int*)malloc(k1 * sizeof(int));
		IntNumber(h, Mas.Bignumber1, k1);
		free(h);

		printf("Введите знак(+, -, *, /):\n");
		scanf_s("%c", &sign, 1);
		Sign(sign);

		printf("Введите 2 число:\n");
		scanf_s("%c", &tmp, 1);
		k2 = ScanNumber(p);
		if (k2 == 0)
		{
			printf("Не число!\n");
			system("pause");
			exit(1);
		}
		Mas.Bignumber2 = (int*)malloc(k2 * sizeof(int));
		IntNumber(p, Mas.Bignumber2, k2);
		free(p);

		if (sign == '+')
		{
			k3 = Summa(k1, k2, &Mas);
		}
		else if (sign == '-')
		{
			k3 = Raznost(k1, k2, &Mas);
		}
		else if (sign == '*')
		{
			k3 = Umnojenie(k1, k2, &Mas);
		}
		else if (sign == '/')
		{
			k3 = Delenie(k1, k2, &Mas);
		}
		PrintAndFree(k3, &Mas);
	}
	else if (m == 2)
	{
		int i = 0, j = 0;
		char **mas;
		mas = (char**)malloc(2 * sizeof(char*));
		for (i = 0; i < 2; i++)
		{
			mas[i] = (char*)malloc(memory * sizeof(char));
		}
		FILE *in;
		err = fopen_s(&in, "input.txt", "r");
		if (err != NULL)
		{
			printf("Файл: input.txt\nКод ошибки: %d\n", err);
			perror("Описание ошибки");
			system("pause");
			exit(1);
		}
		if (SYMBOL(in) == 1) {
			system("pause");
			exit(1);
		}
		scanf_s("%c", &tmp, 1);
		i = 0;
		while (!feof(in))
		{
			fscanf_s(in, "%c", &mas[i][j], 1);
			if (mas[i][j] == '\n')
			{
				k1 = j;
				j = -1;
				i = i + 1;
			}
			j++;
		}
		k2 = j - 1;
		if (i == 0)
		{
			printf("Не число!\n");
			system("pause");
			exit(1);
		}
		if (k2 == 0)
		{
			printf("Не число!\n");
			system("pause");
			exit(1);
		}
		k1 = ProverkaNaSymbol(mas[0], k1);
		k2 = ProverkaNaSymbol(mas[1], k2);
		//printf("%d\n", k1);
		//printf("%d\n", k2);


		Mas.Bignumber1 = (int*)malloc(k1 * sizeof(int));
		Mas.Bignumber2 = (int*)malloc(k2 * sizeof(int));
		IntNumber(mas[0], Mas.Bignumber1, k1);
		IntNumber(mas[1], Mas.Bignumber2, k2);
		for (i = 0; i < 2; i++)
		{
			free(mas[i]);
		}
		free(mas);

		/*printf("1 число:\n");
		for (i = 0; i < k1; i++)
		{
			printf("%d", Mas.Bignumber1[i]);
		}
		printf("\n");
		printf("2 число:\n");
		for (i = 0; i < k2; i++)
		{
			printf("%d", Mas.Bignumber2[i]);
		}
		printf("\n");*/

		printf("Введите знак(+, -, *, /):\n");
		scanf_s("%c", &sign, 1);
		Sign(sign);
		if (sign == '+')
		{
			k3 = Summa(k1, k2, &Mas);
		}
		else if (sign == '-')
		{
			k3 = Raznost(k1, k2, &Mas);
		}
		else if (sign == '*')
		{
			k3 = Umnojenie(k1, k2, &Mas);
		}
		else if (sign == '/')
		{
			k3 = Delenie(k1, k2, &Mas);
		}
		PrintAndFree(k3, &Mas);
		fclose(in);
	}
	else if (m == 3)
	{
		if (argc != 4)
		{
			printf("Неправильный ввод параметров!\n");
			system("pause");
			exit(1);
		}
		int k1 = 0, k2 = 0, i = 0;
		while (argv[1][k1] != '\0')
		{
			k1++;
		}
		while (argv[3][k2] != '\0')
		{
			k2++;
		}
		k1 = ProverkaNaSymbol(argv[1], k1);
		k2 = ProverkaNaSymbol(argv[3], k2);
		//printf("%d\n", k1);
		//printf("%d\n", k2);


		Mas.Bignumber1 = (int*)malloc(k1 * sizeof(int));
		Mas.Bignumber2 = (int*)malloc(k2 * sizeof(int));
		IntNumber(argv[1], Mas.Bignumber1, k1);
		IntNumber(argv[3], Mas.Bignumber2, k2);

		printf("1 число:\n");
		for (i = 0; i < k1; i++)
		{
			printf("%d", Mas.Bignumber1[i]);
		}
		printf("\n");
		printf("2 число:\n");
		for (i = 0; i < k2; i++)
		{
			printf("%d", Mas.Bignumber2[i]);
		}
		printf("\n");

		Sign(argv[2][0]);
		if (argv[2][0] == '+')
		{
			k3 = Summa(k1, k2, &Mas);
		}
		else if (argv[2][0] == '-')
		{
			k3 = Raznost(k1, k2, &Mas);
		}
		else if (argv[2][0] == '*')
		{
			k3 = Umnojenie(k1, k2, &Mas);
		}
		else if (argv[2][0] == '/')
		{
			k3 = Delenie(k1, k2, &Mas);
		}
		PrintAndFree(k3, &Mas);
	}
	else if (m == 4)
	{
		system("pause");
		exit(1);
	}
	system("pause");
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<iostream>

using namespace std;


int main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	int razmmas = 100;
	int elem_c, poryadok = 600;
	int** a,** b,** c;
	clock_t start, end; // объявляем переменные для определения времени выполнения
	for (int progon = 0; progon < 8; progon++) { // цикл для автоматического введение длинны массива
	
		a = new int* [razmmas]; // создаём двумерный массив
		b = new int* [razmmas];
		c = new int* [razmmas];
		for (int p = 0; p < razmmas; p++) {
			a[p] = new int[razmmas];
			b[p] = new int[razmmas];
			c[p] = new int[razmmas];
		}

		int i = 0, j = 0, r;
		elem_c = 0;

		srand(time(NULL)); // инициализируем параметры генератора случайных чисел 
		while (i < razmmas)
		{
			while (j < razmmas)
			{
				a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
				j++;
			}
			i++;
		}
		srand(time(NULL)); // инициализируем параметры генератора случайных чисел
		i = 0; j = 0;
		while (i < razmmas)
		{
			while (j < razmmas)
			{
				b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
				j++;
			}
			i++;
		}

		start = clock(); // сохраняем время до начала умножения чисел
		for (i = 0;i < razmmas;i++)
		{
			for (j = 0;j < razmmas;j++)
			{
				elem_c = 0;
				for (r = 0;r < razmmas;r++)
				{
					elem_c = elem_c + a[i][r] * b[r][j];
					c[i][j] = elem_c;
				}
			}
		}
		end = clock();// сохраняем время в крнце умножения чисел
		double timee = (double)(end - start) / CLOCKS_PER_SEC;// перевод в секунды 
		cout << "Time pri " << razmmas << " elementax: " << timee << "\n";

		if (razmmas == 400 || razmmas == 4000) {
			razmmas += poryadok;
			poryadok *= 10;
		}
		else { razmmas *= 2; }
	}


	return(0);
}


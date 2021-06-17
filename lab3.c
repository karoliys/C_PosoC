//lab3 task 3.2(29)
#include <stdio.h>
#include <math.h>
#include <locale.h>
void EnterArr(int** a, int n)
{
	int num = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 10;
		}
	}
}
void ShowArr(int** a, int n)
{
	printf("\nМассив: \n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void ArrUpDown(int** a, int n)
{
	int TempA; int SummUp = 0; int SummDown = 0;
	//i+1 кол-во элементов пропуска
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = i + 1; j < n - (i + 1); j++)
		{
			TempA = a[i][j];
			a[i][j] = a[n - 1 - i][j];
			a[n - 1 - i][j] = TempA;
			SummDown += TempA;
			SummUp += a[i][j];
		}
	}
	printf("Сумма по новому массиву:\n");
	printf("Сумма верхней: %d\n", SummUp);
	printf("Сумма нижней: %d\n", SummDown); // счёт по новой
}
void ArrLeftRight(int** a, int n)
{
	int TempA, SummLeft = 0, SummRight = 0;
	for (int j = 0; j < n / 2; j++)
	{
		for (int i = j + 1; i < n - (j + 1); i++)
		{
			TempA = a[i][j];
			a[i][j] = a[i][n - 1 - j];
			a[i][n - 1 - j] = TempA;
			SummRight += TempA;
			SummLeft += a[i][j];
		}
	}
	printf("Сумма Левой: %d\n", SummLeft);
	printf("Сумма правой: %d\n", SummRight); // счёт по новой
}


int main()
{
	setlocale(LC_ALL, "Rus");
	int size;
	printf("Введите размер массива\n");
	if (!scanf_s("%d", &size)) {
		printf("Ошибка, неверный ввод\n");
		return 1;
	}
	if (size <= 0) {
		printf("Ошибка, недопустимый аргумент\n");
		return 1;
	}
	int** array = (int**)malloc(size * sizeof(int*));
	if (array == NULL) {
		printf("Не удается выделить память\n");
		return 1;
	}
	for (int i = 0; i < size; i++) {
		array[i] = (int*)malloc(size * sizeof(int));
		if (array[i] == NULL) {
			printf("Не удается выделить память\n");
			return 1;
		}
	}
	EnterArr(array, size);
	ShowArr(array, size);
	ArrUpDown(array, size);
	//ShowArr(array, size);
	ArrLeftRight(array, size);
	ShowArr(array, size);
	for (int i = 0; i < size; i++)
	{
		free(array[i]);
	}
	free(array);
	return 0;
}

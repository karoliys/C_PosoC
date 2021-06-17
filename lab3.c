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
	printf("\n������: \n");
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
	//i+1 ���-�� ��������� ��������
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
	printf("����� �� ������ �������:\n");
	printf("����� �������: %d\n", SummUp);
	printf("����� ������: %d\n", SummDown); // ���� �� �����
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
	printf("����� �����: %d\n", SummLeft);
	printf("����� ������: %d\n", SummRight); // ���� �� �����
}


int main()
{
	setlocale(LC_ALL, "Rus");
	int size;
	printf("������� ������ �������\n");
	if (!scanf_s("%d", &size)) {
		printf("������, �������� ����\n");
		return 1;
	}
	if (size <= 0) {
		printf("������, ������������ ��������\n");
		return 1;
	}
	int** array = (int**)malloc(size * sizeof(int*));
	if (array == NULL) {
		printf("�� ������� �������� ������\n");
		return 1;
	}
	for (int i = 0; i < size; i++) {
		array[i] = (int*)malloc(size * sizeof(int));
		if (array[i] == NULL) {
			printf("�� ������� �������� ������\n");
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

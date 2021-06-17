//lab2 task 2.1(12)
#include <stdio.h>
#include <math.h>
#include <locale.h>


void menu()
{
	printf("1-Введите координаты треугольника\n");
	printf("2-Определить вид треугольника\n");
	printf("3-Вывод периметра треугольника\n");
	printf("4-Вывод площади треугольника\n");
	printf("5-Вывести радиусы вписанной и описанной вокруг треугольника окружностей\n");
	printf("6-Информация о версии и авторе программы\n");
	printf("Another-Выход\n");
}
void ReadyTrg(double coordX[], double coordY[])
{
	coordX[0] = 0; coordX[1] = 10; coordX[2] = 5;
	coordY[0] = 0; coordY[1] = 0; coordY[2] = 8.660254037844386;
}
void EnterCoord(double coordX[], double coordY[])
{
	for (int i = 0; i < 3; i++)
	{
		printf("Координата X%d:\n", i + 1);
		scanf_s("%lf", &coordX[i]);
		printf("Координата Y%d:\n", i + 1);
		scanf_s("%lf", &coordY[i]);
	}
}
double Perimeter(double lengthTr[])
{
	return lengthTr[0] + lengthTr[1] + lengthTr[2];
}
double Square(double lengthTr[])
{
	double P = 0;
	P = (lengthTr[0] + lengthTr[1] + lengthTr[2]) / 2;
	return sqrt(P * (P - lengthTr[0]) * (P - lengthTr[1]) * (P - lengthTr[2]));
}
void LengthTriangle(double coordX[], double coordY[], double lengthTr[])
{
	lengthTr[0] = sqrt(pow((coordX[0] - coordX[1]), 2) + pow((coordY[0] - coordY[1]), 2));
	lengthTr[1] = sqrt(pow((coordX[1] - coordX[2]), 2) + pow((coordY[1] - coordY[2]), 2));
	lengthTr[2] = sqrt(pow((coordX[2] - coordX[0]), 2) + pow((coordY[2] - coordY[0]), 2));
	if (lengthTr[0] + lengthTr[1] <= lengthTr[2] || lengthTr[1] + lengthTr[2] <= lengthTr[0] || lengthTr[0] + lengthTr[2] <= lengthTr[1]) //real trngl
	{
		printf("error");
	}
}
void ViewTr(double lengthTr[])
{
	if ((lengthTr[0] == lengthTr[1]) && (lengthTr[1] == lengthTr[2]))
	{
		printf("Равносторонний");
	}
	else if ((lengthTr[0] == lengthTr[1]) || (lengthTr[1] == lengthTr[2]) || (lengthTr[0] == lengthTr[2]))
	{
		printf("Равнобедренный ");
	}
	else if (pow(lengthTr[0], 2) == pow(lengthTr[1], 2) + pow(lengthTr[2], 2) || pow(lengthTr[1], 2) == pow(lengthTr[0], 2) + pow(lengthTr[2], 2) || pow(lengthTr[2], 2) == pow(lengthTr[1], 2) + pow(lengthTr[0], 2))
	{
		printf("Прямоугольный");
	}
	else
	{
		printf("Произвольный");
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	double coordX[3], coordY[3];
	double lengthTr[3];
	int answer = 0;
	while (1)
	{
		menu();
		scanf_s("%d", &answer);
		switch (answer)
		{
		case 0: ReadyTrg(coordX, coordY); LengthTriangle(coordX, coordY, lengthTr); break;
		case 1: EnterCoord(coordX, coordY); LengthTriangle(coordX, coordY, lengthTr); break;
		case 2: ViewTr(lengthTr); break;
		case 3: printf("Периметр:%f", Perimeter(lengthTr)); break;
		case 4: printf("Площадь:%f", Square(lengthTr)); break;
		case 5:
			printf("Радиус вписанной:%f\n", Square(lengthTr) / (Perimeter(lengthTr) / 2));
			printf("Радиус описанной:%f\n", lengthTr[0] * lengthTr[1] * lengthTr[2]) / (4 * Square(lengthTr)); break;
		case 6: printf("Version: 1.33.7, By Karoliys"); break;
		default: return 0; break;
		}
		printf("\n");
		system("Pause");
		system("@cls||clear");
	}
	return 0;
}

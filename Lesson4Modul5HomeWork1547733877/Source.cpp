#include<stdio.h>
#include<iostream>
#include<locale.h>
#include<time.h>
#include<Windows.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// Lesson4Modul5HomeWork1547733877

void Task1()
{
	SetConsoleTextAttribute(hConsole, 10);
	printf("\n--------------------------------------------------------------------------\n\nTask1\n\n");
	SetConsoleTextAttribute(hConsole, 7);

	const int n = 6;
	int arr[n] = { 0 }, i, ost, dec = 0, dec1=0, count = 0, oct = 0, step = 0, buffer = 0; //dec 62 

	printf("\n В двоичой системе\t=>");
	
	for (i = 0; i < n; i++)
	{
		arr[i] = 0 + rand() % 2;
		printf("%2d", arr[i]);
	}

	for (i = 0; i < n; i++) 
		dec += arr[i] * pow(2, n - 1 - i);		//вывод элементов в обратном порядке для удобства восприятия чисел
	
	for (i = n-1; i >=0; i--)					// смотрим цикл с конца, условие для перевода в 8 систему
	{
		dec1 += arr[i] * pow(2, step);			// переводим число первой бинарной тройки (8 в дес) в 10 систему
		step++;									// степени для перевода бинарного числа в 10 систему

		if (step % 3 == 0)						// смотрим цикл с конца, условие для перевода в 8 систему   
			{
			oct += dec1 * pow(10, count);		// записываем цифры в соответствующие разряды
			count++;							// счетчик для степени, чтобы превести 8-ое число в соотв разряд
			step = 0;							// обнуляем счетчик отработавшей тройки битов
			dec1 = 0;							// обнуляем полученное 8 число для отработавшей тройки битов 
			}
	}

	printf("\n В десятичной системе\t=> %d", dec);
	printf("\n В восмиричной системе\t=> %d", oct);


}


void Task2()
{
	SetConsoleTextAttribute(hConsole, 10);
	printf("\n--------------------------------------------------------------------------\n\nTask2\n\n");
	SetConsoleTextAttribute(hConsole, 7);

	int const ind1 = 9, ind2 = 7, ind3 = 16;
	int arr1[ind1], arr2[ind2], arr3[ind3], i, j, c;

	printf("\n\n\nВвод случайных значений элементов в массив A[%d] : \n\n", ind1);

	for (i = 0; i < ind1; i++)
	{
		arr1[i] = 1 + rand() % 10;
		printf("%d  ", arr1[i]);
	}


	printf("\n\n\nВвод случайных значений элементов в массив B[%d] : \n\n", ind2);

	for (i = 0; i < ind2; i++)
	{
		arr2[i] = 1 + rand() % 10;
		printf("%d  ", arr2[i]);
	}

	printf("\n\n\nОбъединение массивов A[%d] и B[%d] в массив C[%d] : \n\n", ind1, ind2, ind3);

	for (i = 0; i < ind3; i++)
	{
		if (i < ind1) arr3[i] = arr1[i];

		if (i >= ind1) arr3[i] = arr2[i - ind1];

		printf("%d  ", arr3[i]);
	}

	printf("\n\n\nCортировка C[%d] массива по убыванию значений элементов : \n\n", ind3);

	// МЕТОД ПУЗЫРЬКА //
	for (i = 0; i < ind3 - 1; i++)		// достаточно поставить ind3-1 элементов
		for (j = ind3 - 2; j >= i; j--)		// идем с конца массива в начало
			if (arr3[j] < arr3[j + 1])		// если элементы стоят правильно, ...
			{
				c = arr3[j];				// переменная буфер
				arr3[j] = arr3[j + 1];		// перестановка arr3[j] и arr3[j + 1]
				arr3[j + 1] = c;
			}

	for (i = 0; i < ind3; i++) printf("%d  ", arr3[i]);

	printf("\n\n");
}



void Task3()
{
	SetConsoleTextAttribute(hConsole, 10);
	printf("\n--------------------------------------------------------------------------\n\nTask3\n\n");
	SetConsoleTextAttribute(hConsole, 7);

	int const ind = 10;
	int arr[ind] = {1,3,7,8,9,5,6,2,4,7}, i, j, count=0;
			
	for (i = 0; i < ind; i++) printf("A[%d] = %d \n", i, arr[i]);

	for (i = 0; i < ind; i++)
		for (j = i + 1; j < ind; j++)
		{
			count++;

			if (arr[i] == arr[j] && i != j && i < j)
			{
				printf("\n\nОдинаковые элементы расположены по индексам %d и %d \n\n", i, j);
				i = ind;
			}
		}

	printf("\nКол-во циклов до момента нахождения одинаковых элементов = %d \n\n", count);

}


void Task4()
{
	SetConsoleTextAttribute(hConsole, 10);
	printf("\n--------------------------------------------------------------------------\n\nTask4\n\n");
	SetConsoleTextAttribute(hConsole, 7);

	int const ind = 10;
	int arr[ind], i, j, q=0, count=0;

	for (i = 0; i < ind; i++)
	{
		arr[i] = 1 + rand()%10;
		
		//arr[i] = pow(2, i + 1);
		
		printf("A[%d] = %d \n", i, arr[i]);
	}

	for (i = 0; i < ind - 1; i++)
	{
		q = arr[i + 1] / arr[i];
		i = ind;
	}
	

	for (i = 0; i < ind - 1; i++)
	{
		j = i + 1;

		if (arr[i + 1] == arr[i] * q) 
			count++;
	}
	if (count==ind-1) printf("\nЗнаменатель прогрессии : %d \n", q);
	else printf("\nЭлементы массива не образуют прогрессии\n");
}


void Task5()
{
	SetConsoleTextAttribute(hConsole, 10);
	printf("\n--------------------------------------------------------------------------\n\nTask5\n\n");
	SetConsoleTextAttribute(hConsole, 7);

	int const line = 5, column = 4;
	int arr[line][column], i, j, a, b, c;

	for (i = 0; i < line; i++)
	{
		for (j = 0; j < column; j++)
		{
			arr[i][j] = 1 + rand()%9;
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	
	
	printf("\n\nCортировка по убыванию элементов последнего столбца \n\n");

	j = 3;
	
	for (a = 0; a < line - 1; a++)					// достаточно поставить элементов
		for (b = line - 2; b >= a; b--)				// идем с конца массива в начало
			if (arr[b][j] < arr[b + 1][j])			// если элементы стоят правильно, ...
				{
					c = arr[b][j];					// переменная буфер
					arr[b][j] = arr[b + 1][j];		// перестановка 
					arr[b + 1][j] = c;
				}
	
	
	for (i = 0; i < line; i++)
	{
		for (j = 0; j < column; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

}


void Task6()
{
	SetConsoleTextAttribute(hConsole, 10);
	printf("\n--------------------------------------------------------------------------\n\nTask6\n\n");
	SetConsoleTextAttribute(hConsole, 7);

	int const line = 3, column = 4;
	int arr[line][column], i, j, min = 100, mini = 0, mini1=0, c = 0;

	for (i = 0; i < line; i++)
	{
		for (j = 0; j < column; j++)
		{
			arr[i][j] = 1 + rand() % 9;
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	for (j = 0; j < column; j++)
		if (arr[0][j] < min)
		{
			min = arr[0][j];
			mini = j;
			c = arr[0][j];
		}

	min = 100;

	for (j = 0; j < column; j++)
		if (arr[2][j] < min) 
		{
			min = arr[2][j];
			mini1 = j;
		}
	
	
	printf("\n\n arr[0][%d] = %d   arr[2][%d] = %d \n\n", mini, arr[0][mini], mini1, arr[2][mini1]);


	for (j = 0; j < column; j++)
		if (j == mini1)
		{
			arr[0][mini] = arr[2][j];
			arr[2][j] = c;
		}

	printf("\n\nМеняем наименьшие элементы в первой и третей строке\n\n");

	
	for (i = 0; i < line; i++)
		for (j = 0; j < column; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");

}


void Task7()
{
	SetConsoleTextAttribute(hConsole, 10);
	printf("\n--------------------------------------------------------------------------\n\nTask7\n\n");
	SetConsoleTextAttribute(hConsole, 7);

	int const line = 5, column = 6;
	int arr[line][column], i, j, min = 100, max = 0, sum = 0;
	float result = 0;

	printf("\n\nДан двухмерный массив 5 х 6 :\n");

	for (i = 0; i < line; i++)
	{
		for (j = 0; j < column; j++)
		{
			arr[i][j] = 1 + rand() % 9;
			printf("%d ", arr[i][j]);
		}

		printf("\n");
	}
	
		printf("\n\nСреднее арифметическое столбцов : \n");

		for (i = 0; i < column; i++)
		{
			sum = 0;

			for (j = 0; j < line; j++)
			{
				sum += arr[j][i];
				
			}
			
			result = (float)sum / line;

			printf("\nСтолбец %d = %3.2f", i+1, result);
		}
			

		printf("\n\n\nМаксимум и минимум каждой строки : \n");

		for (i = 0; i < line; i++)
		{
			sum = 0;
			min = 100;
			max = 0;

			for (j = 0; j < column; j++)
			{
				if (arr[i][j] < min) min = arr[i][j];
				if (arr[i][j] > max) max = arr[i][j];

			}

			printf("\nCтрока %d ->   max = %d \t min = %d", i, max, min);
		}


}


void Task8()
{
	SetConsoleTextAttribute(hConsole, 10);
	printf("\n--------------------------------------------------------------------------\n\nTask8\n\n");
	SetConsoleTextAttribute(hConsole, 7);

	int const line = 4, column = 4;
	int arr[line][column], i, j, count = 0, count1 = 0;
	
	printf("\nДан двухмерный массив %d х %d :\n\n", line, column);

	for (i = 0; i < line; i++)
	{
		for (j = 0; j < column; j++)
		{
			arr[i][j] = 1 + rand() % 9;
			printf("%d ", arr[i][j]);
		}

		printf("\n");
	}


	for (i = 0; i < line; i++)
	{
		for (j = 0; j < column; j++)
		{
			if (arr[i][j] % 2 == 0) count++;
			else count1++;
		}
	}
	
	printf("\n\nКол-во четных элементов \t -> %d\n", count);
	printf("\n\nКол-во нечетных элементов \t -> %d\n", count1);


}


void Task9()
{
	SetConsoleTextAttribute(hConsole, 10);
	printf("\n--------------------------------------------------------------------------\n\nTask9\n\n");
	SetConsoleTextAttribute(hConsole, 7);

	int const line = 10, column = 10;
	int arr[line][column], i, j, count = 0, count1 = 0;

	printf("\nДан двухмерный массив %d х %d :\n\n", line, column);

	for (i = 0; i < line; i++)
	{
		for (j = 0; j < column; j++)
		{
			arr[i][j] = 1 + rand() % 9;
			
			if(arr[i][j]!=7) printf("%3d  ", arr[i][j]);
			
			else
			{
				printf(" (%d) ", arr[i][j]);
				count++;
			}
		}

		printf("\n");
	}

	printf("\n\nЧисло 7 среди элементов массива встречается %d раз\n", count);

}


void Task10()
{
	SetConsoleTextAttribute(hConsole, 10);
	printf("\n--------------------------------------------------------------------------\n\nTask10\n\n");
	SetConsoleTextAttribute(hConsole, 7);

	int const line = 6, column = 6;
	int arr[line][column], i, j, min = 100, flag = 0;

	printf("\nДан двухмерный массив %d х %d :\n\n", line, column);

	for (i = 0; i < line; i++)
	{
		for (j = 0; j < column; j++)
		{
			arr[i][j] = 1 + rand() % 9;

			printf("%d ", arr[i][j]);

			if (arr[i][j] < min) min = arr[i][j];
		}

		printf("\n");
	}

	printf("\n min %d \n\n", min);

	for (i = 0; i < line; i++)
	{
		for (j = 0; j < column; j++)
		{
			if (arr[i][j] == min) flag=1;
			if (flag) break;
		}
		if (flag) break;
	}
		
		

	printf("\n\nИндексы первого наименьшего  элемента массива A[%d][%d] = %d \n", i, j, arr[i][j]);

}


int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));



	int number, flag;

	do
	{
		printf("Enter number of Task (1) to (10) => ");
		scanf_s("%d", &number);

		switch (number)
		{
		case 1: {Task1(); } break;
		case 2: {Task2(); } break;
		case 3: {Task3(); } break;
		case 4: {Task4(); } break;
		case 5: {Task5(); } break;
		case 6: {Task6(); } break;
		case 7: {Task7(); } break;
		case 8: {Task8(); } break;
		case 9: {Task9(); } break;
		case 10: {Task10(); } break;

		default: printf("\nEntered number of Task does not exist...\n\n");

		}

		SetConsoleTextAttribute(hConsole, 10);
		printf("\n--------------------------------------------------------------------------\n\n"); ("\n");
		SetConsoleTextAttribute(hConsole, 7);

		printf("Do you want to continue? 1/0 => ");
		scanf_s("%d", &flag);

	} while (flag == 1);



	if (flag == 1)
		system("pause");


}
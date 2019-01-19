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

	printf("\n � ������� �������\t=>");
	
	for (i = 0; i < n; i++)
	{
		arr[i] = 0 + rand() % 2;
		printf("%2d", arr[i]);
	}

	for (i = 0; i < n; i++) 
		dec += arr[i] * pow(2, n - 1 - i);		//����� ��������� � �������� ������� ��� �������� ���������� �����
	
	for (i = n-1; i >=0; i--)					// ������� ���� � �����, ������� ��� �������� � 8 �������
	{
		dec1 += arr[i] * pow(2, step);			// ��������� ����� ������ �������� ������ (8 � ���) � 10 �������
		step++;									// ������� ��� �������� ��������� ����� � 10 �������

		if (step % 3 == 0)						// ������� ���� � �����, ������� ��� �������� � 8 �������   
			{
			oct += dec1 * pow(10, count);		// ���������� ����� � ��������������� �������
			count++;							// ������� ��� �������, ����� �������� 8-�� ����� � ����� ������
			step = 0;							// �������� ������� ������������ ������ �����
			dec1 = 0;							// �������� ���������� 8 ����� ��� ������������ ������ ����� 
			}
	}

	printf("\n � ���������� �������\t=> %d", dec);
	printf("\n � ����������� �������\t=> %d", oct);


}


void Task2()
{
	SetConsoleTextAttribute(hConsole, 10);
	printf("\n--------------------------------------------------------------------------\n\nTask2\n\n");
	SetConsoleTextAttribute(hConsole, 7);

	int const ind1 = 9, ind2 = 7, ind3 = 16;
	int arr1[ind1], arr2[ind2], arr3[ind3], i, j, c;

	printf("\n\n\n���� ��������� �������� ��������� � ������ A[%d] : \n\n", ind1);

	for (i = 0; i < ind1; i++)
	{
		arr1[i] = 1 + rand() % 10;
		printf("%d  ", arr1[i]);
	}


	printf("\n\n\n���� ��������� �������� ��������� � ������ B[%d] : \n\n", ind2);

	for (i = 0; i < ind2; i++)
	{
		arr2[i] = 1 + rand() % 10;
		printf("%d  ", arr2[i]);
	}

	printf("\n\n\n����������� �������� A[%d] � B[%d] � ������ C[%d] : \n\n", ind1, ind2, ind3);

	for (i = 0; i < ind3; i++)
	{
		if (i < ind1) arr3[i] = arr1[i];

		if (i >= ind1) arr3[i] = arr2[i - ind1];

		printf("%d  ", arr3[i]);
	}

	printf("\n\n\nC��������� C[%d] ������� �� �������� �������� ��������� : \n\n", ind3);

	// ����� �������� //
	for (i = 0; i < ind3 - 1; i++)		// ���������� ��������� ind3-1 ���������
		for (j = ind3 - 2; j >= i; j--)		// ���� � ����� ������� � ������
			if (arr3[j] < arr3[j + 1])		// ���� �������� ����� ���������, ...
			{
				c = arr3[j];				// ���������� �����
				arr3[j] = arr3[j + 1];		// ������������ arr3[j] � arr3[j + 1]
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
				printf("\n\n���������� �������� ����������� �� �������� %d � %d \n\n", i, j);
				i = ind;
			}
		}

	printf("\n���-�� ������ �� ������� ���������� ���������� ��������� = %d \n\n", count);

}


void Task4()
{
	SetConsoleTextAttribute(hConsole, 10);
	printf("\n--------------------------------------------------------------------------\n\nTask4\n\n");
	SetConsoleTextAttribute(hConsole, 7);

	int const ind = 10;
	int arr[ind], i, j, q;

	for (i = 0; i < ind; i++)
	{
		arr[i] = pow(2, i + 1);
		printf("A[%d] = %d \n", i, arr[i]);
	}

	q = arr[0 + 1] / arr[0];

	printf("\n����������� �������������� ���������� q = %d", q);

	for (i = 0; i < ind-1; i++)
		if (arr[i+1] == arr[i] * q) printf("\n����������� ���������� q = %d \n", q);
			else printf("\n�� �������� \n\n", q);
}


void Task5()
{
	SetConsoleTextAttribute(hConsole, 10);
	printf("\n--------------------------------------------------------------------------\n\nTask5\n\n");
	printf("\n� ����������.... \n\n");
	SetConsoleTextAttribute(hConsole, 7);
}


void Task6()
{
	SetConsoleTextAttribute(hConsole, 10);
	printf("\n--------------------------------------------------------------------------\n\nTask6\n\n");
	printf("\n� ����������.... \n\n");
	SetConsoleTextAttribute(hConsole, 7);
}


void Task7()
{
	SetConsoleTextAttribute(hConsole, 10);
	printf("\n--------------------------------------------------------------------------\n\nTask7\n\n");
	printf("\n� ����������.... \n\n");
	SetConsoleTextAttribute(hConsole, 7);
}


void Task8()
{
	SetConsoleTextAttribute(hConsole, 10);
	printf("\n--------------------------------------------------------------------------\n\nTask8\n\n");
	printf("\n� ����������.... \n\n");
	SetConsoleTextAttribute(hConsole, 7);
}


void Task9()
{
	SetConsoleTextAttribute(hConsole, 10);
	printf("\n--------------------------------------------------------------------------\n\nTask9\n\n");
	printf("\n� ����������.... \n\n");
	SetConsoleTextAttribute(hConsole, 7);
}


void Task10()
{
	SetConsoleTextAttribute(hConsole, 10);
	printf("\n--------------------------------------------------------------------------\n\nTask10\n\n");
	printf("\n� ����������.... \n\n");
	SetConsoleTextAttribute(hConsole, 7);
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
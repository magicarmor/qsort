/*.........................................................
Титов Р.В ИУ 8-21 "Алгоритм быстрой сортировки (QuickSort)"
...........................................................*/
/*...................Declarations..........................*/
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_VAL 30
////////////////////FunctionPrototip////////////////////////
int InputN ( void );
int* InputMassive( int );
void QuickSort( int* );
void OutputMassive( int*, int );
////////////////////////////////////////////////////////////
/*.......................Main..............................*/
int main() {
	srand(time(NULL));	
	int n = InputN();
	int* massive = InputMassive( n );		
	QuickSort( massive );
	OutputMassive( massive, n );
	getch();
	return 0;
}
/*.......................EndMain..............................*/
/*.......................InpunN...............................*/
int InputN ( void ) {
	int n = 0;
	printf("Enter (n < %d)  n = ", MAX_VAL);
	scanf("%d", &n);
	return n;
}
/*.......................EndInpunN............................*/
/*..................InputMassive..............................*/
int* InputMassive( int N ) {
	int i = 0, n = N, massive[MAX_VAL];// Выделяем память
	for(; i < n; i++) {                // Заполняем рандомно
		massive[i] = rand() % 100;     //
	}                                  //  
	return massive;                    // Возвращаем указатель на массив
}
/*..................EndInputMassive...........................*/
/*.......................QuickSort............................*/
void QuickSort(int* arr) {

	int left, right;	              // Получаем координаты левую и правую
	printf("Enter left half = ");
	scanf("%d", &left);
	printf("Enter right half = ");
	scanf("%d", &right);
	int tmp;
	int pivot = arr[(left + right) / 2];
	/* partition */                   // Делим на части и сортируем
	while (left <= right) { 
		while (arr[left] < pivot)
			left++;
		while (arr[right] > pivot)
			right--;
		if (left <= right) {
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
			left++;
			right--;
		}
	}
}
/*....................EndQuickSort............................*/
/*..................OutputMassive.............................*/
void OutputMassive( int* massive, int N) {
	int* arr = massive;            // Выделяем память и инициализируем
	int n = N;                     // Выделяем память и инициализируем
	for(int i = 0; i < n; ++i) {   //
		printf("A[%d] = %d \n", i, arr[i] );// Выводим массив
	}                              //	
}
/*..................EndOutputMassive..........................*/
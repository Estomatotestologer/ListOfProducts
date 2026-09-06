#include "defenitions.h"
#include <stdio.h>
#include "print.h"
#include <iostream>

void printElement(Goods element) {
	printf("%s %s %.3f\n", element.name, element.country, element.price);
}
void print(Goods* array, int n) {
	system("cls");
	printf("Список товаров без сортировки: \n");
	for (int i = 0; i < n; i++) printElement(array[i]);
}
void printSortPrice(Goods* array, int n) {
	system("cls");
	Goods** sortArray = new Goods* [n];
	for (int i = 0; i < n; i++) sortArray[i] = &array[i];
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (sortArray[j]->price > sortArray[j + 1]->price) {
				Goods* tmp = sortArray[j];
				sortArray[j] = sortArray[j + 1];
				sortArray[j + 1] = tmp;
			}
		}
	}
	printf("Отсортированный список по возрастанию цены: \n");
	for (int i = 0; i < n; i++) {
		printElement(*sortArray[i]);
	}
	delete[] sortArray;
}
void printSortName(Goods* array, int n) {
	system("cls");
	Goods** sortArray = new Goods * [n];
	for (int i = 0; i < n; i++) sortArray[i] = &array[i];
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (strcmp(sortArray[j]->name,sortArray[j + 1]->name) > 0) {
				Goods* tmp = sortArray[j];
				sortArray[j] = sortArray[j + 1];
				sortArray[j + 1] = tmp;
			}
		}
	}
	printf("Отсортированный список по названию товара: \n");
	for (int i = 0; i < n; i++) {
		printElement(*sortArray[i]);
	}
	delete[] sortArray;
}
void printCountryName(Goods* array, int n){
	system("cls");
	printf("Введите страну производитель: ");
	char country[MAX];
	scanf_s("%s", country, MAX);
	int col = 0;
	for (int i = 0; i < n; i++) {
		if (strcmp(array[i].country, country) == 0) {
			if (col == 0) printf("Найдены товары: \n");
			printElement(array[i]);
			col++;
		}
	}
	if (col == 0) {
		printf("Товаров из введенной страны не найдено\n");
		system("pause");
		return;
	}

}
#include <iostream>
#include <string.h>
#include "defenitions.h"
#include "changeList.h"
#include "print.h"
#include <Windows.h>
#include "save.h"
using namespace std;

void razbor(char* str, Goods &element) {
	char* buf = nullptr;
	char* ptr = strtok_s(str, " ", &buf);
	strcpy_s(element.name, MAX,ptr);
	ptr = strtok_s(nullptr, " ", &buf);
	strcpy_s(element.country, MAX, ptr);
	ptr = strtok_s(nullptr, " ", &buf);
	element.price = atof(ptr);
}

int menu() {
	int choice;
	printf("\n");
	printf("\nВыберите вариант:\n");
	printf("1 - Распечатать список товаров без сортировки\n");
	printf("2 - Распечатать список товаров, упорядоченный по возрастанию цены\n");
	printf("3 - Распечатать список товаров, упорядоченный в лексикографическом порядке по названию товара\n");
	printf("4 - Добавить товар\n");
	printf("5 - Удалить товар\n");
	printf("6 - Распечатать список товаров из некоторой страны\n");
	printf("7 - Сохранить данные в файл\n");
	printf("8 - Завершение работы\n");
	printf("Ваш выбор: ");
	scanf_s("%d", &choice);
	while (choice > 8 || choice < 1) {
		printf("Неверный выбор. Повторите ввод: ");
		scanf_s("%d", &choice);
	}
	printf("\n");
	return choice;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FILE* input = nullptr;
	if (fopen_s(&input, "data.txt", "r") != 0) {
		printf("Ошибка открытия файла для чтения\n");
		system("pause");
		return 0;
	}
	int col;
	fscanf_s(input, "%d\n", &col);
	Goods* list = new Goods[col];
	for (int i = 0; i < col; i++) {
		char str[MAX];
		fgets(str, MAX, input);
		razbor(str, list[i]);
	}
	print(list, col);
	if (fclose(input) != 0) {
		printf("Ошибка закрытия файла для чтения\n");
		system("pause");
		return 0;
	}
	while (true) {
		int c = menu();
		switch (c) {
		case 1: print(list, col); break;
		case 2: printSortPrice(list, col); break;
		case 3: printSortName(list, col); break;
		case 4: addGood(list, col); break;
		case 5: delGood(list, col); break;
		case 6: printCountryName(list, col); break;
		case 7: saveFile(list, col); break;
		case 8: closeFile(list, col); delete[] list; system("pause"); return 0;
		}
	}
	
}
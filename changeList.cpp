#include "defenitions.h"
#include <iostream>
#include "print.h"
void addGood(Goods* &array, int &n) {
	Goods* ptr = new Goods[n + 1];
	for (int i = 0; i < n+1; i++) ptr[i] = array[i];
	printf("Введите название товара: ");
	scanf_s("%s", ptr[n].name, MAX);
	printf("Введите страну происхождения товара: ");
	scanf_s("%s", ptr[n].country, MAX);
	printf("Введите цену товара: ");
	scanf_s("%lf", &ptr[n].price);
	delete[] array;
	array = ptr;
	n++;
	printf("Добавлен элемент: ");
	printElement(array[n-1]);
	system("pause");
	system("cls");
}

void delOneGood(Goods* &array, int index, int &n) {
	Goods* ptr = new Goods[n - 1];
	for (int i = 0, j = 0; i < n; i++) {
		if (i == index) continue;
		ptr[j] = array[i];
		j++;
	}
	delete[] array;
	array = ptr;
	n--;
}

void delGood(Goods* &array, int &n) {
	printf("Введите имя товара, который нужно удалить: ");
	char good_for_del[MAX];
	scanf_s("%s", good_for_del, MAX);
	char choice;
	int col_del = 0;
	for (int i = 0; i < n; i++) {
		if (strcmp(good_for_del, array[i].name) == 0) {
			printf("Удалить %s %s %.3lf (Y/N)?: ", array[i].name, array[i].country, array[i].price);
			getchar();
			scanf_s("%c", &choice, 1);
			if (choice == 'y' || choice == 'Y' || choice == 'у' || choice == 'У') {
				delOneGood(array, i , n);
				i--;
				col_del++;
			}
		}
	}
	if (col_del == 0) printf("Не найдено товаров для удаления\n");
	else printf("Продукты удалены\n");
	system("pause");
	system("cls");
}
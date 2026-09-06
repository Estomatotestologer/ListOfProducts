#include <iostream>
#include "defenitions.h"
void saveFile(Goods* array, int n) {
	FILE* output = nullptr;
	if (fopen_s(&output, "data.txt", "w") != 0) {
		printf("Не удалось открыть файл для сохранения");
		return;
	}
	fprintf(output, "%d\n", n);
	for (int i = 0; i < n; i++) {
		fprintf(output, "%s %s %.3lf\n", array[i].name, array[i].country, array[i].price);
	}
	if (fclose(output) != 0) {
		printf("Не удалось закрыть и сохранить файл");
		return;
	}
	printf("Данные сохранены\n");
}
void closeFile(Goods* array, int n) {
	char choice;
	printf("Желаете ли сохранить изменения в файл (Y/N?): ");
	getchar();
	scanf_s("%c", &choice, 1);
	if (choice == 'y' || choice == 'Y' || choice == 'у' || choice == 'У') saveFile (array,n);
	else printf("Завершение работы без сохранения файла\n");
}
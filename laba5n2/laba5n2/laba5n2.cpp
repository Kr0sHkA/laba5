﻿#include <iostream>
#include <clocale>

using namespace std;

/*
 * @brief Л/р 5 Одномерные массивы
 * Пислегин Евгений Константинович ИВТ - 32
 * Дан массив размера N (N — четное число).
 * Поменять местами первую и вторую половины массива.
 * @return 0 - всё ок, 1 - ошибка ввода
*/

//Код со статическим выделением памяти

int main() {
	setlocale(LC_ALL, "ru");
	//Ввод константы (максимального размера массива)
	const size_t ms = 100;
	//Создание массива
	int a[ms];
	size_t N;
	//Ввод кол-ва переменных
	cout << "Укажите количество переменных(чётное число в диапазоне [1; 100]): ";
	cin >> N;

	//Проверка условия ввода
	if (N == 0 || N > ms || N % 2 != 0) {
		cout << "Ошибка: количество должно находиться в диапазоне [1; "
			<< ms << "] " << "и быть чётным" << endl;
		return 1;
	}

	//Заполнение массива
	cout << "Введите N переменных:\n";
	for (size_t i = 0; i < N; i++) {
		cin >> a[i];
	}
	// Вводим переменную "половина длины"
	int pd = N / 2;

	for (int i = 0; i < N / 2; i++)
	{
		//Прописываем цикл, в котором производим замену первой и второй половины массива
		int temp = a[i];
		a[i] = a[pd];
		a[pd++] = temp;
	}
	//Выводим результат
	cout << "Результат: \n";
	for (int i = 0; i < N; i++)
		cout << '[' << i + 1 << "]= " << a[i] << endl;
	return 0;
}


/*
//Код с динамическим выделением памяти

int main() {
	setlocale(LC_ALL, "ru");

	size_t N;
	cout << "Укажите количество переменных: ";
	cin >> N;
	if (N == 0 || N % 2 != 0) {
		cerr << "Ошибка: количество должно быть больше нуля и должно быть чётным." << endl;
		return 1;
	}

	/// Указатель на динамический массив
	int *a;
	// динамическое выделение памяти динамического массива
	a = new int[N];

	cout << "Введите N переменных:\n";
	for (size_t i = 0; i < N; i++) {
		cin >> a[i];
	}

	// Вводим переменную "половина длины"
	int pd = N / 2;

	for (int i = 0; i < N / 2; i++)
	{
		//Прописываем цикл, в котором производим замену первой и второй половины массива
		int temp = a[i];
		a[i] = a[pd];
		a[pd++] = temp;
	}
	//Выводим результат
	cout << "Результат: \n";
	for (int i = 0; i < N; i++) {
		cout << '[' << i + 1 << "]= " << a[i] << endl;
	}

	// освобождение памяти динамического массива
	delete[] a;
	return 0;
}
*/
#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <string>
#include <vector>

using namespace std;

namespace l1
{
	class Txt
	{
	private:		
		// Динамический массив для хранения строк из файла
		string* linesArray;
		// Переменная размера динамического массива
		size_t arraySize;

	public:		
		// Конструктор по умолчанию
		Txt(const string& filePath = "");

		// Конструктор копирования
		Txt(const Txt& txt);

		// Перегрузка оператора присваивания копий
		Txt& operator = (const Txt& txt);

		// Конструктор перемещения
		Txt(Txt&& txt) noexcept;

		// Перегрузка оператора присваивания перемещений
		Txt& operator = (Txt&& txt) noexcept;

		// Деструктор
		~Txt();

		// Функция возвращает кол-во строк записанных с файла в вектор
		size_t size() const;
	};
}
#include "Txt.h"

// Конструктор по умолчанию
l1::Txt::Txt(const string& filePath) :
	linesArray(nullptr), arraySize(0)
{
	if (!filePath.empty())
	{
		ifstream file;
		file.open(filePath);

		if (file.is_open())
		{
			string line;

			while (getline(file, line))
				arraySize++;

			file.clear();
			file.seekg(0, ios::beg);

			linesArray = new string[arraySize];

			for (int i = 0; i < arraySize; i++)
				getline(file, linesArray[i]);

			file.close();
		}
	}
}

// Конструктор копирования
l1::Txt::Txt(const l1::Txt& txt) :
	arraySize(txt.arraySize), linesArray(new string[txt.arraySize])
{
	copy(txt.linesArray, txt.linesArray + arraySize, linesArray);
}

// Перегрузка оператора присваивания копированием
l1::Txt& l1::Txt::operator = (const l1::Txt& txt)
{
	if (this != &txt)
	{
		delete[] linesArray;

		arraySize = txt.arraySize;
		linesArray = new string[arraySize];

		copy(txt.linesArray, txt.linesArray + arraySize, linesArray);
	}
	return *this;
}

// Конструктор перемещения
l1::Txt::Txt(l1::Txt&& txt) noexcept :
	linesArray(nullptr), arraySize(0)
{
	linesArray = txt.linesArray;
	arraySize = txt.arraySize;

	txt.linesArray = nullptr;
	txt.arraySize = 0;
}

// Перегрузка оператора присваивания перемещением
l1::Txt& l1::Txt::operator = (l1::Txt&& txt) noexcept
{
	if (this != &txt)
	{
		delete[] linesArray;

		linesArray = txt.linesArray;
		arraySize = txt.arraySize;

		txt.linesArray = nullptr;
		txt.arraySize = 0;
	}
	return *this;
}

// Деструктор
l1::Txt::~Txt()
{
	if (linesArray != nullptr)
		delete[] linesArray;
}

// Функция возвращает кол-во строк записанных с файла в вектор
size_t l1::Txt::size() const
{
	return arraySize;
}
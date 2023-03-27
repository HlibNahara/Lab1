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
		// ������������ ������ ��� �������� ����� �� �����
		string* linesArray;
		// ���������� ������� ������������� �������
		size_t arraySize;

	public:		
		// ����������� �� ���������
		Txt(const string& filePath = "");

		// ����������� �����������
		Txt(const Txt& txt);

		// ���������� ��������� ������������ �����
		Txt& operator = (const Txt& txt);

		// ����������� �����������
		Txt(Txt&& txt) noexcept;

		// ���������� ��������� ������������ �����������
		Txt& operator = (Txt&& txt) noexcept;

		// ����������
		~Txt();

		// ������� ���������� ���-�� ����� ���������� � ����� � ������
		size_t size() const;
	};
}
// ConsoleApplication1(ZI).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <windows.h> 
#include <stdio.h>
#include <wincrypt.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string convertToString(char* a, int size)
{
	int i;
	string s = "";
	for (i = 0; i < size; i++) {
		s = s + a[i];
	}
	return s;
}

void main()
{
	HCRYPTPROV hProv;
	HCRYPTKEY hSessionKey;

	string line;
	char string[] = "Test Hello World World Hello";
	DWORD count = strlen(string);
	ifstream f_in("test.txt");
	while (getline(f_in,line))
	{

	}


	// Получение контекста криптопровайдера
	if (!CryptAcquireContext(&hProv, NULL, NULL,PROV_RSA_FULL, CRYPT_VERIFYCONTEXT))
{
		std::cout << "CryptAcquireContext";
return;
}

	std::cout << "Cryptographic provider initialized" << std::endl;

	// Генерация сессионного ключа
	if (!CryptGenKey(hProv, CALG_RC4, CRYPT_EXPORTABLE, &hSessionKey))
{
		
		std::cout << "CryptGenKey";
return;
}
	
	

	std::cout << "Session key generated" << std::endl;

	// Данные для шифрования


	// Шифрование данных
	if (!CryptEncrypt(hSessionKey, 0, true, 0, (BYTE*)string, &count, strlen(string)))
{
//Error("CryptEncrypt");
return;
}
	std::cout << "Session Key: " << hSessionKey << std::endl;

	std::cout << "Encryption completed" << std::endl;

	// Тестовый вывод на экран
	std::cout << "Encrypted string: " << string << std::endl;
	convertToString(string, strlen(string));
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

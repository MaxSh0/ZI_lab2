// ConsoleApplication1(ZI).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <windows.h> 
#include <stdio.h>
#include <wincrypt.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;




void main()
{
	setlocale(LC_ALL, "Russian");
	HCRYPTPROV hProv;
	HCRYPTKEY hSessionKey;

	string line = "Hello world";
	char string[] = "Hello world"; //new char[line.length()];
	/*for (int i = 0; i < line.length(); i++) {
		string[i] = line[i];
	}*/

	cout << string << endl;

	DWORD count = strlen(string);
	

	std::ifstream in("C:\\Users\\mshak_000\\Desktop\\ZI_lab2\\test2.txt"); // окрываем файл для чтения
	if (in.is_open())
	{
		while (getline(in, line))
		{
			std::cout << line << std::endl;
		}
	}
	in.close();     // закрываем файл


	// Получение контекста криптопровайдера
	if (!CryptAcquireContext(&hProv, NULL, NULL,PROV_RSA_FULL, CRYPT_VERIFYCONTEXT))
{
		std::cout << "Ошибка получения контекста криптопровайдера ";
return;
}

	std::cout << "Cryptographic provider initialized" << std::endl;

	// Генерация сессионного ключа
	if (!CryptGenKey(hProv, CALG_RC4, CRYPT_EXPORTABLE, &hSessionKey))
{
		
		std::cout << "Ошибка генерации ключа";
return;
}
	
	

	std::cout << "Session key generated" << std::endl;

	// Данные для шифрования


	// Шифрование данных
	if (!CryptEncrypt(hSessionKey, 0, true, 0, (BYTE*)string, &count, strlen(string)))
{
	std::cout << "Ошибка шифрования";
return;
}
	std::cout << "Session Key: " << hSessionKey << std::endl;

	std::cout << "Encryption completed" << std::endl;

	// Тестовый вывод на экран
	std::cout << "Encrypted string: " << string << std::endl;




	std::ofstream out;          // поток для записи
	out.open("C:\\Users\\mshak_000\\Desktop\\ZI_lab2\\test2.txt"); // окрываем файл для записи
	if (out.is_open())
	{
		out << string << std::endl;
	}






	if (!CryptDecrypt(hSessionKey, 0, true, 0, (BYTE*)string, &count))
	{
	std::cout << "Ошибка расшифровки";
	}
	std::cout << "Decrypted string: " << string << std::endl;


}



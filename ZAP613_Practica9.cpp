// ZAP613_Practica9.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

// ZAP613_MatrizDinamica.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

bool ReadInt(int& valor)
{
	bool ok = std::cin.good();

	if (!ok)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	return ok;
}

int main()
{
	int m, n, dato, mat[3][2];
	int opc, cont;
	do
	{
		std::cout << "\nPresiona 1 si quieres una matriz de 3x2 que se rellene automaticamente.\nPresiona 2 si quieres una matriz en donde tu escogas las filas y columnas, aparte de los datos.\n";
		std::cin >> opc;

		switch (opc)
		{
		case 1:
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					mat[i][j] = rand() % 10;
				}
			}
			std::cout << "\n";
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					std::cout << "El valor en la posicion [" << i << "]" << "[" << j << "] es : " << mat[i][j] << "\n";
				}
			}
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					std::cout << mat[i][j] << " ";
				}
				std::cout << "\n";
			}

			break;
		case 2:
			std::cout << "Ingresa el numero de columnas\n";
			std::cin >> m;
			std::cout << "Ingresa el numero de filas\n";
			std::cin >> n;
			int** arreglo = new int* [n];

			for (int i = 0; i < m; i++)
			{
				arreglo[i] = new int[n];
			}

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					std::cout << "Ingresa el valor en la posicion [" << i << "]" << "[" << j << "] \n";
					std::cin >> dato;
					while (true)
					{
						if (!ReadInt(dato))
						{
							std::cout << "\nNo ingresaste un numero entero.\n";
							std::cout << "\nIngresa el valor en la posicion [" << i << "]" << "[" << j << "] \n";
							std::cin >> dato;
						}
						else
							break;
					}
					arreglo[i][j] = dato;
				}
				std::cout << "\n";
			}

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					std::cout << "El valor en la posicion [" << i << "]" << "[" << j << "] es : " << arreglo[i][j] << "\n";
				}
			}
			std::cout << "\n";
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					std::cout << arreglo[i][j] << " ";
				}
				std::cout << "\n";
			}
			break;


		}
		std::cout << "\nSi quieres repetir el programa, presiona 1.\nSi quieres salir del programa presiona cualquier tecla.\n";
		std::cin >> cont;
	} while (cont == 1);
}

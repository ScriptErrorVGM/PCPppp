// BoyereMooore.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

# include <limits.h>
# include <string.h>
# include <stdio.h>

# define NO_OF_CHARS 256
using namespace std;		

// Функция полезности для получения максимум двух целых чисел
int max(int a, int b)
{
	return (a > b) ? a : b;
}

// Функция предварительной обработки для плохой эвристической характеристики Бойера Мура 
void badCharHeuristic(char *str, int size, int badchar[NO_OF_CHARS])
{
	int i;

	// Инициализация всех вхождения как -1
	for (i = 0; i < NO_OF_CHARS; i++)
		badchar[i] = -1;

	// Заполнение текущего значения последнего вхождения символа
	for (i = 0; i < size; i++)
		badchar[(int)str[i]] = i;
}

void search(char *txt, char *pat)
{
	int m = strlen(pat);
	int n = strlen(txt);

	int badchar[NO_OF_CHARS];

	badCharHeuristic(pat, m, badchar);

	int s = 0; // s - смещение шаблона относительно текста
	while (s <= (n - m))
	{
		int j = m - 1;

		while (j >= 0 && pat[j] == txt[s + j])
			j--;

		if (j < 0)
		{
			cout << "\n pattern occurs at shift = " << s << endl;

			s += (s + m < n) ? m - badchar[txt[s + m]] : 1;

		}

		else
			s += max(1, j - badchar[txt[s + j]]);
	}
}

/* Driver program to test above funtion */
int main()
{
	char txt[] = "ABAAABCD vbnm  AAA";
	char pat[] = "A";
	search(txt, pat);
	return 0;
}

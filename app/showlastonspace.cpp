/**
 * showlastnonspace.c -- реализует команду вывода каждого последнего непробельного символа строки
 *
 * Copyright (c) 2021, Oleg Lisickii <olegwolf360@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */
using namespace std;
#include <iostream>
#include <cstdio>
#include <cassert>
#include "common.h"
#include <cstring>
#include <string>
#include "text/text.h"

static void show_line(int index, string contents, int cursor, void *data);

/**
 * Вывод каждого последнего непробельного символа строки в прямом порядке следования строк
 */
void showlastnonspace(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, show_line, NULL);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void show_line(int index, string contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
  assert(contents.c_str() != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);
    UNUSED(cursor);

    char * con = new char [contents.length()+1];
    strcpy(con, contents.c_str());
    int j = strlen(con) - 1;

    /*Идём с конца до пробела или (если строка состоит только из пробелов) начала строки*/
    while(con[j] == ' ' && j > -1) {
        j = j-1;
    }

    /* Вывод на экран */
    /*Если дошли до начала строки, то выводит \n, иначе последний непробельный символ*/
    if (j == -1 ) printf("\n");
    else printf("%c\n", con[j]);
    delete con;
}

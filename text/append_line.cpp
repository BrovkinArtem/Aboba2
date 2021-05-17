/**
 * append_line.c -- функции для добавления строк
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <assert.h>
#include <list>

/**
 * Добавляет одну строку к тексту
 * @param txt текст
 * @param contents новая строка
 * @returns none
 */
void append_line(text txt, std::string contents)
{
    /* Добавляем в конец листа новую строку */ 
    txt->lst->push_back(contents);

    /* Указатель курсора ставим на последнюю строку */ 
    txt->cursor->line = txt->lst->end();
    
    /* Ставим курсор на последнюю позицию  */ 
    txt->cursor->position = contents.length();
 
    txt->length++;
}

/**
 * create_text.cpp -- создает в памяти структуры для представления текста
 *
 * Copyright (c) 2021, Alexander Borodin <aborod@petrsu.ru>
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
 * Создает новый текстовый объект
 * @returns текст
 */
text create_text()
{
    text txt;

    /* Создаем структуру описания текста */
    if ((txt = (_list *) malloc(sizeof(_list))) == NULL) {
        fprintf(stderr, "Not enough memory!\n");
        exit(EXIT_FAILURE);
    }

    /* Создаем структуру описания курсора */
    if ((txt->cursor = (crsr *) malloc(sizeof(crsr))) == NULL) {
        fprintf(stderr, "Not enough memory!\n");
        exit(EXIT_FAILURE);
    }

    /* Только что созданный текст не содержит ни одной строки */
    txt->length = 0;

    /* Создаём новый объект класса */
    txt->lst = new std::list<std::string>();

    /* Курсор ставим в конец текста на последнюю позицию */
    txt->cursor->line = txt->lst->end();
    txt->cursor->position = 0;

    return txt;
}

    /**
    * c1n.cpp - exchanges the first and and the current lines
    *
    * Copyright (c) 2021, Brovkin Artem
    *
    * This code is licensed under a MIT-style license.
    */

    #include "_text.h"
    #include <iostream>
    #include <cstdio>
    #include <cassert>
    #include "../common.h"
    #include <cstring>
    #include <string>
    #include <iterator>
    #include <list>
    #include "text.h"
    /*
    |b| <-> |c| <-> |d| <-> |e| <-> |a|
    */

    void c1n(text txt) {
	std::list<std::string>::iterator first = txt->lst->begin();// текущая первая строка
    std::list<std::string>::iterator end = txt->lst->end(); // текущая последняя строка

    if(first == end) return; // если одна строка в доке, то выходим

    txt->lst->push_back(*first);
    txt->lst->push_front(*end);

    txt->lst->erase(first);
    txt->lst->erase(end);
    
    }

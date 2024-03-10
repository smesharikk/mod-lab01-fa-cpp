// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <cmath>

// Реализация функции для задачи №1
unsigned int faStr1(const char* str) {
    unsigned int count = 0;
    bool in_word = false;

    while (*str) {
        if (std::isalpha(*str)) { // Проверяем, является ли текущий символ буквой
            in_word = true; 
        }
        else if (std::isspace(*str) or *str == '\0') { // Проверяем, является ли текущий символ пробелом или концом строки
            if (in_word) { 
                in_word = false; 
            }
        }
        else if (std::isdigit(*str)) { // Если текущий символ является цифрой
            in_word = false; // Сбрасываем флаг слова
            while (*str and !std::isspace(*str)) // Пропускаем все цифры в слове
                str++;
            continue;
        }
        str++; 
    }

    return count;
}


// Реализация функции для задачи №2
unsigned int faStr2(const char* str) {
    bool in_word = false; // Флаг находимся ли мы внутри слова
    bool is_uppercase = false; // Флаг является ли текущее слово словом с заглавной буквы
    int word_count = 0; // Счетчик слов, начинающихся с заглавной буквы и содержащих только строчные буквы
    int i = 0; 

    while (str[i] != '\0') {
        if (str[i] != ' ' and !in_word) { // Если текущий символ не пробел и мы не находимся внутри слова
            in_word = true;
            is_uppercase = std::isupper(str[i]); 
        }
        else if (str[i] == ' ' and in_word) { // Если текущий символ пробел и мы находимся внутри слова
            in_word = false; 
            is_uppercase = false; 
        }
        else if (!std::islower(str[i]) and in_word and is_uppercase) { // Если текущий символ не строчная буква и это начало слова с заглавной буквы
            is_uppercase = false; 
            word_count--; 
        }
        i++;
    }

    return word_count; 
}


// Реализация функции для задачи №3
unsigned int faStr3(const char* str) {
    float letter_сount = 0; // Счетчик букв
    int word_сount = 0; // Счетчик слов
    bool in_word = false; // Флаг, указывающий на наличие слова
    
    while (*str != '\0') {
        if (*str == ' ') {
            if (in_word) {
                word_сount++;
            }
            in_word = false;
        }
        else {
            in_word = true;
            letter_сount++;
        }
        str++;
    }

    // Учитываем последнее слово, если строка не закончена
    if (in_word) {
        word_сount++;
    }

    // Если нет слов, средняя длина слова равна 0
    if (word_сount == 0) {
        return 0;
    }

    // Вычисляем среднюю длину слова, округляя до ближайшего целого
    unsigned int averageLength = round(letter_сount / word_сount);

    return averageLength;
}

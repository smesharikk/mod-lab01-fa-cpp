// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <cmath>


// Реализация функции для задачи №1
unsigned int faStr1(const char* str) {
    bool in_word = false;
    bool has_digit = false; // Флаг, указывающий на наличие цифр в слове
    unsigned int count = 0;
    unsigned int i = 0;

    while (str[i]) {
        if (str[i] != ' ' && !in_word) {
            in_word = true;
            has_digit = false; // Сбрасываем флаг наличия цифры при начале нового слова
            count++; // Увеличиваем счетчик слов
        }
        else if (str[i] != ' ' && in_word) {
            if (isdigit(str[i]) && !has_digit) {
                has_digit = true; // Устанавливаем флаг наличия цифры
                count--; 
            }
        }
        else if (str[i] == ' ' && in_word) {
            in_word = false; // Завершаем слово
        }
        i++; 
    }

    return count;
}

// Реализация функции для задачи №2
unsigned int faStr2(const char* str)
{
    bool is_in_word = false;
    bool is_good_word = true; // Флаг, указывающий на качество слова
    int count = 0;
    int i = 0;
    while (str[i])
    {
        // Чтение слова на начале слова
        if (str[i] != ' ' and !is_in_word)
        {
            is_in_word = true;
            is_good_word = isupper(str[i]); // Проверяем качество слова
            if (is_good_word)
                count++;
        }
        // Нашли не строчную букву в слове
        else if ((!isalpha(str[i]) or isupper(str[i])) and str[i] != ' ' and is_in_word and is_good_word)
        {
            is_good_word = false;
            count--;
        }
        // Окончание слова
        else if (str[i] == ' ' and is_in_word)
        {
            is_good_word = true; // Сбрасываем флаг для следующего слова
            is_in_word = false;
        }
        i++;
    }
    return count;
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

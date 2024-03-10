// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <cmath>

// Реализация функции для задачи №1
unsigned int faStr1(const char* str) {
    unsigned int count = 0;
    bool inWord = false;

    // Проходим по строке
    while (*str) {
        if (std::isalpha(*str)) { // Проверяем, является ли символ буквой
            if (!inWord) { // Если начинается новое слово
                inWord = true;
                count++; // Увеличиваем счетчик слов
            }
        }
        else {
            inWord = false; // Если встречаем не буквенный символ, завершаем слово
        }
        str++;
    }

    return count;
}

// Реализация функции для задачи №2
unsigned int faStr2(const char* str) {
    unsigned int count = 0;
    bool inWord = false;

    // Проходим по строке
    while (*str) {
        if (std::isupper(*str)) { // Проверяем, является ли символ заглавной буквой
            if (!inWord) { // Если начинается новое слово
                inWord = true;
                count++; // Увеличиваем счетчик слов
            }
        }
        else if (std::islower(*str) || std::isspace(*str)) {
            // Если это пробел или строчная латинская буква, продолжаем слово
            inWord = true;
        }
        else {
            inWord = false;
        }
        str++;
    }

    return count;
}

// Реализация функции для задачи №3
unsigned int faStr3(const char* str) {
    unsigned int wordCount = 0;
    unsigned int charCount = 0;

    // Проходим по строке
    while (*str) {
        if (std::isalpha(*str)) { // Если символ - буква
            charCount++; // Увеличиваем счетчик букв в слове
        }
        else if (std::isspace(*str) && charCount > 0) {
            wordCount++; // Если встретили пробел и длина слова больше нуля, увеличиваем счетчик слов
            charCount = 0; // Сбрасываем счетчик букв для нового слова
        }
        str++;
    }

    if (charCount > 0) { // Проверяем, осталось ли слово после конца строки
        wordCount++;
    }

    if (wordCount == 0) {
        return 0;
    }

    // Вычисляем среднюю длину слова и округляем до целого значения по правилам округления
    return static_cast<unsigned int>(std::round(static_cast<double>(charCount) / wordCount));
}

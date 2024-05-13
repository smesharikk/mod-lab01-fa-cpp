// Copyright 2024 UNN-IASR
#include "fun.h"
#include <cctype>
#include <cmath>

unsigned int faStr1(const char* str) {
    bool in_word = false;
    bool has_digit = false;
    unsigned int count = 0;
    unsigned int i = 0;
    while (str[i]) {
        if (str[i] != ' ' && !in_word) {
            has_digit = false;
            in_word = true;
            count++;
        }
        if (str[i] != ' ' && in_word) {
            if (isdigit(str[i]) && !has_digit) {
                has_digit = true;
                count--;
            }
        }
        if (str[i] == ' ' && in_word) {
            in_word = false;
        }

        i++;
    }
    return count;
}
unsigned int faStr2(const char* str) {
    bool inWord = false;
    bool hasDigit = false;
    unsigned int wordCount = 0;
    unsigned int i = 0;
    while (str[i]) {
        if (str[i]!= ' ' &&!inWord) {
            hasDigit = false;
            inWord = true;
            wordCount++;
        }
        if (str[i]!= ' ' && inWord) {
            if (isdigit(str[i]) &&!hasDigit) {
                hasDigit = true;
                wordCount--;
            }
        }
        if (str[i] == ' ' && inWord) {
            inWord = false;
        }
        i++;
    }
    return wordCount;
}
unsigned int faStr3(const char* str) {
    float letter_count = 0;
    int word_count = 0;
    bool in_word = false;
    while (*str != '\0') {
        if (*str == ' ') {
            if (in_word) {
                word_count++;
            }
            in_word = false;
        } else {
            in_word = true;
            letter_count++;
        }
        str++;
    }
    if (in_word) {
        word_count++;
    }
    if (word_count == 0) {
        return 0;
    }
    unsigned int averageLength = round(letter_count / word_count);
    return averageLength;
}

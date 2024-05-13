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
    bool in_word = false;
    bool is_good_word = true;
    int count = 0;
    int i = 0;
    while (str[i]) {
        if (str[i] != ' ' && !in_word) {
            in_word = true;
            is_good_word = isupper(str[i]);
            if (is_good_word)
                count++;
        } else if ((!isalpha(str[i]) || isupper(str[i]))
            && str[i] != ' ' && in_word && is_good_word) {
            is_good_word = false;
            count--;
        } else if (str[i] == ' ' && in_word) {
            is_good_word = true;
            in_word = false;
        }
        i++;
    }
    return count;
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

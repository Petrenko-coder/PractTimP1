#include "chifr.h"
#include <iostream>
#include <string>

using namespace std;

string chifr::encrypt(string input, const int key)
{
    int arraySize = input.length();
    int arrayHeight = (arraySize / key) + ((arraySize % key > 0) ? 1 : 0);
    int lowerStringLength = arraySize % key;
    int stars = (lowerStringLength > 0) ? key - lowerStringLength : 0;

    char** matrix = new char*[arrayHeight];
    for (int i = 0; i < arrayHeight; i++) matrix[i] = new char[key];

    string output;

    for (int i = 0; i < stars; i++) {
        matrix[arrayHeight - 1][(key - 1) - i] = '*';
    }
    int charId = 0;
    for (int i = 0; i < arrayHeight; i++) {
        for (int j = 0; j < key; j++) {
            if (matrix[i][j] == '*') continue;

            matrix[i][j] = input.at(charId);
            charId++;
        }
    }

    for (int i = 0; i < key; i++) {
        for (int j = 0; j < arrayHeight; j++) {
            if (matrix[j][(key - 1) - i] == '*') continue;
            output += matrix[j][(key - 1) - i];
        }
    }
    for (int i = 0; i < arrayHeight; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return output;
}

string chifr::decrypt(string input, const int key)
{
    int arrayHeight = (input.length() / key) + ((input.length() % key > 0) ? 1 : 0);
    int lowerStringLength = input.length() % key;
    int stars = (lowerStringLength > 0) ? key - lowerStringLength : 0;

    char** matrix = new char*[arrayHeight];
    for (int i = 0; i < arrayHeight; i++) matrix[i] = new char[key];

    string output;

    for (int i = 0; i < arrayHeight; i++) {
        for (int j = 0; j < key; j++) {
            matrix[i][j] = '\0';
        }
    }
    
    for (int i = 0; i < stars; i++) {
        matrix[arrayHeight - 1][(key - 1) - i] = '*';
    }
    
    int charId = 0;
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < arrayHeight; j++) {
            if (matrix[j][(key - 1) - i] == '*') continue;

            matrix[j][(key - 1) - i] = input.at(charId);
            charId++;
        }
    }
    
    for (int i = 0; i < input.length(); i++) {
        int y = i / key;
        int x = (i % key);

        char c = matrix[y][x];

        if (c != '\0') {
            output += c;
        }
    }
    for (int i = 0; i < arrayHeight; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return output;
}

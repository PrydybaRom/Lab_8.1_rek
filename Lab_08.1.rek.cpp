#include <iostream>
#include <cstring>

using namespace std;

// Рахує кількість + - =
int countSymbols(const char* str, char target) {
    if (*str == '\0') {
        return 0;
    }

    if (*str == target) {
        return 1 + countSymbols(str + 1, target);
    }

    return countSymbols(str + 1, target);
}

int countSymbolsPlus(const char* str) {
    return countSymbols(str, '+');
}

int countSymbolsMinus(const char* str) {
    return countSymbols(str, '-');
}

int countSymbolsEquals(const char* str) {
    return countSymbols(str, '=');
}



// Змінює символи + - = на **
void changeSymbols(const char* str, char* resultArray, int& newIndex, int index) {
    if (str[index] == '\0') {
        resultArray[newIndex] = '\0';
        return;
    }

    if (str[index] == '+' || str[index] == '-' || str[index] == '=') {
        resultArray[newIndex++] = '*';
        resultArray[newIndex++] = '*';
    }
    else {
        resultArray[newIndex++] = str[index];
    }

    changeSymbols(str, resultArray, newIndex, index + 1);
}

char* newSymbols(const char* str) {
    int length = strlen(str);
    char* resultArray = new char[length * 2 + 1];

    int newIndex = 0;

    changeSymbols(str, resultArray, newIndex, 0);

    return resultArray;
}

int main() {
    const int arraySize = 101;
    char str[arraySize];

    cout << "Enter string:" << std::endl;
    cin.getline(str, arraySize);

    int pCount = countSymbolsPlus(str);
    int mCount = countSymbolsMinus(str);
    int eCount = countSymbolsEquals(str);

    cout << "Str contained + : " << pCount << endl;
    cout << "Str contained - : " << mCount << endl;
    cout << "Str contained = : " << eCount << endl;

    char* modifiedArray = newSymbols(str);
    cout << "Modified Array : " << modifiedArray << endl;

    delete[] modifiedArray;

    return 0;
}

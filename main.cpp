#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Convert a character to its digit value
int charToDigit(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 10;
    } else if (c >= 'a' && c <= 'z') {
        return c - 'a' + 10;
    }
    return 0;
}

// Convert a digit value to character (uppercase)
char digitToChar(int digit) {
    if (digit < 10) {
        return '0' + digit;
    } else {
        return 'A' + (digit - 10);
    }
}

int main() {
    int m, n, base;
    cin >> m >> n >> base;
    cin.ignore(); // Ignore the newline after numbers

    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    // Determine the output width (max of two string lengths)
    int width = max(str1.length(), str2.length());

    // Pad the shorter string with leading zeros
    while (str1.length() < width) {
        str1 = "0" + str1;
    }
    while (str2.length() < width) {
        str2 = "0" + str2;
    }

    // Perform addition from right to left
    string result(width, '0');
    int carry = 0;

    for (int i = width - 1; i >= 0; i--) {
        int digit1 = charToDigit(str1[i]);
        int digit2 = charToDigit(str2[i]);
        int sum = digit1 + digit2 + carry;

        result[i] = digitToChar(sum % base);
        carry = sum / base;
    }

    // The carry is discarded due to fixed width

    cout << result << endl;

    return 0;
}

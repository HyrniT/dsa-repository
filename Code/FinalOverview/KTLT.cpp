#include <iostream>
#include <cstring> 

char* addBit(char* c, int n) {
    int size = strlen(c);
    char* newChars = new char[size + 2];
    
    for (int i = 0; i < size; i++) {
        newChars[i + 1] = c[i];
    }
    
    newChars[0] = '0' + n;
    newChars[size + 1] = '\0';
    
    return newChars;
}

char* toBitString(int N) {
    char* result = new char[1];
    result[0] = '\0';
    
    while (N > 0) {
        result = addBit(result, N % 2);
        N /= 2;
    }
    
    return result;
}

int main() {
    int number = 7;
    char* bitString = toBitString(number);
    
    std::cout << "Binary representation of " << number << ": " << bitString << std::endl;
    
    // Giải phóng bộ nhớ đã cấp phát
    delete[] bitString;
    
    return 0;
}

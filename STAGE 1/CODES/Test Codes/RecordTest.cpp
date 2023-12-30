#include "Record.h"
#include <iostream>
#include <fstream>

void testRecord() {
    Record record;
    record.setFileName("test.txt");

    // Dosyaya yazma iþlemi
    try {
        record.openFile();
        record.writeLine("Test satiri");
        record.closeFile();
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Yazma Hatasi: " << e.what() << std::endl;
    }

    // Dosyadan okuma iþlemi
    try {
        record.openFile();
        std::string line = record.readLine();
        std::string line2 = record.readLine();
        std::cout << "Yazilan: " << line2 << std::endl;
        std::cout << "Okunan: " << line<< std::endl;
        
        record.closeFile();
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Okuma Hatasi: " << e.what() << std::endl;
    }
}

int main() {
    testRecord();
    return 0;
}

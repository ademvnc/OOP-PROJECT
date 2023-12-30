#include "RobotOperator.h"
#include <iostream>

void testRobotOperator() {
    RobotOperator operator1("Operator Adi", 1234);

    // Þifreleme testi
    int encryptedCode = operator1.encryptCode(1234);
    std::cout << "Sifrelenmis Kod: " << encryptedCode << std::endl;

    // Þifre çözme testi
    int decryptedCode = operator1.decryptCode(encryptedCode);
    std::cout << "Sifresi Cozulmus Kod: " << decryptedCode << std::endl;

    // Eriþim kodu kontrolü
    bool isAccessCodeCorrect = operator1.checkAccessCode(1234);
    std::cout << "Erisim Kodu Dogru mu: " << (isAccessCodeCorrect ? "Evet" : "Hayýr") << std::endl;

    // Operator bilgilerinin yazdýrýlmasý
    operator1.print();
}

int main() {
    testRobotOperator();
    return 0;
}

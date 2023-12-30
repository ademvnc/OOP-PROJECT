#include "RobotOperator.h"
#include <iostream>

void testRobotOperator() {
    RobotOperator operator1("Operator Adi", 1234);

    // �ifreleme testi
    int encryptedCode = operator1.encryptCode(1234);
    std::cout << "Sifrelenmis Kod: " << encryptedCode << std::endl;

    // �ifre ��zme testi
    int decryptedCode = operator1.decryptCode(encryptedCode);
    std::cout << "Sifresi Cozulmus Kod: " << decryptedCode << std::endl;

    // Eri�im kodu kontrol�
    bool isAccessCodeCorrect = operator1.checkAccessCode(1234);
    std::cout << "Erisim Kodu Dogru mu: " << (isAccessCodeCorrect ? "Evet" : "Hay�r") << std::endl;

    // Operator bilgilerinin yazd�r�lmas�
    operator1.print();
}

int main() {
    testRobotOperator();
    return 0;
}

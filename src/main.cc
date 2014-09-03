#include <iostream>

int main()
{
    // Exemple
    int bin = 0b111000110010110011010001; // 11100011 00101100 11010001
    // bin est un exemple de code binaire après lecture de la ROM
    while (bin) // Tant que le nombre binaire != 0
    {
        int opcode = bin & 0xff; // Flag de 255 pour lire 8 bits max à la fois
        bin >>= 8;               // Après lecture de l'opcode, on passe au suivant
        switch (opcode)
        {
            case 0x00:
                // Action pour 0
                break;
            case 0x01:
                // Action pour 1
                break;
            // ...
            case 0xff:
                // Action pour 255
                break;
        }
    }
    return 0;
}

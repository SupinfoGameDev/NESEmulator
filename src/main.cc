#include <iostream>

int main()
{
    // Exemple
    int bin = 0b111000110010110011010001; // 11100011 00101100 11010001
    // bin est un exemple de code binaire après lecture de la ROM
    while (bin)
    {
        int opcode = bin & 0xff;
        bin >>= 8;
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

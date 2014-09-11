#include <iostream>
#include "../include/core.h"

// #$ => value
// $  => value in memory address

int main()
{
    // Exemple
    int bin = 0b111000110010110011010001; // 11100011 00101100 11010001
    // bin est un exemple de code binaire après lecture de la ROM
    while (bin)
    {
        u8 opcode = bin & 0xff;
        bin >>= 8;
        switch (opcode)
        {
            case 0x00:
                return 0; // BRK instruction
                break;
                
            case 0x01:
                // ...
                break;
                
            case 0x30:
                // BPL $           ; Goto $ while X is not -1.
                break;
                
            case 0x4c:
            case 0x6c:
                // JMP #$1 #$2     ; Jump #$1#$2 (little-endiant)
                break;
                
            case 0x95:
                // STA $, X        ; Store A into $ offset with X.
                break;
                
            case 0xa2:
                // LDX #$
                break;
                
            case 0x0a:
                ASL();
                break;
                
            case 0xa5:
                // LDA $
                break;
                
            case 0xa9:
                // LDA #$
                break;
                
            case 0xaa:
                TAX();
            case 0xad:
                // LDA A, $ (avec value sur 2 octets)
                break;
                
            case 0xca:
                // DEX (decrement X)
                break;
                
            case 0xff:
                // ...
                break;
        }
    }
    return 0;
}

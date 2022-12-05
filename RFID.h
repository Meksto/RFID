/*=================================================
 * ���������� ���������� �� ��������� ����� ������
 * ��� ���������� RFID
 *-------------------------------------------------
 * RFID reader. RFID.h
 *
 *                  06.12.2022z
 *=================================================
 */

// -- Referenses ------------------------------------
// .........................................................................................
// Definitions:

// Database-ID  - ������-������������ ������� ���������� ����� RFID � ���� ������.
// Owner-ID     - ������ ��������� ��������, ����������� ��������.
// Program-ID   - ������ ���������� ������� ��������, ����������� ���������� ��������.
// Serial-ID    - �������, � ������� ����� ����������� ������ ������ RFID.
// ..........................................................................................
// Restrictions:

// Object-ID [0 : 32767] or [32767 : 65535]
// ..........................................................................................
// Bit-map:
// < ---------------------------------- 96 bit -------------------------------------------->
// 00h ------- 08h -------- 10h --------- 20h --------------- 48h --------60h ----------- 5Fh
// ----------------------------------------------------------------------------------------
// |     0       |     1     |   2  |  3   | 4 | 5 | 6 | 7 | 8 |     9     |   10  |   11  |
// -----------------------------------------------------------------------------------------
// | Database-ID |  Owner-ID | Program-ID  |     Serial-ID     |  Owner-ID |  Object-ID    |
// -----------------------------------------------------------------------------------------

// ������ �� ������������� ���������� ������ ������
#ifndef RFID_H
#define RFID_H

//-- Includes -------------------------------------
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <array>
#include <Windows.h>

//-- Namespaces ------------------------------------
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::hex;
using std::ofstream;

#define ARRAY_SIZE(array)   (sizeof((array))/sizeof((array[0])))    // ������� �������� ������� �������

class RFID {
    public:
        RFID();                         // ����������� ������ RFID
        ~RFID();                        // ����������
        // -- Matrix algoritms --
        void generateRandomData(void);          // ��������� ��������� ������
        void consoleOutputHexMatrix(void);      // ����� � ������� ������� � ���� �������
        void fileOutputHexMatrix(void);         // ����� � ���� ������� � ���� �������

        unsigned char** matrixChar;     // ��������� ������������ ������ ��� ������� ����� RFID
        unsigned char* msg;             // ��������� ��������

    private:
        // -- Function definition --
        const string    FILE_NAME = "����1.txt";       // ���� ��������� ��������� ������
        const string    FILE_CODE_NAME = "����2.txt";  // ����
        const int       STRING_LENGTH = 11;                 // ����� ������
        int             ROW_LENGTH = 0;                         // ����� �������

        const char letters[241] = "!\"#$%&'()*=,-./0123456789:;<?@ABCDEF\
        GHIJKLMNOPQRSTUVWXYZ[] ^_`abcdefghijklmnopqrstuvwxyz{|}~�����\
        Ũ����������������������������������������������������������"; // ������� ���������

        uint8_t     DatabaseID;     // RFID - DatabaseID
        uint16_t    OwnerID;        // RFID - OwnerID
        uint16_t    ProgramID;      // RFID - ProgramID
        uint8_t     SerialID[5];    // RFID -SerialID[5]
        uint8_t     ObjectID;       // RFID - ObjectID
};
#endif
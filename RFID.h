/*=================================================
 * Разработка приложения по генерации строк данных
 * для технологии RFID
 *-------------------------------------------------
 * RFID reader. RFID.h
 *
 *                  06.12.2022z
 *=================================================
 */

// -- Referenses ------------------------------------
// .........................................................................................
// Definitions:

// Database-ID  - Маркер-определитель области применения метки RFID в базе данных.
// Owner-ID     - Маркер владельца элемента, помечаемого маркером.
// Program-ID   - Маркер подфункции данного элемента, опредленной владельцем элемента.
// Serial-ID    - Объекты, к ктороым будет прикрепленн данный маркер RFID.
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

// Защита от множественных объявлений одного класса
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

#define ARRAY_SIZE(array)   (sizeof((array))/sizeof((array[0])))    // Функция подсчета размера массива

class RFID {
    public:
        RFID();                         // Конструктор класса RFID
        ~RFID();                        // Деструктор
        // -- Matrix algoritms --
        void generateRandomData(void);          // Генератор случайных данных
        void consoleOutputHexMatrix(void);      // Вывод в консоль матрицы в хекс формате
        void fileOutputHexMatrix(void);         // Вывод в файл матрицы в хекс формате

        unsigned char** matrixChar;     // Двумерный динамический массив для матрицы полей RFID
        unsigned char* msg;             // Сообщение передачи

    private:
        // -- Function definition --
        const string    FILE_NAME = "этап1.txt";       // Файл генерации случайных данных
        const string    FILE_CODE_NAME = "этап2.txt";  // Файл
        const int       STRING_LENGTH = 11;                 // длина строки
        int             ROW_LENGTH = 0;                         // длина столбца

        const char letters[241] = "!\"#$%&'()*=,-./0123456789:;<?@ABCDEF\
        GHIJKLMNOPQRSTUVWXYZ[] ^_`abcdefghijklmnopqrstuvwxyz{|}~АБВГД\
        ЕЁЖЗИЙКЛМНОПРСТУФКЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфкцчшщъыьэюя"; // Алфавит кодировки

        uint8_t     DatabaseID;     // RFID - DatabaseID
        uint16_t    OwnerID;        // RFID - OwnerID
        uint16_t    ProgramID;      // RFID - ProgramID
        uint8_t     SerialID[5];    // RFID -SerialID[5]
        uint8_t     ObjectID;       // RFID - ObjectID
};
#endif
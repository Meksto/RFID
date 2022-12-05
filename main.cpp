/*=================================================
 * Разработка приложения по генерации строк данных
 * для технологии RFID
 *-------------------------------------------------
 * Source main file. Main.c
 *
 *                  06.12.2022z
 *=================================================
 * Debug Configuration:
 * > chcp 866
 * > g++ main.cpp -o main.exe
 * > ./main.exe
 */

//-- Includes -------------------------------------
#include "main.h"

//-- Main function --------------------------------
int main(){
    system("chcp 866");
    system("cls");
    // -- Settings Main --
    setlocale(LC_ALL, "RUSSIAN");               // Настройка консоли для отображения кириллицы

    RFID *rfid = new RFID;  // Создание объекта
    rfid->generateRandomData();
    rfid->consoleOutputHexMatrix();
    rfid->fileOutputHexMatrix();
    delete rfid;            // Уничтожение объекта
    // -- End of program --
    return 0;
}
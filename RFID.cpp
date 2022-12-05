/*=================================================
 * ���������� ���������� �� ��������� ����� ������
 * ��� ���������� RFID
 *-------------------------------------------------
 * RFID reader. RFID.cpp
 *
 *                  06.12.2022z
 *=================================================
 *=================================================
 */
#include "RFID.h"

//-- Function -------------------------------------
RFID::RFID(){

}

RFID::~RFID(){
    for (int i = 0; i < ROW_LENGTH; i++) {  //������� ������� ������ ���������� �� ������� ���������2,
        delete[] matrixChar[i];             // � ����� ������� ���������1, ������� � �������� �� ���������2.
    }
    delete[] matrixChar;

    cout << "RFID: ������ �������." << endl;
}

void RFID::generateRandomData() {
    srand((unsigned)time(NULL)); // ��������� ������� ��� ���������� ��������� �����
    // -- Generate random values --
    cout << "[��������� ��������� ��������]" << endl;
    cout << "�������� ���������� �����: ";
    cin >> ROW_LENGTH; cout << endl;
    matrixChar = new unsigned char* [ROW_LENGTH]; // �� ������ ����������� ���

    // [Create random matrix]
    for(int i = 0; i < ROW_LENGTH; i++){
        matrixChar[i] = new unsigned char[STRING_LENGTH];
    }
    for(int i = 0; i < ROW_LENGTH; i++){
        for(int j = 0; j < STRING_LENGTH; j++){
            matrixChar[i][j] = letters[rand() % ARRAY_SIZE(letters) - 2];
        }
    }
}

void RFID::consoleOutputHexMatrix() {
    // [HEX format console output]
    for(int i = 0; i < ROW_LENGTH; i++){
        for(int j = 0; j < STRING_LENGTH; j++){
            cout << matrixChar[i][j];
        }
        for(int j = 0; j < STRING_LENGTH; j++){
            cout << " " << hex << matrixChar[i][j];
        }
        cout << endl<< "HEX" << endl;
        for (int j = 0; j < STRING_LENGTH; j++) {
            cout << " " << hex << (unsigned int)matrixChar[i][j];
        }
        cout << endl;
    }
}

void RFID::fileOutputHexMatrix() {
    // [HEX format file output]
    ofstream outFile(FILE_NAME);
    for(int i = 0; i < ROW_LENGTH; i++){
        for(int j = 0; j < STRING_LENGTH; j++){
            outFile << matrixChar[i][j];
        }
        for(int j = 0; j < STRING_LENGTH; j++){
            outFile << " " << hex << matrixChar[i][j];
        }
        
        outFile << endl;
    }
    outFile.close();
}
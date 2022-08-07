#pragma once

/*
 Name:		AdhanDisplay.h
 Created:	08/05/2022 07:05:15 AM
 Author:	Murat


*/
#define SSPI_CS1      21
#define SSPI_CS2      22
#define SSPI_CLK      26
#define SSPI_DO       25

#define WR_CMD        0x80
#define NumbAdr       0x07   
#define Turk          1
#define Arab          2
#define Eng           3  

//                                 t                      o                                        F                      a                       j                  r
const uint8_t Fajr[35] = {   0, 16,124, 18,  0,   12, 18, 18, 18, 12,   0,  0,  0,  0,  0,  126,  80,  80,  80, 64,  12, 18, 18, 18, 30,    0, 17, 94, 16,  0,  30, 8,  16, 16, 8 };
//                                 t                      o                                        D                      h                       u                  r
const uint8_t Dhur[35] = {   0, 16,124, 18,  0,   12, 18, 18, 18, 12,   0,  0,  0,  0,  0,  126,  66,  66, 102, 60, 126, 16, 16, 16, 14,   28,  2,  2,  2, 30,  30, 8,  16, 16, 8 };
//                                 t                      o                                        A                      s                       r
const uint8_t Asr[35] = {    0, 16,124, 18,  0,   12, 18, 18, 18, 12,   0,  0,  0,  0,  0,   62, 104,  72, 104, 62,  16, 42, 42, 42,  4,   62, 16, 32, 32, 16,   0,  0,  0,  0, 0 };
//                                 M                      a                     g                  h                      r                       i                  b
const uint8_t Maghrib[35]={126, 48, 24, 48,126,   12, 18, 18, 18, 30,  12, 21, 21, 21, 30,  126,   8,  16,  16, 14,  30,  8, 16, 16,  8,    0, 18, 94, 18,  0, 126, 10, 18, 18,12 };
//                                 t                      o                                        I                      s                       h                  a
const uint8_t Isha[35] = {   0, 16,124, 18,  0,   12, 18, 18, 18, 12,   0,  0,  0,  0,  0,    0,  66, 126,  66,  0,  16, 42, 42, 42,  4,   28,  2,  2,  2, 30,  12, 18, 18, 18,30 };
//                                                        S                     a                  b                      a                       h                  
const uint8_t Sabah[35] = {  0,  0,  0,  0,  0,   34, 82, 82, 82, 12,  12, 18, 18, 18, 30,  126,  10,  18,  18, 12,  12, 18, 18, 18, 30,  126, 16, 16, 16, 14,   0,  0,  0,  0, 0 };
//                                                        ö                     ğ                  l                      e                       n                                         
const uint8_t Oglen[35] = {  0,  0,  0,  0,  0,   92, 34, 34, 34, 92,  12, 85, 85, 85, 30,    0,   0, 124,   2,  0,  28, 42, 42, 42, 16,   30, 16, 16, 16, 14,   0,  0,  0,  0, 0 };
//                                 i                      k                     i                  n                      d                       i                  
const uint8_t Ikindi[35] = { 0, 18, 94, 18,  0,  126,  8, 20, 18,  0,   0, 18, 94, 18,  0,   30,  16,  16,  16, 14,  12, 18, 18, 18,126,    0, 18, 94, 18,  0,   0,  0,  0,  0, 0 };
//                                                        A                     k                  ş                      a                       m                                             j                  r
const uint8_t Aksam[35] = {  0,  0,  0,  0,  0,   62,104, 72,104, 62, 126,  8, 20, 18,  0,   16,  42,  43,  42,  4,  12, 18, 18, 18, 30,   30, 16, 14, 16, 14,   0,  0,  0,  0, 0 };
//                                                        Y                     a                  t                      s                       ı                  
const uint8_t Yatsi[35] = {  0,  0,  0,  0,  0,   64, 48, 14, 48, 64,  12, 18, 18, 18, 30,    0,  16,  60,  18,  0,  24, 42, 42, 42,  4,    0, 18, 30, 18,  0,   0,  0,  0,  0, 0 };
//                                 V                      o                     l                  
const uint8_t Vol[35] = {  112, 12,  3, 12, 112,   62, 99, 65, 99, 62, 127,  1,  1,  1,  1,   0,   0,   0,   0,  0,   0,  0,  0,  0,  0,    0,  0,  0,  0,  0,   0,  0,  0,  0, 0 };
//                                 S                      a                     l                  a                      m                        
const uint8_t Slm[35] = {    34, 82, 82, 82,  12,   12, 18, 18, 18, 30,   0,  0,124,  2,  0,   12, 18,  18,  18, 30,   30, 16, 14, 16, 14,   0,  0,  0,  0,  0,   0,  0,  0,  0, 0 };
//                                 M                      a                     s                  a                     l                       a                  m
const uint8_t Mslm[35] = { 126, 48, 24, 48, 126,   12, 18, 18, 18, 30,  16, 42, 42, 42,  4,   12, 18,  18,  18, 30,   0,  0, 124,  2,  0,  12, 18, 18, 18, 30,  30, 16, 14, 16, 14};



//                             0                     1                    2                   3                 4
//                             5                     6                    7                   8                 9     
uint8_t NumTxt[50] = { 62, 99, 65, 99, 62,   0, 33, 127, 1, 0,  35, 69, 73, 81, 33,  34, 65, 73, 105, 54,  24, 40, 72, 31,  8,
                      114, 73, 73, 73, 78,  62,105, 73, 73, 6,  64, 71, 72, 80, 96,  54, 73, 73,  73, 54,  48, 73, 73, 74, 60 };

//                  0  1  2  3  4   5   6  7  8   9  -  :
uint8_t Numb[] = { 63,6,91,79,102,109,124,7,127,103,63,54 };

uint8_t ayar;

struct Salat
{
public:
    uint8_t a_Fajr[35];
    uint8_t a_Dhur[35];
    uint8_t a_Asr[35];
    uint8_t a_Maghrib[35];
    uint8_t a_Isha[35];
};


void MySPI_SendData(uint8_t data) {
    uint8_t mveri;
    mveri = data;
    digitalWrite(SSPI_CLK, HIGH);
    digitalWrite(SSPI_DO, HIGH);
    for (uint8_t j = 0;j < 8;j++) {
        digitalWrite(SSPI_CLK, LOW);
        if ((mveri & 0x01) == 0) {      // MSB first
            digitalWrite(SSPI_DO, LOW);
        }
        else {
            digitalWrite(SSPI_DO, HIGH);
        }
        digitalWrite(SSPI_CLK, HIGH);
        mveri = mveri >> 1;
    }
    delayMicroseconds(3);
}

void MySPI_SendByte(uint8_t dat) {
    uint8_t veri;
    veri = dat;
    digitalWrite(SSPI_CLK, HIGH);
    digitalWrite(SSPI_DO, HIGH);
    for (uint8_t j = 0;j < 8;j++) {
        digitalWrite(SSPI_CLK, LOW);
        if ((veri & 0x80) == 0) {      // MSB first
            digitalWrite(SSPI_DO, LOW);
        }
        else {
            digitalWrite(SSPI_DO, HIGH);
        }
        digitalWrite(SSPI_CLK, HIGH);
        veri = veri << 1;
    }
    delayMicroseconds(3);
}

void SendComm(uint8_t Command, uint8_t argument) {
    digitalWrite(SSPI_CS1, HIGH);
    digitalWrite(SSPI_CS2, HIGH);
    digitalWrite(SSPI_CS1, LOW);  // select first chip
    delayMicroseconds(2);
    MySPI_SendByte(Command);
    MySPI_SendByte(argument);
    digitalWrite(SSPI_CS1, HIGH);
    digitalWrite(SSPI_CS2, LOW);  // select second chip
    delayMicroseconds(2);
    MySPI_SendByte(Command);
    MySPI_SendByte(argument);
    digitalWrite(SSPI_CS2, HIGH);
    digitalWrite(SSPI_CS1, HIGH);
}

void ClrTxtDisp() {
    digitalWrite(SSPI_CS1, HIGH);
    digitalWrite(SSPI_CS2, HIGH);
    digitalWrite(SSPI_CS1, LOW);  // select first chip
    MySPI_SendByte(WR_CMD);          // Write RAM command
    MySPI_SendByte(0x00);          // first adress
    for (uint8_t r = 0;r < 28;r++) {
        // first 28 rows on first chip
        MySPI_SendData(0);
    }
    digitalWrite(SSPI_CS1, HIGH);
    digitalWrite(SSPI_CS2, LOW);  // select second chip
    MySPI_SendByte(WR_CMD);          // Write RAM command
    MySPI_SendByte(0x00);          // first adress
    for (uint8_t r = 0;r < 7;r++) {
        // last 7 rows on second chip
        MySPI_SendData(0);
    }
    digitalWrite(SSPI_CS2, HIGH);
    digitalWrite(SSPI_CS1, HIGH);
}

void DispSetup() {

    //  turn com lines on 
    SendComm(0x41, 0x7F);        // com lines 0-6 is used  
    //  turn row pins on 
    digitalWrite(SSPI_CS1, HIGH);
    digitalWrite(SSPI_CS2, HIGH);
    digitalWrite(SSPI_CS1, LOW);  // select first chip
    MySPI_SendByte(0x42);         // turn on row pins  
    MySPI_SendByte(0xFF);         // row 27-20 on
    MySPI_SendByte(0xFF);         // row 12-19 on 
    MySPI_SendByte(0xFF);         // row 4-11 on
    MySPI_SendByte(0x0F);         // row 3-0 on
    digitalWrite(SSPI_CS1, HIGH);
    digitalWrite(SSPI_CS2, LOW);  // select second chip
    MySPI_SendByte(0x42);         // turn on row pins  
    MySPI_SendByte(0x00);         // row 27-20 off
    MySPI_SendByte(0x01);         // row 12 on 13-19 oFF 
    MySPI_SendByte(0xFF);         // row 4-11 on
    MySPI_SendByte(0x0F);         // row 3-0 on
    digitalWrite(SSPI_CS2, HIGH);
    digitalWrite(SSPI_CS1, HIGH);
    // binary gray mode select 
    SendComm(0x31, 0x01);         // Bin/Gray select, 0=gray 1=binary
    //  select com outputs  
    SendComm(0x32, 0x06);         // select com lines to use, first 6 lines, high scan (led+ on com)
    // Set constant current ratio

    // set global brigtness 
    SendComm(0x37, 0x10);          // *** set brightnes
    // Cascade mode and oscillator select  
    SendComm(0x34, 0x00);          // Cascade mode osc=IRC osc active, sync pin active
    //  oscillator enable
    SendComm(0x35, 0x03);          // oscillator On/off normal display mode
}

void DispText(uint8_t vakit, uint8_t lang) {
    Salat mysalat;
    uint8_t mytxt[35];
    uint8_t row = 0;
    if (lang == Turk) {
        for (uint8_t o = 0;o < 35;o++) {
            mysalat.a_Fajr[o] = Sabah[o];
            mysalat.a_Dhur[o] = Oglen[o];
            mysalat.a_Asr[o] = Ikindi[o];
            mysalat.a_Maghrib[o] = Aksam[o];
            mysalat.a_Isha[o] = Yatsi[o];
        }
    }
    else if (lang == Arab) {
        for (uint8_t o = 0;o < 35;o++) {
            mysalat.a_Fajr[o] = Fajr[o];
            mysalat.a_Dhur[o] = Dhur[o];
            mysalat.a_Asr[o] = Asr[o];
            mysalat.a_Maghrib[o] = Maghrib[o];
            mysalat.a_Isha[o] = Isha[o];
        }
    }
    else {              // just in case for other languages
        for (uint8_t o = 0;o < 35;o++) {
            mysalat.a_Fajr[o] = Fajr[o];
            mysalat.a_Dhur[o] = Dhur[o];
            mysalat.a_Asr[o] = Asr[o];
            mysalat.a_Maghrib[o] = Maghrib[o];
            mysalat.a_Isha[o] = Isha[o];
        }
    }
    switch (vakit) {
    case 0:
        for (uint8_t o = 0;o < 35;o++) {
            mytxt[o] = Slm[o];
        }
        //if (ayar > 9) {
        //    row = ayar / 10;
        //    for (uint8_t p = 0;p < 5;p++) {
        //        mytxt[20 + p] = NumTxt[row * 5 + p];
        //    }

        //}
        //row = ayar % 10;
        //for (uint8_t p = 0;p < 5;p++) {
        //    mytxt[25 + p] = NumTxt[row * 5 + p];
        //}

        break;
    case 1:
        for (uint8_t o = 0;o < 35;o++) {
            mytxt[o] = mysalat.a_Fajr[o];
        }
        break;
    case 2:
        for (uint8_t o = 0;o < 35;o++) {
            mytxt[o] = mysalat.a_Dhur[o];
        }
        break;
    case 3:
        for (uint8_t o = 0;o < 35;o++) {
            mytxt[o] = mysalat.a_Asr[o];
        }
        break;
    case 4:
        for (uint8_t o = 0;o < 35;o++) {
            mytxt[o] = mysalat.a_Maghrib[o];
        }
        break;
    case 5:
        for (uint8_t o = 0;o < 35;o++) {
            mytxt[o] = mysalat.a_Isha[o];
        }
        break;
    case 6:
        for (uint8_t o = 0;o < 35;o++) {
            mytxt[o] = Mslm[o];
        }
        break;
    }

    digitalWrite(SSPI_CS1, HIGH);
    digitalWrite(SSPI_CS2, HIGH);
    digitalWrite(SSPI_CS1, LOW);  // select first chip
    MySPI_SendByte(WR_CMD);        // Write RAM command
    MySPI_SendByte(0x00);          // first adress
    for (uint8_t r = 0;r < 28;r++) {
        row = mytxt[r];           // first 28 rows on first chip
        MySPI_SendData(row);
    }
    digitalWrite(SSPI_CS1, HIGH);
    digitalWrite(SSPI_CS2, LOW);  // select second chip
    MySPI_SendByte(WR_CMD);          // Write RAM command
    MySPI_SendByte(0x00);          // first adress
    for (uint8_t r = 0;r < 7;r++) {
        row = mytxt[r + 28];        // last 7 rows on second chip
        MySPI_SendData(row);
    }
    digitalWrite(SSPI_CS2, HIGH);
    digitalWrite(SSPI_CS1, HIGH);
}

void dispVol(uint8_t ses) {
    uint8_t amytxt[35];
    uint8_t arow = 0;
    if (ses<21) {
        for (uint8_t o = 0;o < 35;o++) {
            amytxt[o] = Vol[o];
        }
        if (ayar > 9) {
            arow = ses / 10;
            for (uint8_t p = 0;p < 5;p++) {
                amytxt[20 + p] = NumTxt[arow * 5 + p];
            }

        }
        arow = ses % 10;
        for (uint8_t p = 0;p < 5;p++) {
            amytxt[25 + p] = NumTxt[arow * 5 + p];
        }
    }
    digitalWrite(SSPI_CS1, HIGH);
    digitalWrite(SSPI_CS2, HIGH);
    digitalWrite(SSPI_CS1, LOW);  // select first chip
    MySPI_SendByte(WR_CMD);        // Write RAM command
    MySPI_SendByte(0x00);          // first adress
    for (uint8_t r = 0;r < 28;r++) {
        arow = amytxt[r];           // first 28 rows on first chip
        MySPI_SendData(arow);
    }
    digitalWrite(SSPI_CS1, HIGH);
    digitalWrite(SSPI_CS2, LOW);  // select second chip
    MySPI_SendByte(WR_CMD);          // Write RAM command
    MySPI_SendByte(0x00);          // first adress
    for (uint8_t r = 0;r < 7;r++) {
        arow = amytxt[r + 28];        // last 7 rows on second chip
        MySPI_SendData(arow);
    }
    digitalWrite(SSPI_CS2, HIGH);
    digitalWrite(SSPI_CS1, HIGH);
}

void DispClock(uint8_t minus, int8_t saat, uint8_t dakika, uint8_t colon) {
    uint8_t saatim[7];
    uint8_t onlar, birler, rw;
    if (minus == 1) { saatim[0] = 63; }
    else { saatim[0] = 0; }
    if (saat > 9) {
        onlar = saat / 10;
        saatim[1] = Numb[onlar];
        birler = saat - onlar * 10;
    }
    else {
        saatim[1] = 0;
        birler = saat;
    }
    saatim[2] = Numb[birler];
    if (dakika > 9) {
        onlar = dakika / 10;
        saatim[4] = Numb[onlar];
        birler = dakika - onlar * 10;
    }
    else {
        onlar = 0;
        saatim[4] = Numb[onlar];
        birler = dakika;
    }
    saatim[5] = Numb[birler];
    if (colon == 1) { saatim[3] = 54; }
    else { saatim[3] = 0; }
    digitalWrite(SSPI_CS2, HIGH);
    digitalWrite(SSPI_CS1, HIGH);
    digitalWrite(SSPI_CS2, LOW);
    MySPI_SendByte(WR_CMD);          // Write RAM command
    MySPI_SendByte(7);         // first adress is 7 for clock
    for (uint8_t r = 0;r < 7;r++) {
        rw = saatim[r];        // last 6 rows on second chip
        MySPI_SendData(rw);
    }
    digitalWrite(SSPI_CS2, HIGH);
    digitalWrite(SSPI_CS1, HIGH);
}

void SetBrightness(uint8_t brightness) {
    if (brightness < 64) {                // brigtnes is 0-63 (0x00 to 0x40) max 63  
        SendComm(0x37, brightness);       // *** set brightnes 
    }
}









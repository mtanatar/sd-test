/*
 Name:		sd_test.ino
 Created:	6/20/2022 11:21:18 PM
 Author:	Murat
*/

/*
 Name:		player_sd_a2dp_test.ino
 Created:	16-Jun-22 23:59:13
 Author:	Emre TURAL
*/

#include "Arduino.h"
#include "WiFi.h"
#include "Audio.h"
#include "SD.h"
#include "FS.h"
#include "OneWireLed.h"
#include "AdhanDisplay.h"

uint8_t saa = 02;
uint8_t dak = 48;
uint8_t san = 24;


// Digital I/O used
#define xSD_CS          5
#define xSPI_MOSI      23
#define xSPI_MISO      19
#define xSPI_SCK       18

#define I2S_DOUT      27
#define I2S_BCLK      15
#define I2S_LRC       32
#define OWLED         33  
#define MUTE          14


#define RTC_SDA       13   
#define RTC_SCK       12
#define RTC_ADDRESS   0x68
#define SQW           35 


Audio audio;

String ssid = "Tura";
String password = "1020304050";




void dispShow() {
  
    // ClearClk();
    byte saniye, dakika, saat, mynum, mon;

    san++;
    if (san == 60) {
        dak++;
        if (dak == 60) {
            saa++;
        }
    }
    saniye = san;
    dakika = dak;
    saat = saa;
    ayar = 9;
    Serial.print("Saat : ");
    Serial.print(saat); Serial.print(":");
    Serial.print(dakika); Serial.print(":");
    Serial.println(saniye);
    mynum = san % 5;
    mon = mynum % 2;
    ClrTxtDisp();
    // test leds
    if (mynum == 0) { ayar+= san % 10; }
    DispText(mynum, 1);
    DispClock(0, saat, saniye, mon);

    
}

void LedShow() {
    uint8_t g1 = 1;
    uint8_t g2 = 1;
    uint8_t g3 = 1;
    DispSetup();
    dispShow();
    Serial.println("*** Circle Doger Blue ****");
    for(uint8_t g=0;g<10;g++){
       for (uint8_t n = 1; n < 9; n++) {
          CircleColor(30, 144, 255, n);
          delay(150);
       }
    }
    dispShow();
    Serial.println("*** Doger Blue ****");
    SendRGB(30, 144, 255);
    delay(5000);
    dispShow();
    Serial.println("******* Circle Gold ******");
    for (uint8_t v=0; v<10; v++)
    {
        for (uint8_t n = 1; n < 9; n++) {
            CircleColor(200, 120, 0, n);
            delay(150);
        }
    }
    dispShow();
    Serial.println("********** Gold **********");
    SendRGB(200, 120, 0);
    delay(5000);
    dispShow();
    Serial.println("*** Dimmed Light Cyan ****");
    SendRGB(76, 85, 85);
    delay(5000);
    dispShow();
    Serial.println("**** Dimmed Gold  ********");
    SendRGB(118, 107, 10);
    delay(5000);
    dispShow();
    Serial.println("* Blink Orange Red 5 times **");
    for (uint8_t n = 1; n < 6; n++) {
        SendRGB(255, 69, 0);
        delay(1000);
        dispShow();
        SendRGB(0, 0, 0);
        delay(1000);
        dispShow();
    }
    dispShow();
    Serial.println("***** Orange Red *********");
    SendRGB(255, 69, 0);
    delay(5000);
    dispShow();
}



//TaskHandle_t taskAnimation;

void setup() {
    
    pinMode(RTC_SCK, OUTPUT);
    pinMode(RTC_SDA, OUTPUT);
    pinMode(SQW, INPUT);
    
    pinMode(MUTE, OUTPUT);      digitalWrite(MUTE, LOW);
   
    pinMode(xSD_CS, OUTPUT);    digitalWrite(xSD_CS, HIGH); 
    
    pinMode(OWLED, OUTPUT);    // digitalWrite(OWLED, LOW);
     
    SPI.begin(xSPI_SCK, xSPI_MISO, xSPI_MOSI);
    Serial.begin(115200);
    SD.begin(xSD_CS);

    pinMode(SSPI_CLK, OUTPUT); digitalWrite(SSPI_CLK, HIGH);
    pinMode(SSPI_DO, OUTPUT); digitalWrite(SSPI_DO, HIGH);
    pinMode(SSPI_CS1, OUTPUT); digitalWrite(SSPI_CS1, HIGH);
    pinMode(SSPI_CS2, OUTPUT); digitalWrite(SSPI_CS2, HIGH);

    WiFi.disconnect();
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid.c_str(), password.c_str());
    
    while (WiFi.status() != WL_CONNECTED) {
        Serial.println("No Connection");
        delay(1500);
    }
    Serial.println("Connected To " + ssid);
    audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
    audio.setVolume(5); // 0...21

 //   audio.connecttoFS(SD, "/positiveNotification.mp3");
//    audio.connecttohost("http://37.1.145.21:9001/;stream.mp3");
//    audio.connecttohost("http://www.wdr.de/wdrlive/media/einslive.m3u");
//    audio.connecttohost("http://macslons-irish-pub-radio.com/media.asx");
    audio.connecttohost(" http://stream.radyoalaturka.com.tr:9100/");
//    audio.connecttohost("http://mp3.ffh.de/radioffh/hqlivestream.aac"); //  128k aac
//     audio.connecttohost("http://stream.radyoodtu.com.tr/rock");
//    audio.connecttohost("http://mp3.ffh.de/radioffh/hqlivestream.mp3"); //  128k mp3
//    audio.connecttohost("https://github.com/schreibfaul1/ESP32-audioI2S/raw/master/additional_info/Testfiles/sample1.m4a"); // m4a
//    audio.connecttohost("https://github.com/schreibfaul1/ESP32-audioI2S/raw/master/additional_info/Testfiles/test_16bit_stereo.wav"); // wav
//    audio.connecttospeech("Wenn die Hunde schlafen, kann der Wolf gut Schafe stehlen.", "de");

    
    

    LedShow();
    

    // handler, task name, stack depth, parameter, priority, task, core id
   // xTaskCreatePinnedToCore(taskAnimationHandler, "AnimationTask", 1024, NULL, 7, &taskAnimation, 1);
}

void taskAnimationHandler(void* parameter)
{
    // setup

    // loop
    while (true)
    {
        //do something
        LedShow();
        vTaskDelay(10000 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL); // taskAnimation

}


void loop()
{
 //   LedShow();
    
    audio.loop();
}

// optional
void audio_info(const char* info) {
    Serial.print("info        "); Serial.println(info);
}
void audio_id3data(const char* info) {  //id3 metadata
    Serial.print("id3data     ");Serial.println(info);
}
void audio_eof_mp3(const char* info) {  //end of file
    Serial.print("eof_mp3     ");Serial.println(info);
}
void audio_showstation(const char* info) {
    Serial.print("station     ");Serial.println(info);
}
void audio_showstreamtitle(const char* info) {
    Serial.print("streamtitle ");Serial.println(info);
}
void audio_bitrate(const char* info) {
    Serial.print("bitrate     ");Serial.println(info);
}
void audio_commercial(const char* info) {  //duration in sec
    Serial.print("commercial  ");Serial.println(info);
}
void audio_icyurl(const char* info) {  //homepage
    Serial.print("icyurl      ");Serial.println(info);
}
void audio_lasthost(const char* info) {  //stream URL played
    Serial.print("lasthost    ");Serial.println(info);
}
void audio_eof_speech(const char* info) {
    Serial.print("eof_speech  ");Serial.println(info);
}





//
//
///*
//  ESP32 SD I2S Music Player
//  esp32-i2s-sd-player.ino
//  Plays MP3 file from microSD card
//  Uses MAX98357 I2S Amplifier Module
//  Uses ESP32-audioI2S Library - https://github.com/schreibfaul1/ESP32-audioI2S
//  *
//  DroneBot Workshop 2022
//  https://dronebotworkshop.com
//*/
//
//// Include required libraries
//#include "Arduino.h"
//#include "Audio.h"
//#include "SD.h"
//#include "FS.h"
//
//// microSD Card Reader connections
//#define PIN_AUDIO_KIT_SD_CARD_CS 5
//#define PIN_AUDIO_KIT_SD_CARD_MISO 23
//#define PIN_AUDIO_KIT_SD_CARD_MOSI 19
//#define PIN_AUDIO_KIT_SD_CARD_CLK  18
//
//#define SD_CS          5
//#define SPI_MOSI      23 
//#define SPI_MISO      19
//#define SPI_SCK       18
//
//// I2S Connections
//#define I2S_DOUT      27
//#define I2S_BCLK      15
//#define I2S_LRC       32
//
///*
//// I2S Connections
//#define I2S_DOUT      22
//#define I2S_BCLK      26
//#define I2S_LRC       25
//*/
//
///*
//// I2S Connections
//#define I2S_DOUT      27
//#define I2S_BCLK      15
//#define I2S_LRC       32
//*/
//
///*
//    i2s_pin_config_t my_pin_config;
//    my_pin_config.bck_io_num = 15; //15
//    my_pin_config.ws_io_num = 32; // 16
//    my_pin_config.data_out_num = 27; //17
//    my_pin_config.data_in_num = I2S_PIN_NO_CHANGE;
//*/
//
//// Create Audio object
//Audio audio;
//
//void setup() {
//
//    // Set microSD Card CS as OUTPUT and set HIGH
//    pinMode(SD_CS, OUTPUT);
//    digitalWrite(SD_CS, HIGH);
//
//    // Initialize SPI bus for microSD Card
//    SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI, SD_CS);
//
//    // Start Serial Port
//    Serial.begin(115200);
//    while (Serial.available()) {}
//
//    // Start microSD Card
//    if (!SD.begin(SD_CS))
//    {
//        Serial.println("Error accessing microSD card!");
//        while (true);
//    }
//
//    // Setup I2S 
//    audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
//
//    // Set Volume
//    audio.setVolume(100);
//
//    // Open music file
//    audio.connecttoFS(SD, "/positiveNotification.mp3");
//    //beep.mp3
//    //negativeNotification.wav
//    //positiveNotification.mp3
//    //successNotification.wav
//    audio.setVolume(100);
//}
//
//void loop()
//{
//    audio.loop();
//}
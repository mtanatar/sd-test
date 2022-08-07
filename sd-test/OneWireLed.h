#pragma once
/*
 Name:		OneWireLed.h
 Created:	08/01/2022 01:42:18 AM
 Author:	Murat


*/




void NOP600() {
    asm("nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;"
        "nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;"
        "nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;"
        "nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;"
        "nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;"
        "nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;");
}

void NOP300() {
    asm("nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;"
        "nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;"
        "nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;");
}

void SendOneLed(uint8_t rd, uint8_t gr, uint8_t bl) {
    uint8_t kiz;
    uint8_t yes;
    uint8_t mav;
    yes = gr;
    for (uint8_t t = 0; t < 8; t++) {
        if ((yes & 0x80) == 0) {
            GPIO.out1_w1ts.val = 2;  // gpio_set_level(GPIO_NUM_33, 1); // 
            NOP300();
            GPIO.out1_w1tc.val = 2;  //   gpio_set_level(GPIO_NUM_33, 0);
            NOP600(); NOP300();
        }
        else {
            GPIO.out1_w1ts.val = 2;  //  gpio_set_level(GPIO_NUM_33, 1);
            NOP600();
            GPIO.out1_w1tc.val = 2;  //   gpio_set_level(GPIO_NUM_33, 0);
            NOP600();
        }
        yes = yes << 1;
    }
    kiz = rd;
    for (uint8_t t1 = 0; t1 < 8; t1++) {
        if ((kiz & 0x80) == 0) {
            GPIO.out1_w1ts.val = 2;  //  gpio_set_level(GPIO_NUM_33, 1);
            NOP300();                //  asm("nop; nop; nop");
            GPIO.out1_w1tc.val = 2;  //   gpio_set_level(GPIO_NUM_33, 0);
            NOP600(); NOP300();
        }
        else {
            GPIO.out1_w1ts.val = 2;  //  gpio_set_level(GPIO_NUM_33, 1);
            NOP600();
            GPIO.out1_w1tc.val = 2;  // gpio_set_level(GPIO_NUM_33, 0);
            NOP600();
        }
        kiz = kiz << 1;
    }
    mav = bl;
    for (uint8_t t2 = 0; t2 < 8; t2++) {
        if ((mav & 0x80) == 0) {
            GPIO.out1_w1ts.val = 2;  //  gpio_set_level(GPIO_NUM_33, 1);
            NOP300();                //  asm("nop; nop; nop");
            GPIO.out1_w1tc.val = 2;  //  gpio_set_level(GPIO_NUM_33, 0);
            NOP600(); NOP300();
        }
        else {
            GPIO.out1_w1ts.val = 2;  //  gpio_set_level(GPIO_NUM_33, 1);
            NOP600();
            GPIO.out1_w1tc.val = 2;  //  gpio_set_level(GPIO_NUM_33, 0);
            NOP600();
        }
        mav = mav << 1;
    }
    GPIO.out1_w1tc.val = 2;
}

void CircleColor(uint8_t R, uint8_t G, uint8_t B, uint8_t plc) {
    uint8_t pl = 0;
    uint8_t kirm, yesil, mavi;
    uint8_t lkirm, lyesil, lmavi;
    uint8_t mavi_1, mavi_2, mavi_3, mavi_4, mavi_5, mavi_6, mavi_7, mavi_8;
    uint8_t kirm_1, kirm_2, kirm_3, kirm_4, kirm_5, kirm_6, kirm_7, kirm_8;
    uint8_t yesil_1, yesil_2, yesil_3, yesil_4, yesil_5, yesil_6, yesil_7, yesil_8;
    pl = plc;
    yesil = G;
    lyesil = yesil / 3;
    kirm = R;
    lkirm = kirm / 3;
    mavi = B;
    lmavi = mavi / 3;

    if (pl == 1) {
        mavi_1 = mavi; mavi_2 = lmavi; mavi_3 = 0; mavi_4 = 0; mavi_5 = 0; mavi_6 = 0; mavi_7 = 0; mavi_8 = lmavi;
        kirm_1 = kirm; kirm_2 = lkirm; kirm_3 = 0; kirm_4 = 0; kirm_5 = 0; kirm_6 = 0; kirm_7 = 0; kirm_8 = lkirm;
        yesil_1 = yesil; yesil_2 = lyesil; yesil_3 = 0; yesil_4 = 0; yesil_5 = 0; yesil_6 = 0; yesil_7 = 0; yesil_8 = lyesil;
    }
    if (pl == 2) {
        mavi_1 = lmavi; mavi_2 = mavi; mavi_3 = lmavi; mavi_4 = 0; mavi_5 = 0; mavi_6 = 0; mavi_7 = 0; mavi_8 = 0;
        kirm_1 = lkirm; kirm_2 = kirm; kirm_3 = lkirm; kirm_4 = 0; kirm_5 = 0; kirm_6 = 0; kirm_7 = 0; kirm_8 = 0;
        yesil_1 = lyesil; yesil_2 = yesil; yesil_3 = lyesil; yesil_4 = 0; yesil_5 = 0; yesil_6 = 0; yesil_7 = 0; yesil_8 = 0;
    }
    if (pl == 3) {
        mavi_1 = 0; mavi_2 = lmavi; mavi_3 = mavi; mavi_4 = lmavi; mavi_5 = 0; mavi_6 = 0; mavi_7 = 0; mavi_8 = 0;
        kirm_1 = 0; kirm_2 = lkirm; kirm_3 = kirm; kirm_4 = lkirm; kirm_5 = 0; kirm_6 = 0; kirm_7 = 0; kirm_8 = 0;
        yesil_1 = 0; yesil_2 = lyesil; yesil_3 = yesil; yesil_4 = lyesil; yesil_5 = 0; yesil_6 = 0; yesil_7 = 0; yesil_8 = 0;
    }
    if (pl == 4) {
        mavi_1 = 0; mavi_2 = 0; mavi_3 = lmavi; mavi_4 = mavi; mavi_5 = lmavi; mavi_6 = 0; mavi_7 = 0; mavi_8 = 0;
        kirm_1 = 0; kirm_2 = 0; kirm_3 = lkirm; kirm_4 = kirm; kirm_5 = lkirm; kirm_6 = 0; kirm_7 = 0; kirm_8 = 0;
        yesil_1 = 0; yesil_2 = 0; yesil_3 = lyesil; yesil_4 = yesil; yesil_5 = lyesil; yesil_6 = 0; yesil_7 = 0; yesil_8 = 0;
    }
    if (pl == 5) {
        mavi_1 = 0; mavi_2 = 0; mavi_3 = 0; mavi_4 = lmavi; mavi_5 = mavi; mavi_6 = lmavi; mavi_7 = 0; mavi_8 = 0;
        kirm_1 = 0; kirm_2 = 0; kirm_3 = 0; kirm_4 = lkirm; kirm_5 = kirm; kirm_6 = lkirm; kirm_7 = 0; kirm_8 = 0;
        yesil_1 = 0; yesil_2 = 0; yesil_3 = 0; yesil_4 = lyesil; yesil_5 = yesil; yesil_6 = lyesil; yesil_7 = 0; yesil_8 = 0;
    }
    if (pl == 6) {
        mavi_1 = 0; mavi_2 = 0; mavi_3 = 0; mavi_4 = 0; mavi_5 = lmavi; mavi_6 = mavi; mavi_7 = lmavi; mavi_8 = 0;
        kirm_1 = 0; kirm_2 = 0; kirm_3 = 0; kirm_4 = 0; kirm_5 = lkirm; kirm_6 = kirm; kirm_7 = lkirm; kirm_8 = 0;
        yesil_1 = 0; yesil_2 = 0; yesil_3 = 0; yesil_4 = 0; yesil_5 = lyesil; yesil_6 = yesil; yesil_7 = lyesil; yesil_8 = 0;
    }
    if (pl == 7) {
        mavi_1 = 0; mavi_2 = 0; mavi_3 = 0; mavi_4 = 0; mavi_5 = 0; mavi_6 = lmavi; mavi_7 = mavi; mavi_8 = lmavi;
        kirm_1 = 0; kirm_2 = 0; kirm_3 = 0; kirm_4 = 0; kirm_5 = 0; kirm_6 = lkirm; kirm_7 = kirm; kirm_8 = lkirm;
        yesil_1 = 0; yesil_2 = 0; yesil_3 = 0; yesil_4 = 0; yesil_5 = 0; yesil_6 = lyesil; yesil_7 = yesil; yesil_8 = lyesil;
    }
    if (pl == 8) {
        mavi_1 = lmavi; mavi_2 = 0; mavi_3 = 0; mavi_4 = 0; mavi_5 = 0; mavi_6 = 0; mavi_7 = lmavi; mavi_8 = mavi;
        kirm_1 = lkirm; kirm_2 = 0; kirm_3 = 0; kirm_4 = 0; kirm_5 = 0; kirm_6 = 0; kirm_7 = lkirm; kirm_8 = kirm;
        yesil_1 = lyesil; yesil_2 = 0; yesil_3 = 0; yesil_4 = 0; yesil_5 = 0; yesil_6 = 0; yesil_7 = lyesil; yesil_8 = yesil;
    }

    for (uint8_t l = 0; l < 8; l++) {
        SendOneLed(kirm_1, yesil_1, mavi_1);
        SendOneLed(kirm_2, yesil_2, mavi_2);
        SendOneLed(kirm_3, yesil_3, mavi_3);
        SendOneLed(kirm_4, yesil_4, mavi_4);
        SendOneLed(kirm_5, yesil_5, mavi_5);
        SendOneLed(kirm_6, yesil_6, mavi_6);
        SendOneLed(kirm_7, yesil_7, mavi_7);
        SendOneLed(kirm_8, yesil_8, mavi_8);
    }
}


void SendRGB(uint8_t Red, uint8_t Green, uint8_t Blue) {
    uint8_t kizil;
    uint8_t yesil;
    uint8_t mavi;

    for (uint8_t led = 0; led < 8; led++) {
        yesil = Green;
        for (uint8_t bt = 0; bt < 8; bt++) {
            if ((yesil & 0x80) == 0) {
                GPIO.out1_w1ts.val = 2;  // gpio_set_level(GPIO_NUM_33, 1); // 
                NOP300();
                GPIO.out1_w1tc.val = 2;  //   gpio_set_level(GPIO_NUM_33, 0);
                NOP600();
                NOP300();
            }
            else {
                GPIO.out1_w1ts.val = 2;  //  gpio_set_level(GPIO_NUM_33, 1);
                NOP600();
                GPIO.out1_w1tc.val = 2;  //   gpio_set_level(GPIO_NUM_33, 0);
                NOP600();
            }
            yesil = yesil << 1;
        }
        kizil = Red;
        for (uint8_t bt1 = 0; bt1 < 8; bt1++) {
            if ((kizil & 0x80) == 0) {
                GPIO.out1_w1ts.val = 2;  //  gpio_set_level(GPIO_NUM_33, 1);
                NOP300();                //  asm("nop; nop; nop");
                GPIO.out1_w1tc.val = 2;  //   gpio_set_level(GPIO_NUM_33, 0);
                NOP600();
                NOP300();
            }
            else {
                GPIO.out1_w1ts.val = 2;  //  gpio_set_level(GPIO_NUM_33, 1);
                NOP600();
                GPIO.out1_w1tc.val = 2;  // gpio_set_level(GPIO_NUM_33, 0);
                NOP600();
            }
            kizil = kizil << 1;
        }
        mavi = Blue;
        for (uint8_t bt2 = 0; bt2 < 8; bt2++) {
            if ((mavi & 0x80) == 0) {
                GPIO.out1_w1ts.val = 2;  //  gpio_set_level(GPIO_NUM_33, 1);
                NOP300();                //  asm("nop; nop; nop");
                GPIO.out1_w1tc.val = 2;  //  gpio_set_level(GPIO_NUM_33, 0);
                NOP600();
                NOP300();
            }
            else {
                GPIO.out1_w1ts.val = 2;  //  gpio_set_level(GPIO_NUM_33, 1);
                NOP600();
                GPIO.out1_w1tc.val = 2;  //  gpio_set_level(GPIO_NUM_33, 0);
                NOP600();
            }
            mavi = mavi << 1;
        }
        GPIO.out1_w1tc.val = 2;
    }
    delayMicroseconds(90);
}
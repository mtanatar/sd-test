#pragma once
/*
 * OnewireLED.h
 *
 *  Created on: July 26,2022
 *  Updated on: July 26,2022
 *      Author: Murat Tanatar
 */





public:
	void CircleColor(uint8_t R, uint8_t G, uint8_t B, uint8_t plc);
	void SendRGB(uint8_t Red, uint8_t Green, uint8_t Blue);

private:
	void NOP600();
	void NOP300();
	void SendOneLed(uint8_t rd, uint8_t gr, uint8_t bl);
};
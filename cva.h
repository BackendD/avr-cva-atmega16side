/*
 * cva.h
 *
 *  Created on: Feb 26, 2018
 *      Author: hasan
 */

#ifndef CVA_H_
#define CVA_H_

#include <stddef.h>
#include <stdint-gcc.h>
#include <avr/io.h>

class Modem {
public:
	Modem(uint32_t freq, uint8_t bufferSize);
	~Modem();
	void setFreq(uint32_t freq);
	void begin(void);
	static Modem* activeObject;
	void demodulate(void);
	void recv(void);
	uint16_t tcnt_bit_period;
	virtual uint8_t available();
	virtual uint8_t read();

private:
	uint32_t freq;
	uint32_t baudRate;
	uint32_t lowFreq;
	uint32_t highFreq;
	uint16_t _lastTCNT;
	uint16_t _lowCount;
	uint16_t _highCount;
	uint8_t rxBufSize;
	uint8_t* _recvBuffer;
	uint8_t _recvBufferHead;
	uint8_t _recvBufferTail;
	uint8_t _recvStat;
	uint8_t _recvBits;

	uint16_t low_freq_micros;
	uint16_t micros_per_timer_count;
	uint16_t tcnt_low_freq;
	uint16_t tcnt_low_th_h;
	uint16_t tcnt_low_th_l;
	uint16_t bit_period;
	uint16_t high_freq_micros;
	uint16_t tcnt_high_freq;
	uint16_t tcnt_high_th_h;
	uint16_t tcnt_high_th_l;
};

#endif /* CVA_H_ */

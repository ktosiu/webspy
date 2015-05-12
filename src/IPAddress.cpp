/*
 * IPAddress.cpp
 *
 *  Created on: May 5, 2015
 *      Author: Felipe Rodopoulos
 */

#include <cstring>
#include <cstdio>

#include "IPAddress.h"

using namespace std;

IPAddress::IPAddress() {
	// TODO Auto-generated constructor stub
}

IPAddress::IPAddress(string ip){
	char* tmp = (char*)ip.c_str();
	uint8_t octs[4];

	sscanf(tmp, "%d.%d.%d.%d", octs[0], octs[1], octs[2], octs[3]);

	this->ip = (octs[0] << 24) + (octs[1] << 12) + (octs[2] << 8) + octs[3];
}

IPAddress::IPAddress(uint32_t ip) : ip(ip){ }

IPAddress::~IPAddress() { }

IPAddress IPAddress::operator +(uint32_t a){
	IPAddress tmp;
	tmp.ip = ip + a;
	return tmp;
}

IPAddress IPAddress::operator ++(){
	this->ip++;
	IPAddress tmp = *this;
	return tmp;
}

string IPAddress::toString(){
	char tmp[16];
	sprintf(tmp, "%d.%d.%d.%d",
			int(((uint8_t*)&ip)[0]),
			int(((uint8_t*)&ip)[1]),
			int(((uint8_t*)&ip)[2]),
			int(((uint8_t*)&ip)[3])
	);
	return string(tmp);
}

/*
 * Sweeper.h
 *
 *  Created on: 10 de ago de 2015
 *      Author: rodopoulos
 */

#ifndef SRC_SWEEPER_H_
#define SRC_SWEEPER_H_

#include <vector>
#include <tins/tins.h>
#include <pthread.h>
#include "Globals.h"
#include "Host.h"

class Sweeper {

	static std::vector<Host> hosts;

	static void* sendProbes(void* args);
	static bool  replyHandle(Tins::PDU& reply);
	static bool  isNewHost(Tins::IPv4Address ip);
	static std::string baseIP(std::string);

public:
	Sweeper();
	virtual ~Sweeper();

	void  sweep();
	Host& selectHost();
};


#endif /* SRC_SWEEPER_H_ */

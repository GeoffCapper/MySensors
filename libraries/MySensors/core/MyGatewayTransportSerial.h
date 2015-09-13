/**
 * The MySensors Arduino library handles the wireless radio link and protocol
 * between your home built sensors/actuators and HA controller of choice.
 * The sensors forms a self healing radio network with optional repeaters. Each
 * repeater and gateway builds a routing tables in EEPROM which keeps track of the
 * network topology allowing messages to be routed to nodes.
 *
 * Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
 * Copyright (C) 2013-2015 Sensnology AB
 * Full contributor list: https://github.com/mysensors/Arduino/graphs/contributors
 *
 * Documentation: http://www.mysensors.org
 * Support Forum: http://forum.mysensors.org
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 */

#ifndef MyGatewayTransportSerial_h
#define MyGatewayTransportSerial_h

#include "MyMessage.h"
#include "MyProtocol.h"
#include "MyProtocolDefault.h"

#define MAX_RECEIVE_LENGTH 100 // Maximum message length for messages coming from controller

class MyGatewayTransportSerial : public MyGatewayTransport
{
public:
	// MyGateway constructor
	MyGatewayTransportSerial(MyProtocol &protocol = *new MyProtocolDefault());

	// initialize the transport driver
	bool begin();

	// Send message to controller
	bool send(MyMessage &message);

	// Check if a new message is available from controller
	bool available();

	// Pick up last message received from controller
	MyMessage& receive();
private:
	char inputString[MAX_RECEIVE_LENGTH];    // A buffer for incoming commands from serial interface
	int inputPos;
	MyMessage msg;
};

#endif

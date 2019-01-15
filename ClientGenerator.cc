/*
 * ClientGenerator.cc
 *
 *  Created on: 15 sty 2019
 *      Author: Karol Kostorz
 */


#include <omnetpp.h>
#include <stdlib.h>

using namespace omnetpp;

Define_Module(ClientGenerator);
    void ClientGenerator::initialize()
    {
        n = 4;
    }

    void ClientGenerator::handleMessage(cMessage *msg)
    {
        cMessage *message = new cMessage("");
        send(message, "out");
    }


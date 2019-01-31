/*
 * Exit.cc
 *
 *  Created on: 15 sty 2019
 *      Author: Karol Kostorz
 */


#include <omnetpp.h>
#include <stdlib.h>
#include "AirportMessage_m.h"

using namespace omnetpp;

class Exit : public cSimpleModule
{
  private:
    int passengerCount;
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage  *msg) override;
};

Define_Module(Exit);

void Exit::initialize()
{
    passengerCount = 0;
}

void Exit::handleMessage(cMessage  *msg)
{
    AirportMessage *rmsg = check_and_cast<AirportMessage *>(msg);
    EV << "Passenger at Exit.\n";
    passengerCount++;
    delete rmsg;
}


/*
 * Plane.cc
 *
 *  Created on: 15 sty 2019
 *      Author: Karol Kostorz
 */



#include <omnetpp.h>
#include <stdlib.h>
#include "AirportMessage_m.h"

using namespace omnetpp;

class Plane : public cSimpleModule
{
  private:
    int passengerCount;
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage  *msg) override;
};

Define_Module(Plane);

void Plane::initialize()
{
    passengerCount = 0;
}

void Plane::handleMessage(cMessage  *msg)
{
    AirportMessage *rmsg = check_and_cast<AirportMessage *>(msg);
    EV << "Passenger at Plane.\n";
    passengerCount++;
    delete rmsg;
}

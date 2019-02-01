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
    cDoubleHistogram PassengersTimeStats;
  protected:
    virtual void finish() override;
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

    PassengersTimeStats.collect(rmsg->getArrivalTime() - rmsg->getTimestamp());

    EV << "Passenger at Exit.\n";
    passengerCount++;
    delete rmsg;
}

void Exit::finish()
{
    // This function is called by OMNeT++ at the end of the simulation.
    EV << "Received:     " << passengerCount << endl;
    EV << "Hop count, min:    " << PassengersTimeStats.getMin() << endl;
    EV << "Hop count, max:    " << PassengersTimeStats.getMax() << endl;
    EV << "Hop count, mean:   " << PassengersTimeStats.getMean() << endl;
    EV << "Hop count, stddev: " << PassengersTimeStats.getStddev() << endl;

    recordScalar("#passengerCount", passengerCount);

    PassengersTimeStats.recordAs("hop count");
}


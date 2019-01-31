/*
 * PrimaryControl.cc
 *
 *  Created on: 15 sty 2019
 *      Author: Karol Kostorz
 */

#include <omnetpp.h>
#include <stdlib.h>
#include "PassengerMessage_m.h"
#include "QueueMessage_m.h"

using namespace omnetpp;

class PrimaryControl : public cSimpleModule
{
  private:
    float delay;
    bool controlDone;
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage  *msg) override;
};

Define_Module(PrimaryControl);

void PrimaryControl::initialize()
{
    delay = 1.0;
    controlDone = false;
}

void PrimaryControl::handleMessage(cMessage *msg)
{
    PassengerMessage *rmsg = check_and_cast<PassengerMessage *>(msg);

    EV << "Passenger arrived at Primary control.\n";
    if (controlDone)
    {
        int prob = intuniform(0, 10);
        if (prob > 8)
        {
            rmsg->setIsDirty(true);
            EV << "Passenger send to Secondary control.\n";
            send(rmsg,"outSecondary");
        }
        else
        {
            send(rmsg,"outPlane");
            EV << "Passenger send to Plane.\n";
        }
        controlDone = false;
        QueueMessage *qmsg = new QueueMessage();
        send(qmsg,"outSignal");
    }
    else
    {
        scheduleAt(simTime() + delay, rmsg);
        controlDone = true;
    }

}

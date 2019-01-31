/*
 * PrimaryControl.cc
 *
 *  Created on: 15 sty 2019
 *      Author: Karol Kostorz
 */

#include <omnetpp.h>
#include <stdlib.h>
#include "AirportMessage_m.h"
#include "PayloadType.h"

using namespace omnetpp;

class PrimaryControl : public cSimpleModule
{
  private:
    bool controlDone;
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage  *msg) override;
};

Define_Module(PrimaryControl);

void PrimaryControl::initialize()
{
    controlDone = false;
}

void PrimaryControl::handleMessage(cMessage *msg)
{
    AirportMessage *rmsg = check_and_cast<AirportMessage *>(msg);

    EV << "Passenger arrived at Primary control.\n";
    if (controlDone)
    {
        if (rmsg->par("primaryFail"))
        {
            EV << "Passenger send to Secondary control.\n";
            send(rmsg,"outSecondary");
        }
        else
        {
            send(rmsg,"outPlane");
            EV << "Passenger send to Plane.\n";
        }
        controlDone = false;
        AirportMessage *qmsg = new AirportMessage();
        qmsg->setKind(PayloadType::QUEUE);
        send(qmsg,"outSignal");
    }
    else
    {
        scheduleAt(simTime() + rmsg->getDelay(), rmsg);
        controlDone = true;
    }

}

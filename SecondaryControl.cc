/*
 * SecondaryControl.cc
 *
 *  Created on: 15 sty 2019
 *      Author: Karol Kostorz
 */

#include <omnetpp.h>
#include <stdlib.h>
#include "AirportMessage_m.h"
#include "PayloadType.h"

using namespace omnetpp;

class SecondaryControl : public cSimpleModule
{
    private:
      bool controlDone;
    protected:
      virtual void initialize() override;
      virtual void handleMessage(cMessage  *msg) override;
};

Define_Module(SecondaryControl);

void SecondaryControl::initialize()
{
    controlDone = false;
}

void SecondaryControl::handleMessage(cMessage *msg)
{
    AirportMessage *rmsg = check_and_cast<AirportMessage *>(msg);

    EV << "Passenger arrived at Secondary control.\n";
    if (controlDone)
    {
        if (rmsg->par("secondaryFail"))
        {
            EV << "Passenger send to Exit.\n";
            send(rmsg,"exit");
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

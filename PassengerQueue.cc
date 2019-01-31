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

class PassengerQueue : public cSimpleModule
{
  private:
    bool canSend;

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage  *msg) override;
};

Define_Module(PassengerQueue);

void PassengerQueue::initialize()
{
    canSend = true;
}

void PassengerQueue::handleMessage(cMessage *msg)
{
    try
    {
        QueueMessage *rmsg = check_and_cast<QueueMessage *>(msg);
        EV << "Message is queue.\n";
        canSend = true;
        delete rmsg;
    }
    catch(...)
    {
        PassengerMessage *rmsg = check_and_cast<PassengerMessage *>(msg);
        EV << "Message is passenger.\n";
        if (canSend)
        {
            send(rmsg,"outPassenger");
            canSend = false;
        }
        else
        {
            scheduleAt(simTime() + 0.0, rmsg);
        }
    }

}


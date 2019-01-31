/*
 * ClientGenerator.cc
 *
 *  Created on: 15 sty 2019
 *      Author: Karol Kostorz
 */


#include <omnetpp.h>
#include <stdlib.h>
#include "PassengerMessage_m.h"
#include "QueueMessage_m.h"
#include "Passenger.h"

using namespace omnetpp;

class ClientGenerator : public cSimpleModule
{
  private:
    int passengerCount = 0;
  protected:
    virtual PassengerMessage *generateMessage();
    virtual void initialize() override;
    virtual void handleMessage(cMessage  *msg) override;

};


Define_Module(ClientGenerator);

void ClientGenerator::initialize()
{
    QueueMessage* p = new QueueMessage("Inital");

    scheduleAt(0.0,p);
}

PassengerMessage *ClientGenerator::generateMessage()
{
    // Produce source and destination addresses.

    char msgname[15];
    sprintf(msgname, "Passenger no%d", passengerCount);
    passengerCount++;
    // Create message object and set source and destination field.
    //PassengerMessage *msg = new PassengerMessage(msgname);
    AirportMessage *msg = new AirportMessage(msgname);
    Passenger *p = new Passenger();
    double d = normal(3.0, 1.5);
    int n = intuniform(0,10);
    bool isDirty  = false;
    if (n < 3) {
        isDirty = true;
    }
    p->FillPasenger(d, isDirty);

    return msg;
}


void ClientGenerator::handleMessage(cMessage  *msg)
{
    QueueMessage *qmsg = check_and_cast<QueueMessage *>(msg);

    int count = qmsg->getCount();

    qmsg->setCount(count++);

    if (passengerCount < 50)
    {
        scheduleAt(simTime() + 1.0,qmsg);

    EV << "Sending passenger.\n";


    AirportMessage *pmsg = generateMessage();

    send(pmsg, "out");
    }

}




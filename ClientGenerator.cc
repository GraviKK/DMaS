/*
 * ClientGenerator.cc
 *
 *  Created on: 15 sty 2019
 *      Author: Karol Kostorz
 */


#include <omnetpp.h>
#include <stdlib.h>
#include "AirportMessage_m.h"
#include "PayloadType.h"

using namespace omnetpp;

class ClientGenerator : public cSimpleModule
{
  private:
    int passengerCount = 0;
  protected:
    virtual AirportMessage *generateMessage();
    virtual void initialize() override;
    virtual void handleMessage(cMessage  *msg) override;

};


Define_Module(ClientGenerator);

void ClientGenerator::initialize()
{
    AirportMessage* msg = new AirportMessage("Inital");
    msg->setKind(PayloadType::QUEUE);
    scheduleAt(0.0,msg);
}

AirportMessage *ClientGenerator::generateMessage()
{
    // Produce source and destination addresses.

    char msgname[15];
    sprintf(msgname, "Passenger no%d", passengerCount);
    passengerCount++;
    AirportMessage *msg = new AirportMessage(msgname);
    msg->setKind(PayloadType::PASSENGER);
    msg->setDelay(normal(3.0, 1.5));
    msg->addPar("primaryFail");
    msg->addPar("secondaryFail");
    int n = intuniform(0,10);
    msg->par("primaryFail")  = false;
    msg->par("secondaryFail")  = false;
    if (n < 3) {
        msg->par("primaryFail") = true;
        int m = intuniform(0,10);
        if ( m < 5) {
            msg->par("secondaryFail")  = true;
        }
    }

    return msg;
}


void ClientGenerator::handleMessage(cMessage  *msg)
{
    AirportMessage *qmsg = check_and_cast<AirportMessage *>(msg);


    if (passengerCount < 50)
    {
        scheduleAt(simTime() + normal(1.0, 0.5),qmsg);

    EV << "Sending passenger.\n";


    AirportMessage *pmsg = generateMessage();

    send(pmsg, "out");
    }

}




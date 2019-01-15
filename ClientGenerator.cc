/*
 * ClientGenerator.cc
 *
 *  Created on: 15 sty 2019
 *      Author: Karol Kostorz
 */


#include <omnetpp.h>
#include <stdlib.h>

using namespace omnetpp;

class ClientGenerator : public cSimpleModule
{
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};


Define_Module(ClientGenerator);

void ClientGenerator::initialize()
{

}

void ClientGenerator::handleMessage(cMessage *msg)
{
    cMessage *message = new cMessage("");
    send(message, "out");
}


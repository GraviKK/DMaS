
#include <omnetpp.h>
#include <ctime>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace omnetpp;

class ArrivalQueue : public cSimpleModule
{
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void refreshDisplay();
};

Define_Module(ArrivalQueue);

void ArrivalQueue::initialize()
{

}

void ArrivalQueue::handleMessage(cMessage *msg)
{

}

void ArrivalQueue::refreshDisplay()
{

}

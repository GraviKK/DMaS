
#include <omnetpp.h>
#include <ctime>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace omnetpp;

Define_Module(ArrivalQueue);

void ArrivalQueue::initialize()
{

}

void ArrivalQueue::handleMessage(cMessage *msg)
{
    cMessage *message = new cMessage("");
    send(message, "tout");
}


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
    send(message, "out");
    send(message, "out2");
}

void ArrivalQueue::refreshDisplay() const
{
//    char buf[60];
//    sprintf(buf, "Clients: %ld\tFirst: %ld", clients.size(), clients.size() > 0 ? clients.front() + 1 : -1);
//    //sprintf(buf, "Clients increase: %f", current_clients_increase);
//    getDisplayString().setTagArg("t", 0, buf);
}

/*
 * Exit.cc
 *
 *  Created on: 15 sty 2019
 *      Author: Karol Kostorz
 */


#include <omnetpp.h>
#include <stdlib.h>

using namespace omnetpp;

class Exit : public cSimpleModule
{
  protected:
    virtual void initialize() override;
};

Define_Module(Exit);

void Exit::initialize()
{

}

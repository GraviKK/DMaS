/*
 * PrimaryControl.cc
 *
 *  Created on: 15 sty 2019
 *      Author: Karol Kostorz
 */

#include <omnetpp.h>
#include <stdlib.h>

using namespace omnetpp;

class PrimaryControl : public cSimpleModule
{
  protected:
    virtual void initialize() override;
};

Define_Module(PrimaryControl);

void PrimaryControl::initialize()
{

}

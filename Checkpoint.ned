//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//
//
// TODO documentation
//
network checkpoint
{
    @display("bgb=974,507;bgl=2");
    types:
        simple PassengerQueue
        {
            gates:
                output outPassenger;
                input in;
                input inSignal;
        }

        simple PrimaryControl
        {
            gates:
                input in;
                output outSecondary;
                output outPlane;
                output outSignal;
        }

        simple SecondaryControl
        {
            gates:
                input in;
                output outPlane;
                output exit;
                output outSignal;
        }

        simple Plane
        {
            gates:
                input inPrimary;
                input inSecondary;

        }

        simple Exit
        {
            gates:
                input in;
        }

        simple ClientGenerator
        {
            gates:
                output out;
        }

    submodules:
        arrivalQueue: PassengerQueue {
            @display("p=423,382");
        }
        secondaryQueue: PassengerQueue {
            @display("p=473.1075,202.935");
        }
        primaryControll: PrimaryControl {
            @display("p=425.43,297.0675");
        }
        secondaryControll: SecondaryControl {
            @display("p=573.3525,112.47");
        }
        plane: Plane {
            @display("p=423,82");
        }
        exit: Exit {
            @display("p=710,183");
        }
        clientGenerator: ClientGenerator {
            @display("p=637,382");
        }
    connections:
        arrivalQueue.outPassenger --> primaryControll.in;
        primaryControll.outSecondary --> secondaryQueue.in;
        secondaryQueue.outPassenger --> secondaryControll.in;
        primaryControll.outPlane --> plane.inPrimary;
        secondaryControll.outPlane --> plane.inSecondary;
        secondaryControll.exit --> exit.in;
        clientGenerator.out --> arrivalQueue.in;
        primaryControll.outSignal --> arrivalQueue.inSignal;
        secondaryControll.outSignal --> secondaryQueue.inSignal;
}


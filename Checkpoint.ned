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
    @display("bgb=974,507");
    types:
        simple ArrivalQueue
        {
            gates:
                output out;
        }

        simple PrimaryControl
        {
            gates:
                input in;
                output outSecondary;
                output outPlane;
        }

        simple SecondaryControl
        {
            gates:
                input in;
                output out;
                output exit;
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

    submodules:
        arrivalQueue: ArrivalQueue {
            @display("p=423,382");
        }
        primaryControll: PrimaryControl {
            @display("p=423,288");
        }
        secondaryControll: SecondaryControl {
            @display("p=534,183");
        }
        plane: Plane {
            @display("p=423,82");
        }
        exit: Exit {
            @display("p=710,183");
        }
    connections:
        arrivalQueue.out --> primaryControll.in;
        primaryControll.outSecondary --> secondaryControll.in;
        primaryControll.outPlane --> plane.inPrimary;
        secondaryControll.out --> plane.inSecondary;
        secondaryControll.exit --> exit.in;
}


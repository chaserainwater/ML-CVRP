//Program that generates Capacitated Vehicle Routing Problems with parameters provided by the user
//
////This follows the examples provided by the CVRPLIB,
//Capacitated Vehicle Routing Problem Library,
//http://vrp.atd-lab.inf.puc-rio.br/index.php/en/.
//
//
//
//
//


#include<iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


using namespace std;
//test
//Start the Main Function

int main()

{

//Initialize beginning variables:

int NumofInsts;
int NumofNodes;
int NumofVehics;
int CapofVehics;
int DistLower;
int DistUpper;
int DistDiff;
string Exit;
stringstream InstantID;
int DemandMult;
int Demand;

//Get the number of instances to be generated and the parameters for said instances.
    cout << "This program will calculate a number of Capacitated Vehicle Routing Problems, given your parameters. \n";
    cout << "How many instances do you want to calculate? \n";
    cin >> NumofInsts  ;
    cout<<"Help";

    cout << "Enter n, the number of nodes used in the graph. \n";
    cin >> NumofNodes  ;

    cout << "Enter k, the number of vehicles in the problem.  \n";
    cin >> NumofVehics  ;

    cout << "Enter c, the capacity of the vehicles in the problem.  \n";
    cin >> CapofVehics  ;

    cout << "The demand at each node will be based on a uniform distribution. \n";
    cout << "Enter the lower bound for the distribution. \n";
    cin >> DistLower  ;

    cout << "Enter the upper bound for the distribution. \n";
    cin >> DistUpper  ;

    cout << NumofInsts << " instances of: \n";
    cout << "Name :  UAIE-n"<<NumofNodes<<"-k"<<NumofVehics<<"\n";
    cout << "Comment: (Based off of Augerat et al)\n";
    cout << "Type: CVRP \n";
    cout << "DIMENSION : " << NumofNodes << "\n";
    cout << "EDGE_WEIGHT_TYPE : EUC_2D \n";
    cout << "CAPACITY : " << CapofVehics << "\n";
    cout << "Please check your directory. \n";


//Create random processes to draw from. This is used for the node placement,
//demands, and demand multiplication factors respectively.

//Random process for the node placement
    random_device NodeRanDev;
    mt19937 NodeGen(NodeRanDev());
    uniform_int_distribution<> NodeDis(1, 100);

//Random process for demands of nodes
//This is a uniform distribution from the parameters provided
    random_device DemandRanDev;
    mt19937 DemandGen(DemandRanDev());
    uniform_int_distribution<> DemandDis(DistLower, DistUpper);

//Random process for having some nodes' demands multiplied by 10.
    random_device DemandMultRanDev;
    mt19937 DemandMultGen(DemandMultRanDev());
    uniform_int_distribution<> DemandMultDis(1, 10);






//Creates a for-loop for the number of instances desired
for (int k = 0; k < NumofInsts ; k++ )
{

stringstream InstantID;

    //Identify Instance ID and names txt file.
    InstantID <<"UAIE-n"<<NumofNodes<<"-k"<<NumofVehics<<"-"<<k+1<<".txt";
    //cout << InstantID << "\n";

    //Creates file for instance k+1
    ofstream myfile;
    myfile.open(InstantID.str());
    myfile << "Name :  UAIE-n"<<NumofNodes<<"-k"<<NumofVehics<<"-"<<k+1<<"\n";
    myfile << "Comment : (Based off of Augerat et al)\n";
    myfile << "Type : CVRP \n";
    myfile << "DIMENSION : " << NumofNodes << "\n";
    myfile << "EDGE_WEIGHT_TYPE : EUC_2D \n";
    myfile << "CAPACITY : " << CapofVehics << "\n";
    myfile << "NODE_COORD_SECTION  \n";

//The following creates a list with n number of nodes.
//The coordinates are generated randomly within a square of side 100.

    for (int n=0; n<NumofNodes; ++n)
        {
            myfile << n+1 << ' ';
            myfile << NodeDis(NodeGen) << ' ' <<  NodeDis(NodeGen);
            myfile << '\n';
        }


    myfile << "DEMAND_SECTION  \n";

//The first node is considered the Depot and has a demand of 0.
    myfile << "1 0  \n";

//Creates the list for demands at each node
    for (int n=1; n<NumofNodes; ++n)
        {
            DemandMult = DemandMultDis(DemandMultGen);
            Demand = DemandDis(DemandGen);

            if(DemandMult == 0){
                myfile << n+1 << ' ';
               // myfile << Demand << ' ';
                myfile << Demand*3 << ' ' ;
                    //To check to see which ones are being multiplied by 3.
                    //This should be approximately one tenth of the nodes.
                    myfile << "True" ;
                myfile << '\n';
            }
            else{
                myfile << n+1 << ' ';
                myfile << Demand << ' ' ;
                myfile << '\n';
            }
        }


    myfile << "DEPOT_SECTION  \n";
    myfile << "1  \n";
    myfile << "-1  \n";
    myfile << "EOF  \n";

    //Closes current file.
    myfile.close();

    //Clears file names in for-loop.
  //  delete InstantID;


//Ends the for loop to create more than once instance.
}






    cout << "Ready to exit? \n";
    cin >> Exit ;

  return 0;
}

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


using namespace std;

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

//Get the number of instances to be generated and the parameters for said instances.
    cout << "This program will calculate a number of Capacitated Vehicle Routing Problems, given your parameters. \n";
    cout << "How many instances do you want to calculate? \n";
    cin >> NumofInsts  ;

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




//Creates a for loop for the number of instances desired
for (int k = 0; k < NumofInsts ; k++ )
{

    cout << "Name :  UAIE-n"<<NumofNodes<<"-k"<<NumofVehics<<"-"<<k+1<<"\n";
    cout << "Comment : (Based off of Augerat et al)\n";
    cout << "Type : CVRP \n";
    cout << "DIMENSION : " << NumofNodes << "\n";
    cout << "EDGE_WEIGHT_TYPE : EUC_2D \n";
    cout << "CAPACITY : " << CapofVehics << "\n";
    cout << "NODE_COORD_SECTION  \n";

//
//
//The following creates a graph with n number of nodes.
//The coordinates are generated randomly within a square of side 100.
//
//


    random_device NodeRanDev;
    mt19937 NodeGen(NodeRanDev());
    uniform_int_distribution<> NodeDis(1, 100);

    for (int n=0; n<NumofNodes; ++n)
        {

            cout << n+1 << ' ';
            cout << NodeDis(NodeGen) << ' ' <<  NodeDis(NodeGen) ;
            cout << '\n';
        }

    cout << "DEMAND_SECTION  \n";

//
//
//The following creates a uniform distribution from the parameters provided
//for the number of nodes provided.
//
//


//The first node is considered the Depot and has a demand of 0.

            cout << "1 0  \n";


    random_device DemandRanDev;
    mt19937 DemandGen(DemandRanDev());
    uniform_int_distribution<> DemandDis(DistLower, DistUpper);

    for (int n=1; n<NumofNodes; ++n)
        {

            cout << n+1 << ' ';
            cout << DemandDis(DemandGen) << ' ' ;
            cout << '\n';
        }


    cout << "DEPOT_SECTION  \n";
    cout << "1  \n";
    cout << "-1  \n";
    cout << "EOF  \n";


//Ends the for loop to create more than once instance.
}









    cout << "Ready to exit? \n";
    cin >> Exit ;

  return 0;
}

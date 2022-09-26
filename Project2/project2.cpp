// Computing Structures Fall 2022
// DSA 5005
// Aditya Narasimhan

#include <iostream>
#include <string>

using namespace std;

// class node to store one node's details
template <class DT>
class Node
{
protected:
    int nodeNumber;  // field to store node's number
    string nodeInfo; // field to store node's information
    DT yearCreated;  // field to store the year of the node created
    string location; // field to store the location

public:
    Node(); // default constructor

    // getters
    string getNodeInfo();
    int getNodeNumber();
    DT getYearCreated();
    string getLocation();

    // setters
    void setNodeInfo(string newInfo, DT newYearCreated, string newLoc); // V2: updated
    void setNodeNumber(int newNum);
    void setYearCreated(DT newYearCreated);
    void setLocation(string newLocation);

    void display(); // display node details

    ~Node(); // destructor
};

// function definitions

// constructor

template <class DT>
Node<DT>::Node() {
    nodeNumber = -1;
    nodeInfo = "";
    yearCreated = NULL;
    location = "";
}

// getters definitions
template <class DT>
string Node<DT>::getNodeInfo() {
    return nodeInfo;
}
template <class DT>
int Node<DT>::getNodeNumber() {
    return nodeNumber;
}

template <class DT>
DT Node<DT>::getYearCreated() {
    return yearCreated;
}
template <class DT>
string Node<DT>::getLocation() {
    return location;
}

// setters definitions


template <class DT>
void Node<DT>::setNodeInfo(string newInfo, DT newYearCreated, string newLoc) {
    nodeInfo = newInfo;
    yearCreated = newYearCreated;
    location = newLoc;
}

template <class DT>
void Node<DT>::setNodeNumber(int newNum) {
    nodeNumber = newNum;
}

template <class DT>
void Node<DT>::setYearCreated(DT newYearCreated) {
    yearCreated = newYearCreated;
}

template <class DT>
void Node<DT>::setLocation(string newLocation) {
    location = newLocation;
}

template <class DT>
void Node<DT>::display() {
    int nodeN = getNodeNumber();
    string nodeIn = getNodeInfo();
    int yearMade = getYearCreated();
    string place = getLocation();
    cout << nodeN << ": " << nodeIn << ", " << yearMade << ", " << place << endl;
    //cout << nodeNumber << ": " << nodeInfo << ", " << yearCreated << ", " << location << endl;
}

// Destructor

template <class DT>
Node<DT>::~Node() {
    // Destructor stub
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// class to store one edge's details
template <class DT>
class Edge
{
protected:
    Node<DT> *u;     // field to store source node pointer
    Node<DT> *v;     // field to store destination node pointer
    string edgeInfo; // field to store edge information
    DT yearsKnown;   // u and v - years known

public:
    Edge(); // default constructor
    // getters
    Node<DT>* getu();
    Node<DT>* getv();
    string getEdgeInfo();
    DT getYearsKnown();

    // setters
    void setu(Node<DT> *newu);
    void setv(Node<DT> *newv);
    void setEdgeInfo(string newInfo, DT newYearsKnown); // V2: updated
    void setYearsKnown(DT newYear);                     // V2: updated

    void display(); // display edge details

    ~Edge(); // destructor
};


// function definitions

// constructor

template <class DT>
Edge<DT>::Edge() {
    u = NULL;
    v = NULL;
    edgeInfo = "";
    yearsKnown = NULL;
}

// getters

template <class DT>
Node<DT>* Edge<DT>::getu() {
    return u;
}

template <class DT>
Node<DT>* Edge<DT>::getv() {
    return v;
}

template <class DT>
string Edge<DT>::getEdgeInfo() {
    return edgeInfo;
}

template <class DT>
DT Edge<DT>::getYearsKnown() {
    return yearsKnown;
}

// setters

template <class DT>
void Edge<DT>::setu(Node<DT> *newu) {
    u = newu;
}

template <class DT>
void Edge<DT>::setv(Node<DT> *newv) {
    v = newv;
}

template <class DT>
void Edge<DT>::setEdgeInfo(string newInfo, DT newYearsKnown) {
    edgeInfo = newInfo;
    yearsKnown = newYearsKnown;
}

template <class DT>
void Edge<DT>::setYearsKnown(DT newYear) {
    yearsKnown = newYear;
}

// display and destructor

template <class DT>
void Edge<DT>::display() {
    string nodeUInfo = u->getNodeInfo();
    string nodeVInfo = v->getNodeInfo();
    string displayEdgeInfo = getEdgeInfo();
    int yearsKnown = getYearsKnown();
    cout << nodeUInfo << " - " << nodeVInfo << " " << displayEdgeInfo << ", " << yearsKnown << endl;
    //cout << displayEdgeInfo << ", " << yearsKnown << endl;
}

template <class DT>
Edge<DT>::~Edge() {
    // Destructor stub
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// class to store the graph
template <class DT>
class GraphDB
{
    // TODO: ostream operator for displaying myNodes and myEdges
    //friend ostream& operator<< (ostream& s, const <DT> arr);
protected:
    Node<DT>* myNodes; // array of nodes
    Edge<DT>* myEdges; // array of edges
    int numNodes;      // number of nodes
    int numEdges;      // number of edges
    int maxEdges;      // store the max number of edges (array size)

public:
    GraphDB(int nNodes, int nEdges); // non-default constructor
    // setters
    void setNode(Node<DT>& newNode);
    void setEdge(Edge<DT>& newEdge);
    void setNodeInfo(int u, string newInfo);
    void setEdgeInfo(int u, int v, string newInfo);

    // getters
    Node<DT> *getNode(int nodeNum);
    string getNodeInfo(int nodeNum);
    Edge<DT> *getEdgeInfo(int u, int v);

    // operations
    bool isAnEdge(int u, int v);     // is this edge existent
    bool edgeChecker(int u, int v); // auxillary method to check 2 nodes for an edge
    void addEdge(Edge<DT>& newEdge); // add an edge
    void deleteEdge(int u, int v);   // delete the edge
    void display();                  // display the contents of the two arrays
    int *findNeighbours(int u);      // returns an integer array of neighbours' nodeNum

    ~GraphDB(); // destructor
};

// constructor

template <class DT>
GraphDB<DT>::GraphDB(int nNodes, int nEdges) {
    numNodes = nNodes;
    maxEdges = nEdges;
    numEdges = 0;
    myNodes = new Node<int>[numNodes];
    myEdges = new Edge<int>[maxEdges];
}

// setters 

template <class DT>
void GraphDB<DT>::setNode(Node<DT>& newNode) {
    int newNodeNum = newNode.getNodeNumber();
    string newNodeInfo = newNode.getNodeInfo();
    int nodeYear = newNode.getYearCreated();
    string nodeLocation = newNode.getLocation();
    // Set to Node at newNodeNum
    myNodes[newNodeNum].setNodeNumber(newNodeNum);
    myNodes[newNodeNum].setNodeInfo(newNodeInfo, nodeYear, nodeLocation);
}

template <class DT>
void GraphDB<DT>::setEdge(Edge<DT>& newEdge) {
    //numEdges = numEdges + 1;
    // Extract string info and years known
    string newEdgeInfo = newEdge.getEdgeInfo();
    int years = newEdge.getYearsKnown();
    Node<int>* nodeU = &newEdge.getu();
    //Node<int>* nodeV = &newEdge.getv();
    //Node<DT>* Edge<DT>::getu()
    // Set to last box of myEdges array
    myEdges[numEdges - 1].setu(&newEdge.getu());
    myEdges[numEdges - 1].setv(&newEdge.getv());
    myEdges[numEdges - 1].setEdgeInfo(newEdgeInfo, years);
}

template <class DT>
void GraphDB<DT>::setNodeInfo(int u, string newInfo) {
    // Set the nodeInfo at node U to newInfo
    myNodes[u].setNodeInfo(newInfo);
}

template <class DT>
void GraphDB<DT>::setEdgeInfo(int u, int v, string newInfo) {
    // Find the edge that connects u and v
    // use setEdgeInfo(newInfo)
    // Loop through the myEdges array
    for (int i = 0; i < numEdges; ++i) {
        // Create 2 nodes to store u and v
        Node nodeU = myEdges[i].getu();
        Node nodeV = myEdges[i].getv();
        // If the u and v matches tempU and tempV, then set the newInfo into that edge
        // and break the loop
        if (nodeU.getNodeNumber() == u && nodeV.getNodeNumber() == v) {
            myEdges[i].setEdgeInfo(newInfo);
            break;
        }
    }
}

// getters

template <class DT>
Node<DT>* GraphDB<DT>::getNode(int nodeNum) {
    return &myNodes[nodeNum];
}

template <class DT>
string GraphDB<DT>::getNodeInfo(int nodeNum) {
    return myNodes[nodeNum].getNodeInfo();
}

template <class DT>
Edge<DT>* GraphDB<DT>::getEdgeInfo(int u, int v) {
    for (int i = 0; i < numEdges; ++i) {
        Edge thisEdge = myEdges[i];
        Node nodeU = myEdges[i].getu();
        Node nodeV = myEdges[i].getv();
        if (nodeU.getNodeNumber() == u && nodeV.getNodeNumber() == v) {
            // return would also break the loop
            return &thisEdge;
        }
    }
}

// operations

template <class DT>
bool GraphDB<DT>::edgeChecker(int u, int v) {
    bool isEdge = false;
    for (int i = 0; i < numEdges; ++i) {
        Edge thisEdge = myEdges[i];
        Node nodeU = myEdges[i].getu();
        Node nodeV = myEdges[i].getv();
        // Find the edge
        if (nodeU.getNodeNumber() == u && nodeV.getNodeNumber() == v) {
            isEdge = true;
            return isEdge;
        }
        else {
            // Keep looping until you find the edge
            continue;
        }
    }
    return isEdge;
}

template <class DT>
bool GraphDB<DT>::isAnEdge(int u, int v) {
    bool isEdge = edgeChecker(u, v);
    if (isEdge == true) {
        cout << "Edge exists between " << myNodes[u].getNodeInfo() << " and " << myNodes[v].getNodeInfo() << endl;
    }
    else {
        cout << "No edge exists between " << myNodes[u].getNodeInfo() << " and " << myNodes[v].getNodeInfo() << endl;
    }
    return isEdge;
}

template <class DT>
void GraphDB<DT>::addEdge(Edge<DT>& newEdge) { // Similar to setEdge
    // Currently, if statement not being executed
    //cout << numEdges << maxEdges << endl;
    numEdges = numEdges + 1;
    if (numEdges < maxEdges) {
        setEdge(newEdge);
    }
    else {
        // Increase by 1 every time
        int difference = 1;
        // Update maxEdges to a larger number
        maxEdges = maxEdges + difference;
        // Expand array
        Edge* tempEdge = new Edge[maxEdges];
        for (int i = 0; i < numEdges; ++i) {
            // Fill up the temp array
            tempEdge[i] = myEdges[i];
        }
        // Delete old myEdges array
        delete[] myEdges;
        // Point new myEdges array to temp array
        myEdges = tempEdge;
        // Set the edge
        setEdge(newEdge);
    }
}

template <class DT>
void GraphDB<DT>::deleteEdge(int u, int v) {
    bool isEdge = edgeChecker(u, v);
    if (isEdge == true) {
        // If edge exists, delete it
        cout << "Removing " << u << " " << v << endl;
        // Create a temp array with the size of maxEdges
        Edge* tempEdge = new Edge[maxEdges];
        for (int i = 0; i < numEdges; ++i) {
            Edge thisEdge = myEdges[i];
            Node nodeU = myEdges[i].getu();
            Node nodeV = myEdges[i].getv();
            // Find the edge to be remove
            if (nodeU.getNodeNumber() == u && nodeV.getNodeNumber() == v) {
                // Fill first part of temp, skip i
                for (int j = 0; j < i; ++j) {
                    //cout << "Filling first half" << endl;
                    tempEdge[j] = myEdges[j];
                }
                // Fill the rest of temp
                for (int j = i + 1; j < numEdges; ++j) {
                    // Need j - 1 for tempEdge otherwise the 
                    // new array will have an empty spot
                    tempEdge[j - 1] = myEdges[j];
                }
                break;
            }
        }
        // Decrease numEdges by 1
        numEdges = numEdges - 1;
        // Delete old array
        delete[] myEdges;
        // Assign new array pointer 
        myEdges = tempEdge;
    }
    else {
        // If edge does not exist, print a statement
        cout << "Removing " << u << " " << v << " but this edge does not exist." << endl;
    }
}



template <class DT>
void GraphDB<DT>::display() {
    cout << "Displaying myNodes: " << endl;
    for (int i = 0; i < numNodes; i++) {
        myNodes[i].display();
    }
    /*cout << "Displaying myEdges: " << endl;
    for (int i = 0; i < numEdges; i++) {
        myEdges[i].display();
    }*/

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main()
{

    // you can start with the same main function from project 1
    int numNodes;
    int maxEdges;
    int nodeNum;
    string nodeInfo;
    int year;
    string nodeLocation;
    int u, v, knownyears;
    char command;

    cin >> numNodes >> maxEdges;

    cout << "numNodes: " << numNodes << endl;
    cout << "maxEdges: " << maxEdges << endl;

    /*Node<int>* test = new Node<int>();

    int nodeNum = 0;
    string nodeInfo = "Harry";
    string nodeLocation = "London";
    int year = 1051994;

    test->setNodeNumber(nodeNum);
    test->setNodeInfo(nodeInfo, year, nodeLocation);

    test->display();

    Node<int>* test1 = new Node<int>();

    int test1Num = 1;
    string test1Info = "Ron";
    string test1Location = "Liverpool";
    int test1year = 10071995;

    test1->setNodeNumber(test1Num);
    test1->setNodeInfo(test1Info, test1year, test1Location);

    test1->display();

    Edge<int>* testEdge = new Edge<int>();
    testEdge->setu(test);
    testEdge->setv(test1);
    testEdge->setEdgeInfo("friend", 4);

    testEdge->display();*/

    GraphDB<int>* masterGraph = new GraphDB<int>(numNodes, maxEdges);

    for (int i = 0; i < numNodes; i++) {
        // Read in node number and node info
        cin >> nodeNum >> nodeInfo >> year >> nodeLocation;
        // Create new node object
        Node<int>* addNode = new Node<int>();
        // Set the node number and info
        addNode->setNodeNumber(nodeNum);
        addNode->setNodeInfo(nodeInfo, year, nodeLocation);
        //addNode->display();
        // Set the node into the database
        masterGraph->setNode(*addNode);
    }

    cin >> command;
    while (!cin.eof()) {
        switch (command) {
            case 'I': {
                cin >> u >> v >> nodeInfo >> knownyears;
                // Create new edge object
                Edge<int>* newEdge = new Edge<int>();
                // Get node U and node V from the graph database
                Node<int>* nodeU = masterGraph->getNode(u);
                Node<int>* nodeV = masterGraph->getNode(v);
                // Set node U and node V into edge
                newEdge->setu(nodeU);
                newEdge->setv(nodeV);
                // Set edge information
                newEdge->setEdgeInfo(nodeInfo, knownyears);
                // Print statement
                cout << "Inserting " << u << " " << v << ": " << nodeInfo << ", " << knownyears << endl;
                // Add edge to graph database
                masterGraph->setEdge(*newEdge);
                break;
            }
            case 'E': {
                cin >> u >> v;
                cout << "Need to add case E" << endl;
                break;
            }
            case 'R': {
                cin >> u >> v;
                cout << "Need to add case R" << endl;
                break;
            }
            case 'D': {
                cout << "Need to add case D" << endl;
                masterGraph->display();
                break;
            }
            case 'N': {
                cin >> u;
                cout << "Need to add case N" << endl;
                break;
            }
            default: cout << "Holy cow!" << endl;
        }
        cin >> command;
    }

    return 0;
}
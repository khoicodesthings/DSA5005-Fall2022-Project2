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
}

// getters definitions

string Node<string>::getNodeInfo() {
    return nodeInfo;
}

int Node<int>::getNodeNumber() {
    return nodeNumber;
}

template <class DT>
DT Node<DT>::getYearCreated() {
    return getYearCreated;
}

string Node<string>::getLocation() {
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
    cout << getNodeNumber() << ": " << getNodeInfo() << endl;
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
    Node<DT>* u;     // field to store source node pointer
    Node<DT>* v;     // field to store destination node pointer
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
    void setu(Node<DT>* newu);
    void setv(Node<DT>* newv);
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
    return *u;
}

template <class DT>
Node<DT>* Edge<DT>::getv() {
    return *v;
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
void Edge<DT>::setu(Node<DT>* newu) {
    u = newu;
}

template <class DT>
void Edge<DT>::setv(Node<DT>* newv) {
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
    Node<DT>* getNode(int nodeNum);
    string getNodeInfo(int nodeNum);
    Edge<DT>* getEdgeInfo(int u, int v);

    // operations
    bool isAnEdge(int u, int v);     // is this edge existent
    void addEdge(Edge<DT>& newEdge); // add an edge
    void deleteEdge(int u, int v);   // delete the edge
    void display();                  // display the contents of the two arrays
    int* findNeighbours(int u);      // returns an integer array of neighbours' nodeNum

    ~GraphDB(); // destructor
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main()
{

    // you can start with the same main function from project 1
    int numNodes;
    int maxEdges;

    cin >> numNodes >> maxEdges;

    cout << "numNodes: " << numNodes << endl;
    cout << "maxEdges: " << maxEdges << endl;



    

    return 0;
}
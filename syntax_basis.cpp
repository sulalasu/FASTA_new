#include <iostream>

#define msgLOG(message, x) std::cout << message << ":  " << x << std::endl;
#define LOG(x) std::cout << x << std::endl;

class Studierender
{
public:
    std::string m_vorname;
    std::string m_nachname;
    long m_matrikelnummer;

    //constructor:
    Studierender() {}
    Studierender(const std::string i_nachname) 
        : m_nachname(i_nachname) {}

    //function:
    void printNachname() {
        msgLOG("name: ", m_nachname)
    }
};


class Entity
{
private:
    std::string m_name;

public:
    // constructors:
    Entity() : m_name("Unbekannt") {} //default constructor
    Entity(const std::string& i_name) : m_name(i_name) {} //constrctr with name input

    //getter/setter:
    const std::string& getName() const //1st const: return type is of const reference (string); 2nd const: function does not modify member variable
    {
        return m_name;
    }
};

int main()
{
Entity entity;
std::cout << entity.getName() << std::endl;

Entity entity_2("input name");
//Entity entity_2 = Entity("input name"); => same
std::cout << entity_2.getName() << std::endl;

//__________________new keyword_______________________________
// Creates new instance of class Entity in Heap, with the poiinter (Entity) entity_3 pointing to it.
// But i now have to manuylly free this memory!
Entity* e;
{
    Entity* entity_3 = new Entity("pointer heap name");
    e = entity_3;
    std::cout << entity_3->getName() << std::endl;
    delete entity_3; 
    //delete e;
}
//___________________
// Pointer allgemein: 
//___________________

int x = 10;
int* pX;
pX = &x; // & ist hier kein typ sondern ein operator. return(address of)
//in einem schritt:
// int y = 11;
// int* pY = &y;
msgLOG("original x: ", x);
msgLOG("pointer x:  ", pX);


//dereference (get value of pointer/address)
msgLOG("dereference: ", *pX);

Studierender* pSusi = new Studierender;
//neuer block am heap wird reserviert. new gibt einen pointer zurück.
// der ist in pSusi gespeichert.

Studierender* pMaxi = new Studierender("mustermann");
//geht:
(*pMaxi).printNachname();
pMaxi->printNachname();
//geht nicht:
//pMaxi.printNachname(); // pointer muss erst dereferenced werden!


// im gegensatz zu referenzen können pointer auch null sein:
Studierender* pNuller = NULL;
Studierender* pNullerpointer = nullptr;

// delete löscht das, wohin der pointer zeigt!
msgLOG("delete pX", *pX);
//delete pX; // Segmentation fault: Core dumped WEIL: delete nur in kombi mit 'new' beim instanzieren.
delete pSusi;
delete pMaxi;


int* pNewX = new int;
pNewX = &x;
msgLOG("*pnewx: ", *pNewX);
//delete pNewX; // only deletes pointer, not value stored at pointer!
LOG("deleted pnewx ");
msgLOG("x: ", x);
msgLOG("*pNewX", *pNewX); //now points to random variable



// setting a variable at pointer address:
int* newP = new int;
*newP = 17;
msgLOG("*newP ", *newP);
LOG("hello");
msgLOG("newP: ", newP);

int* z = new int(9);
msgLOG("z address: ", z); 
msgLOG("z: ", (*z));
msgLOG("z: ", *z);
*z = 8;
msgLOG("z", *z);
delete z;
msgLOG("z after delte: ", *z) // random value for z! => UNDEFINED BEHAVIOUR!
msgLOG("z address: ", z); 




LOG("ende des programms");



return 0;
}
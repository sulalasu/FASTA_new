#include <iostream>

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


return 0;
}
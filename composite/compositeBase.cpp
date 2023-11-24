#include <iostream>
#include <list>
#include <string>

using namespace std;

class Component
{
protected:
    string name;
public:
    Component(string name) : name(name) {}

    virtual void Add(Component* pc) = 0;
    virtual void Remove(Component* pc) = 0;
    virtual void Display(int depth) = 0;
};

class Composite : public Component
{
private:
    list<Component*> children;
public:
    Composite(string name): Component(name) {}

    void Add(Component *pc) override
    {
        children.push_front(pc);
    }

    void Remove(Component *pc) override
    {
        children.remove(pc);
    }

    void Display(int depth) override
    {
        cout << string(depth, '-') << Component::name << endl;
        for(auto m : children)
        {
            m->Display(depth + 2);
        }
    }
};

class Leaf : public Component
{
public:
    Leaf(string name) : Component(name) {}

    void Add(Component *pc) override
    {
        cout << "Cannot add to a leaf" << endl;
    }

    void Remove(Component* pc) override
    {
        cout << "Cannot remove from a leaf" << endl;
    }

    void Display(int depth) override
    {
        cout << string(depth, '-') << Component::name << endl;
    }
};

int main()
{
    Composite *root = new Composite("root");
    root->Add(new Leaf("Leaf A"));
    root->Add(new Leaf("Leaf B"));

    Composite *comp = new Composite("Composite X");
    comp->Add(new Leaf("Leaf XA"));
    comp->Add(new Leaf("Leaf XB"));

    root->Add(comp);

    Composite *comp2 = new Composite("Composite XY");
    comp2->Add(new Composite("Leaf XYA"));
    comp2->Add(new Composite("Leaf XYB"));

    comp->Add(comp2);

    root->Add(new Leaf("Leaf C"));

    Leaf *leaf = new Leaf("Leaf D");
    root->Add(leaf);
    root->Remove(leaf);

    root->Display(1);

    return 0;
}
# cpp-qt
Code samples for Design principles in C++ with Qt

# 6. polymorphism and inheritance
* If base class constructor does not need arguments, it will be called automatically in derived class constructor.
    * If it needs argument, call in it derived class initialization list.
    * If nontrivial ctor(s) are defined for base class but derived class ctor does not make explicit calls to them, then either call the nontrivial ctors or define the trivial ctor for the base class  
* valid overriding methods must satisfy: [see this](http://web.cecs.pdx.edu/~karlaf/CS202_Slides/Topic4.pdf)
    1. Public virtual methods in base class, public inheritance of derived class
    2. Methods in base and derived class must have the same signature (argument AND return type)
    3. The overridden method in base class is accessed via base class pointer or reference.
        * Only then will the overriding method in derived class be called
        * In contrast, overloading only require the name to be the same
* If derived class is accessed by base class pointer:
    * If overridden method is declared as `virtual` in base class, then child class method will be called
    * Else, base class method will be called
    * If such access might happen in the code, make base class's destructor `virtual` to ensure that derived class's destructor gets called
* If derived class is accessed by base class object (`Derived d; Base b; b = d; b.` or `Derived d; Base* bptr= &d; Base b = *bptr; b.method();`)
    * Overridden Methods will resolve to base class methods
* Virtual funcitons are not virtual in ctors
    * If a derived class calls base class ctor, which contains calls to base class virtual functions, base class's definitions will be used even though they are called from derived class. 
* Dynamic binding is more flexible but less efficient than static binding
* Abstract Base Class (ABC): 
    * Have at least 1 [pure virtual function](http://www.learncpp.com/cpp-tutorial/126-pure-virtual-functions-abstract-base-classes-and-interface-classes/)
    * Have no public ctor (but may have protected & private ctors)
    * Should not be instantiated
* Hidden vs inaccessible: (see this)[http://www.ics.com/designpatterns/solutions/overloadhide.html#ovl-acctc]
* (Special functions)[http://www.ics.com/designpatterns/solutions/derivedcdas.html] - ctor, copy ctor, copy assignment operator, destructor
    * Base class ctor, either explicitly or implicitly (calling the default ctor), must be called in derived class ctor
    * Base class destructors are never inheritted, but are automatically called when derived class destructors are called. 

#include<iostream>

//Abstract class
class Pizza {
    public:
        virtual void preparePizza() const  = 0;
};

//  Concrete classes implementing Pizza class
class NYPizza : public Pizza {
    public:
        void preparePizza() const override {
            std::cout <<"Preparing NY style Pizza"<<std::endl;
        }
};

class ChicagoPizza : public Pizza {
    public:
        void preparePizza() const override{
            std::cout <<"Preparing Chicago style Pizza"<<std::endl;
        }
};


//Creator class abstract
class PizzaShop {
    public:
        virtual ~PizzaShop(){};
        virtual Pizza* createPizza() const = 0; //FactoryMethod
};

class NYPizzaShop : public PizzaShop {
    public:
        Pizza* createPizza() const override{
            return new NYPizza();
        }
};

class ChicagoPizzaShop : public PizzaShop {
    public:
        Pizza* createPizza() const override{
            return new ChicagoPizza();
        }
};

int main() {
    PizzaShop* nyPizzaShop = new NYPizzaShop();
    PizzaShop* chicagoPizzaShop = new ChicagoPizzaShop();
    
    Pizza* nyPizza = nyPizzaShop->createPizza();
    nyPizza->preparePizza();

    Pizza* chicagoPizza = chicagoPizzaShop->createPizza();
    chicagoPizza->preparePizza();

    delete nyPizzaShop;   
    delete chicagoPizzaShop;   
    delete nyPizza;   
    delete chicagoPizza;   
    return 0;
}

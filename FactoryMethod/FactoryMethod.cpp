#include<iostream>

//Abstract class
class Pizza {
    public:
        virtual void preparePizza() const  = 0;
        virtual void bakePizza() const  = 0;
        virtual void cutPizza() const  = 0;
        virtual void boxPizza() const  = 0;
};

//  Concrete classes implementing Pizza class
class NYPizza : public Pizza {
    public:
        void preparePizza() const override {
            std::cout <<"Preparing NY style Pizza"<<std::endl;
        }
        void bakePizza() const override {
            std::cout <<"Baking NY style Pizza"<<std::endl;
        }
        void cutPizza() const override {
            std::cout <<"Cutting NY style Pizza"<<std::endl;
        }
        void boxPizza() const override {
            std::cout <<"Boxing NY style Pizza"<<std::endl;
        }
};

class ChicagoPizza : public Pizza {
    public:
        void preparePizza() const override{
            std::cout <<"Preparing Chicago style Pizza"<<std::endl;
        }
        void bakePizza() const override {
            std::cout <<"Baking Chicago style Pizza"<<std::endl;
        }
        void cutPizza() const override {
            std::cout <<"Cutting Chicago style Pizza"<<std::endl;
        }
        void boxPizza() const override {
            std::cout <<"Boxing Chicago style Pizza"<<std::endl;
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
    nyPizza->bakePizza();
    nyPizza->cutPizza();
    nyPizza->boxPizza();

    Pizza* chicagoPizza = chicagoPizzaShop->createPizza();
    chicagoPizza->preparePizza();
    chicagoPizza->bakePizza();
    chicagoPizza->cutPizza();
    chicagoPizza->boxPizza();

    delete nyPizzaShop;   
    delete chicagoPizzaShop;   
    delete nyPizza;   
    delete chicagoPizza;   
    return 0;
}

/*
Simple Example of Singleton Design Pattern. This implementation is not thread safe and uses lazy initialization.
This pattern is useful if we want only one instance of an object to exist throughout the code. For example: Config, Registry settings.
*/

#include <iostream>

using namespace std;

class Singleton {
    private:
        Singleton() {
            val = "INITIALIZE";
        }
        static Singleton* singleton;
        std::string val;

    public:
        Singleton(Singleton &copy) = delete;
        void operator=(const Singleton&) = delete;

        static Singleton *GetInstance() ;

        std::string getVal() const{
            return val;
        }
        
};

Singleton* Singleton::singleton = NULL;

Singleton *Singleton::GetInstance() {
    if (singleton==NULL) {
        singleton = new Singleton();
    }
    return singleton;
}

int main(){
    Singleton *instance = Singleton::GetInstance();
    
    cout<<instance->getVal()<<endl;

    return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>

class ISubscriber {
  public:
    virtual void update() = 0;
};

class IPublisher {
  public:
    virtual void addSubscriber(ISubscriber* subscriber) = 0;
    virtual void removeSubscriber(ISubscriber* subscriber) = 0;
    virtual void notifySubscribers() =0;
};

class Newspaper : public IPublisher {
  public:
    void addSubscriber(ISubscriber* subscriber) {
        subscriberList.push_back(subscriber);
    }

    void removeSubscriber(ISubscriber* subscriber) {
        subscriberList.erase(std::remove(subscriberList.begin(), subscriberList.end(), subscriber), subscriberList.end());
    }
    void notifySubscribers() {   
        for (auto subscriber: subscriberList) {
            subscriber->update();
        }
    }
  private:
    std::vector<ISubscriber*> subscriberList;
};

class Subscriber : public ISubscriber {
  public:
    Subscriber(const std::string name) : name(name){
    }
    void update() {
        std::cout << "Subscriber " <<name<<" has been updated."<<std::endl;
    }
  private:
    std::string name;
};

int main() {
    IPublisher* newspaper = new Newspaper();
    ISubscriber* office = new Subscriber("Office");
    ISubscriber* library = new Subscriber("Library");

    newspaper->addSubscriber(office);
    newspaper->addSubscriber(library);
    newspaper->notifySubscribers();

    delete newspaper;
    delete office;
    delete library;

    return 0;
}

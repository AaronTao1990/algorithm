#import <stdio.h>

class Singleton
{
private:
    Singleton(){}
    static Singleton* instance;

public:
    static Singleton* getInstance();
};

Singleton* Singleton::instance =NULL;

Singleton* Singleton::getInstance()
{
    if(instance==NULL)
        instance=new Singleton();
    return instance;
}

int main() {
    Singleton::getInstance();
}

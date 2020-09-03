#include <stdlib.h>

struct A
{
    int a;
    int b;
};

struct A* getObject()
{
    static struct A *instance = NULL;

    // do lock here
    if(instance == NULL)
    {
        instance = malloc(sizeof(*instance));
        instance->a = 1;
        instance->b = 2;
    }
    // do unlock

    return instance;
};

int main(){
	
}

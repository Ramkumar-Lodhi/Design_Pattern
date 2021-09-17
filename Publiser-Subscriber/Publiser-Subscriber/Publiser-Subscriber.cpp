
#include <iostream>
#include "Ipublisher.h"
#include "Weather.h"
#include "Laptop.h"
#include "Mobile.h"
#include "Tablet.h"

int main()
{
    ISubscriber* s1 = new Mobile();
    ISubscriber* s2 = new Laptop();
    ISubscriber* s3 = new Tablet();
    IPublisher* client = new Weather();
    if (client) {
        client->Register(s1);
        client->Register(s2);
        client->Register(s3);

        client->setWeatherInfo(21.0f, 13.0f);

        client->Delete(s2);

        client->setWeatherInfo(12.0f, 14.0f);

        client->Delete(s2);
    }

}

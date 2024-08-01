#include<iostream>
#include<C:\Users\Palak Gada\OneDrive\Documents\PPS MAJOR PROJECT\json.hpp>
#include<fstream>

using namespace std;
using json=nlohmann::json;

int main()
{
    ifstream f("pps.json");
    json data=json::parse(f);

    for(int i=0;i<100;i++)
    {
        string name = data[i]("name");    }
    for(int i=0;i<100;i++)
    {

        cout<<data[i].("name");
    }


}

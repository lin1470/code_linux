#include "Sale_data.h"
#include<string>
#include<iostream>
using namespace std;

Sale_data::Sale_data()
{
    //ctor
    string bookNo;
    unsigned units_sold=0;
    double revenue=0.0;
    string isbn()const {return bookNo;}
    Sale_data& combine(const Sales_data&);
    double avg_price() const;
}

Sales_data add(const Sale_data&,const Sales_data&);
ostream &print(ostream&,const Sale_data&);
istream &read(istream&,const Sale_data&);
Sale_data::~Sale_data()
{
    //dtor
}

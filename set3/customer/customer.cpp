#include <iostream>
#include"customer.h"
#include"prepaid.h"
#include"postpaid.h"

using namespace std;

    CustomerBase::CustomerBase():
        m_custId(""),m_custName(""),m_phone(""),m_balance(0){}

    CustomerBase::CustomerBase(string custId,string custName,string phone,double balance):
        m_custId(custId),m_custName(custName),m_phone(phone),m_balance(balance) {}

    CustomerBase::CustomerBase(string custId,string custName,string phone):
        m_custId(custId),m_custName(custName),m_phone(phone),m_balance(0){}

    CustomerBase::CustomerBase(const CustomerBase &ref):
        m_custId(ref.m_custId),m_custName(ref.m_custName),m_phone(ref.m_phone),m_balance(ref.m_balance){}


    PrepaidCustomer::PrepaidCustomer():
        CustomerBase(){}

    PrepaidCustomer::PrepaidCustomer(string custId,string custName,string phone,double balance):
        CustomerBase(custId,custName,phone,balance){}

    PrepaidCustomer::PrepaidCustomer(string custId,string custName,string phone):
        CustomerBase(custId,custName,phone){}


    PostpaidCustomer::PostpaidCustomer():
        CustomerBase(){}

    PostpaidCustomer::PostpaidCustomer(string custId,string custName,string phone,double balance,int billdate):
        CustomerBase(custId,custName,phone,balance),m_billDate{billdate}{}

    PostpaidCustomer::PostpaidCustomer(string custId,string custName,string phone):
        CustomerBase(custId,custName,phone) {}

    void CustomerBase::dispay()const
    {
        cout<<m_custId<<endl;
        cout<<m_custName<<endl;
        cout<<m_phone<<endl;
        cout<<m_balance<<endl;
    }
    void PostpaidCustomer::dispay() const{
    cout<<"Postpaid Customer\nBill due on "<<m_billDate<<endl;}

    void PostpaidCustomer::billPay(double i){
        postpaidbill(i);
        cout<<"Bill Paid\n";}

    void CustomerBase::postpaidbill(double amnt){
    m_balance-=amnt;
    }

    void PrepaidCustomer::dispay() const{
    cout<<"Prepaid Customer\n";}

    double CustomerBase::getBalance() const
    {
        cout<<m_balance<<endl;
        return m_balance;
    }
   void CustomerBase::credit(double amnt)
    {
         m_balance+=amnt;
    }
   void CustomerBase::makeCall(double amnt)
    {
        cout<<"Calling"<<"\n";
        m_balance=m_balance-(amnt);
    }

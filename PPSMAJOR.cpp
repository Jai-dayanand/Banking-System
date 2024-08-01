#include <iostream>
#include "json.hpp"
#include <fstream>

using namespace std;
using json = nlohmann::json;

class Bank
{
    private:
        string firstname;
        string lastname;
        string accpass;
        string acctype;
        long int balance;

        long int accnofinal;
        string passfinal;

    public:
        void newacc()    // Creates a new account
        {
            cout<<"ENTER THE FIRST NAME : ";
            cin>>firstname;
            cout<<"ENTER THE LAST NAME : ";
            cin>>lastname;
            cout<<"CREATE A PASSWORD: ";
            cin>>accpass;
            cout<<"ENTER THE TYPE OF ACCOUNT: ";
            cin>>acctype;
            cout<<"ENTER THE DEPOSIT AMOUNT: ";
            cin>>balance;

            cout<<"\n=> GLAD TO HAVE YOU WITH US <=\n"<<endl;

            checkdisplay();
            //make a new object in json and access random data as customer id and new account number from there.
        }

        void checkdisplay()    // Displays the new account
        {
            int t;
            cout<<"=> DO YOU WANT TO DISPLAY YOUR ACCOUNT ?<="<<endl;   // Asks the new user if he/she wants to access the new account created
            cout<<"=> ENTER 1 TO ACCESS <="<<endl;                      // If user enters 1, the rest of the code in function gets executed
            cout<<"=> ENTER ANY KEY TO EXIT <="<<endl;                  // If any other key is entered, it exits the function
            cin>>t;
            cout<<endl;

            ifstream me("PPSMAJOR.json");   // data from "Bank data" json file is copied in file "me"
            json data = json::parse(me);     // the data from file "me" is stored in "data" json
            if(t==1)
            {
                cout<<"\n\nWHAT DO YOU WANT TO DISPLAY? \n1.DISPLAY ALL.\n2.ACCOUNT NUMBER.\n3.NAME.\n4.CUSTOMER ID. \n5.BALANCE. \n6.ACCOUNT TYPE. \n7.EXIT. "<<endl;
                int op,ct=1;
                string ask;

                while(ct==1)        // Loops until the user selects "EXIT"
                {
                    cout<<"ENTER THE NUMERIC OF WHAT YOU WANT TO DISPLAY: ";  //asks the user what he wants to display
                    cin>>op;

                    switch(op)
                    {
                        case 1:         //displays all the details
                        {
                            cout<<"THE ACCOUNT NUMBER IS : ";
                            cout<<data["Account holder 6"]["Account Number"];
                            cout<<endl;
                            cout<<"THE NAME OF THE USER IS :"<<firstname<<" "<<lastname<<endl;
                            cout<<"THE CUSTOMER ID IS : ";
                            cout<<data["Account holder 6"]["Customer ID"];
                            cout<<endl;
                            cout<<"THE ACCOUNT TYPE IS :"<<acctype;
                            cout<<endl;
                            cout<<"THE BALANCE AMOUNT IS :"<<balance;
                            cout<<endl;

                            cout<<"Do you want to display anything else?";
                            cin>>ask;
                            break;
                        }

                        case 2:         //displays account number
                        {
                            cout<<"THE ACCOUNT NUMBER IS : ";
                            cout<<data["Account holder 6"]["Account Number"];
                            cout<<endl;

                            cout<<"Do you want to display anything else?";
                            cin>>ask;
                            break;
                        }
                        case 3:         //displays account holder name
                        {
                            cout<<"THE NAME OF THE USER IS : "<<firstname<<" "<<lastname<<endl;

                            cout<<"Do you want to display anything else?";
                            cin>>ask;
                            break;
                        }
                        case 4:         //displays customer ID
                        {
                            cout<<"THE CUSTOMER ID IS : ";
                            cout<<data["Account holder 6"]["Customer ID"];
                            cout<<endl;

                            cout<<"Do you want to display anything else?";
                            cin>>ask;
                            break;
                        }
                        case 5:         //displays balance in the account
                        {
                            cout<<"THE BALANCE AMOUNT IS :"<<balance;
                            cout<<endl;

                            cout<<"Do you want to display anything else?";
                            cin>>ask;
                            break;
                        }
                        case 6:         //displays the type of account
                        {
                            cout<<"THE ACCOUNT TYPE IS :"<<acctype;
                            cout<<endl;

                            cout<<"Do you want to display anything else?";
                            cin>>ask;
                            break;
                        }
                        case 7:         //exits
                        {
                            cout<<"HAVE A NICE DAY. "<<endl;
                            ct=0;
                            break;
                        }
                        default:
                        {
                            cout<<"Enter a valid numeric!"<<endl;
                            ct=1;
                        }
                    }

                    //Condition for looping
                    if (ask=="yes")         //if user enters "yes" to display something else then next iteration continues
                        continue;
                    else if (ask=="no")     //if user enters "no" to display something else then loop ends
                    {
                        cout<<"HAVE A NICE DAY.";
                        break;
                    }
                    else if (ct==0)
                        break;
                    else if (ct==1)
                        continue;
                    else
                    {
                        cout<<"HAVE A NICE DAY.";
                        break;
                    }
                }
            }
            else
            {
                cout<<"HAVE A NICE DAY.";
            }
        }
        void existingacc()
        {
        ifstream me("PPSMAJOR.json");
        json data = json::parse(me);

        int ct1=1;
        while(ct1<4)
        {
          cout<<"ENTER THE ACCOUNT NUMBER :";
          cin>>accnofinal;
          cout<<"ENTER THE PASSWORD :";
          cin>>passfinal;
          cout<<endl;

          if(accnofinal==96997580 && passfinal == "tan_c.410")
          {
              cout<<"THE NAME OF THE ACCOUNT HOLDER IS :";
              cout<<data["Account holder 1"]["Name"];
              cout<<endl;
              cout<<"THE CUSTOMER ID OF THE ACCOUNT HOLDER IS :";
              cout<<data["Account holder 1"]["Customer ID"];
              cout<<endl;
              cout<<"THE ACCOUNT TYPE IS :";
              cout<<data["Account holder 1"]["Account type"];
              cout<<endl;
              cout<<"THE BALANCE AMOUNT IS :";
              cout<<data["Account holder 1"]["Balance"];
              cout<<endl;
              break;
          }
          else if(accnofinal==96997581 && passfinal == "jai_d.230")
          {
            cout<<"THE NAME OF THE ACCOUNT HOLDER IS :";
            cout<<data["Account holder 2"]["Name"];
            cout<<endl;
            cout<<"THE CUSTOMER ID OF THE ACCOUNT HOLDER IS :";
            cout<<data["Account holder 2"]["Customer ID"];
            cout<<endl;
            cout<<"THE ACCOUNT TYPE IS :";
            cout<<data["Account holder 2"]["Account type"];
            cout<<endl;
            cout<<"THE BALANCE AMOUNT IS :";
            cout<<data["Account holder 2"]["Balance"];
            cout<<endl;
            break;
          }
          else if(accnofinal==96997582 && passfinal == "pal_g.687")
          {
            cout<<"THE NAME OF THE ACCOUNT HOLDER IS :";
            cout<<data["Account holder 3"]["Name"];
            cout<<endl;
            cout<<"THE CUSTOMER ID OF THE ACCOUNT HOLDER IS :";
            cout<<data["Account holder 3"]["Customer ID"];
            cout<<endl;
            cout<<"THE ACCOUNT TYPE IS :";
            cout<<data["Account holder 3"]["Account type"];
            cout<<endl;
            cout<<"THE BALANCE AMOUNT IS :";
            cout<<data["Account holder 3"]["Balance"];
            cout<<endl;
            break;
          }
          else if (accnofinal==96997583 && passfinal =="kam_m.123")
          {
            cout<<"THE NAME OF THE ACCOUNT HOLDER IS :";
            cout<<data["Account holder 4"]["Name"];
            cout<<endl;
            cout<<"THE CUSTOMER ID OF THE ACCOUNT HOLDER IS :";
            cout<<data["Account holder 4"]["Customer ID"];
            cout<<endl;
            cout<<"THE ACCOUNT TYPE IS :";
            cout<<data["Account holder 4"]["Account type"];
            cout<<endl;
            cout<<"THE BALANCE AMOUNT IS :";
            cout<<data["Account holder 4"]["Balance"];
            cout<<endl;
            break;
          }
          else if(accnofinal==96997584 && passfinal == "tis_b.587")
          {
            cout<<"THE NAME OF THE ACCOUNT HOLDER IS :";
            cout<<data["Account holder 5"]["Name"];
            cout<<endl;
            cout<<"THE CUSTOMER ID OF THE ACCOUNT HOLDER IS :";
            cout<<data["Account holder 5"]["Customer ID"];
            cout<<endl;
            cout<<"THE ACCOUNT TYPE IS :";
            cout<<data["Account holder 5"]["Account type"];
            cout<<endl;
            cout<<"THE BALANCE AMOUNT IS :";
            cout<<data["Account holder 5"]["Balance"];
            cout<<endl;
            break;
          }
          else
          {
            ct1++;
            cout<<"PLease re-enter login details!\n";
          }
        }
        if (ct1==4)
          cout<<"YOU HAVE REACHED THE MAXIMUM LIMIT TO LOGIN!\n";
        }

  };

  int main()
  {


    cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"-------------------------------------------WELCOME TO THE BANK------------------------------------------"<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
    Bank obj;
    int option;
    cout<<endl<<endl;
    cout<<"=> DO YOU WANT TO ACCESS YOUR EXISTING ACCOUINT OR MAKE A NEW ONE <=";
    cout<<"\n1.EXISTING ACCOUNT.\n2.NEW ACCOUNT."<<endl;
    cin>>option;
    cout<<endl;

    switch(option)
    {
      case 1:
      {
        obj.existingacc();
        break;
      }
      case 2:
      {
        obj.newacc();
        break;
      }
      default:
      {
        cout<<"INVALID DETAIL."<<endl;
        cout<<"HAVE A NICE DAY";
        break;
      }
    }
  }

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <iomanip>
#include <list>


using namespace std;

const int n = 5; //Number of items in menu

const string items[n] = {"Chicken Burger","Beef Burger","CLub Sandwich","Chicken Nuggets","Anday Wala Burger"};

const double UnitPrice[n]= {495, 575, 325, 95, 69}; //Price of single items.

int orderTemp[n] = {0,0,0,0,0}; //Stores the number of items for one instance of an order and adds to num[] array.

int num[n] = {0,0,0,0,0};	//Stores the number of items ordered by one customer

double cost[n] = {0,0,0,0,0}; //Price of the number of items ordered

const float gst = 0.16;

void takeOrder();
void displayOrder();	//Displays what the customer has ordered along with their price.
void resetVariables();
void printByLetter(string a, int wait); //Pointless function

long total;			//The total bill of an order.

int method;

int cust_id = 1;	//For User Interface
int cust_no;		//For arrays. = cust_id - 1.
bool keepRunning = true;	//variable to control the outermost loop to keep the program running
int order, orderMore;		//control the the inner loop and allows to run it again to add items to order as well as the choice of the customer.
string orderMoreInp;							

//analytics:
int itemsSold[5] = {0,0,0,0,0};	//total number of items sold for all orders yet
//double totalSales[10];		//total earnings per order.
list<float> totalSales; 		//List
double totalSales_analytics;	//total earnings overall

void analytics();				//Displays analytics

string dateAndtime[10];			//Stores date and time as string for every order
list<string> dateAndTime;

time_t now = time(0);			//For calculating time
string now2 = ctime(&now);		//ANd converting to string



int main() //MAIN
{
	
while(keepRunning)
{
	//reset & cust_no++	
	resetVariables();
  //-------------------------------
       
         
	while (order != 0 && orderMore !=0)
	{
	
		takeOrder();

       	system("CLS");
		if(order!=0)
		{
			
			displayOrder();
		
			do{
		
				cout<<"\n\nWould you like to order anything else? :";
				cin>>orderMoreInp;
				
				if(orderMoreInp == "Yes" || orderMoreInp == "yes" || orderMoreInp == "YES" || orderMoreInp == "y" || orderMoreInp == "Y")
				{
					orderMore = 1;
				}
				else if(orderMoreInp == "No" || orderMoreInp == "no" || orderMoreInp == "No" || orderMoreInp == "n" || orderMoreInp == "N")
				{
					orderMore = 0;
				}
				else
				{
					orderMore = 3;
					cout<<"Please enter a valid response\n";
				}

			}while(orderMore!= 0 && orderMore != 1 );
		
		}
	
	
	}		

	//billing

	for(int i=0; i<5; i++)
	{
		total = total + cost[i]; 
	}



	if(total != 0)
	{
		//totalSales[cust_no] = total;
		totalSales.push_back(total);
	}

	{ //DisplayBill
	
		cout<<"\nYour total would be \n\n";
		printByLetter("... \n", 170);
		cout<<total<<" Rs/- + "<<gst*100<<"% GST = ";
		printByLetter(".....",100);
		cout<<"\b\b\b\b\b "<<total+ gst*total<<" Rs /-"<<endl;
	}
	
	//store data for analytics
	for(int i=0; i<5; i++)
	{
		itemsSold[i] += num[i]; 
	}

	Sleep(200);

	if(total!=0)
	{

		do{

			cout<<"\nWould you like to pay cash or by card (1 or 2)? :";
			cin>>method;

			switch(method)
			{
				case 1:
					cout<<"\nThank you! Come back again";
					break;
	
				case 2:
					cout<<"\nInsert your card and ";
					system("pause");	
					break;
				default: 
					cout<<"Enter a valid option";	
			}
	
		}while(method!=1 && method!=2);

//Store date and time of the order and transaction
		{
		now = time(0);
		now2 = ctime(&now);
		dateAndtime[cust_no] = now2;
		}
	}

	//NewOrder
	do
	{

		cout<<"\n\nPress 1 for new order, 0 to open analytics: ";
		cin>>keepRunning;
		if(keepRunning == 0)
		{
			analytics();	
		}
		else if(keepRunning ==1 && total!=0)
		{
		cust_id++;	
		}
	
	}while(keepRunning != 1);


	}

getch();

return 0;

}//End of Main FUnction

//Prototypes 

void takeOrder()
{
	system("CLS");
		cout<<setw(60)<<"Customer_ID: "<<cust_id<<endl;
		cout<<"-------------------MENU-------------------\n\n";
		Sleep(100);
    	cout <<"\n [1] Chicken Burger\t\t495 Rs/- \n";
    	Sleep(100);
    	cout<<"\n [2] Beef Burger\t\t575 Rs/- \n";
    	Sleep(100);
		cout<<"\n [3] Club Sandwich\t\t325 Rs/- \n";
		Sleep(100);
 		cout<<"\n [4] Chicken Nuggets\t\t95  Rs/- \n";
 		Sleep(100);
		cout<<"\n [5] Anday wala burger\t\t69 Rs/- \n";

		do{
	
		cout<<"\nFrom The List Of Items, What Would You Like?: ";
		cin>>order;
		
		if(order<=5 && order>=0)
		{
		
			if(order != 0)
			{
			int	_i = order - 1;
		
		
			cout<<"How many "<<items[_i]<<" would you like to order: ";
			cin>>orderTemp[_i];
			num[_i] = num[_i] + orderTemp[_i];
			cost[_i] = UnitPrice[_i] * num[_i];
			}
		}
		else
		{
			cout<<"Please enter a valid option."<<endl<<endl;
		}
		
		/*switch(order)	
			{
                
                case 0:
                break;
                
				case 1:
                     
                cout<<"\nHow Many Chicken Burgers Would You Like To Order: ";
                        cin>>orderTemp[0];
                		num[0] = num[0] + orderTemp[0];
                		cost[0] = UnitPrice[0] * num[0];
                break;
                     
				case 2: 
                cout<<"\nHow Many Beef Burgers Would You Like To Order: ";
				         cin>>orderTemp[1];
               			num[1] = num[1] + orderTemp[1];
                		cost[1]= UnitPrice[1] * num[1];
                break;
                
                
                case 3: 
                cout<<"\nHow Many Club Sandwiches Would You Like To Order: ";
                         cin>>orderTemp[2];
                		num[2] = num[2] + orderTemp[2];
                		cost[2]= UnitPrice[2] * num[2];
                break;
                
                
                 
                case 4: 
                cout<<"\nHow Many Chicken Nuggets Would You Like To Order: ";
                         cin>>orderTemp[3];
                		num[3] = num[3] + orderTemp[3];
                		cost[3]= UnitPrice[3] * num[3];
                break;
                
                
                
                case 5: 
                cout<<"\nHow Many Anday Walay Burgers Would You Like To Order: ";
                         cin>>orderTemp[4];
                        num[4] = num[4] + orderTemp[4];
                		cost[4]= UnitPrice[4] * num[4]; 
                break;
                
                
                default: cout<<"Please Choose A Valid Item From Our List\n";
                }*/   
         }while(order < 0 || order > 5);
}


void analytics()
{
	system("CLS");
/*	for(int i=0; i<10; i++)
	{
		
		totalSales_analytics+= totalSales[i];
	}
	
	cout<<"Total sales of the day:\n"<<endl;
	for(int i=0; i<10; i++)
	{
			if(totalSales[i] == 0){
			break;
		}
		cout<<i+1<<") "<<totalSales[i]<<"Rs /-  "<<dateAndtime[i]<<endl;
		Sleep(150);
	}
	cout<<"Total = "<<totalSales_analytics<<" Rs /-"<<endl;
	*/
	
	list<float>::iterator it = totalSales.begin();
    for(int i=0; i<totalSales.size(); i++)
	{	
        cout<<*it<<endl;
        ++it;
    }
	
	cout<<"\nITEM"<<setw(25)<<right<<"\tSOLD"<<setw(30)<<right<<"Earnings"<<endl<<endl;
	Sleep(300);
	cout<<"Chicken Burger\t"<<setw(17)<<right<<itemsSold[0]<<setw(30)<<right<<itemsSold[0]*UnitPrice[0]<<endl;
	Sleep(100);
	cout<<"Beef Burger\t"<<setw(17)<<right<<itemsSold[1]<<setw(30)<<right<<itemsSold[1]*UnitPrice[1]<<endl;
	Sleep(100);
	cout<<"Club Sandwich\t"<<setw(17)<<right<<itemsSold[2]<<setw(30)<<right<<itemsSold[2]*UnitPrice[2]<<endl;
	Sleep(100);
	cout<<"Chicken Nuggets\t"<<setw(17)<<right<<itemsSold[3]<<setw(30)<<right<<itemsSold[3]*UnitPrice[3]<<endl;
	Sleep(100);
	cout<<"Anday wala burger"<<setw(16)<<right<<itemsSold[4]<<setw(30)<<right<<itemsSold[4]*UnitPrice[4]<<endl<<endl;
	
	system("pause");
	system("CLS");
			
	 
}



void displayOrder()
{
	cout<<"You Have Ordered:\n\n";
	
	cout<<left<<setw(15)<<"ITEM"<<right<<setw(10)<<"QUANTITY"<<right<<setw(15)<<"UNIT PRICE"<<right<<setw(20)<<"PRICE\n";
	cout<<"--------------------------------------------------------------";

	cout<<"\n"<<items[0]<<":\t"<<setw(7)<<right<< num[0] <<setw(16)<<right<< UnitPrice[0] <<setw(20) <<right<<cost[0]<<endl;
	Sleep(100);
	cout<<items[1]<<":\t"<<setw(7)<<right<< num[1] <<setw(16)<<right<< UnitPrice[1] <<setw(20) <<right<<cost[1]<<endl;
	Sleep(100);
	cout<<items[2]<<":\t"<<setw(7)<<right<< num[2] <<setw(16)<<right<<UnitPrice[2] <<setw(20) <<right<<cost[2]<<endl;
	Sleep(100);
	cout<<items[3]<<":"<<setw(7)<<right<< num[3] <<setw(16)<<right<< UnitPrice[3]<<setw(20) <<right<<cost[3]<<endl;
	Sleep(100);
	cout<<items[4]<<":"<<setw(5)<<right<< num[4] <<setw(16)<<right<< UnitPrice[4] <<setw(20) <<right<<cost[4]<<endl;
}

void resetVariables()
{
	cust_no = cust_id - 1;
	string orderMoreInp;
	order = 1, orderMore = 1;
	total = 0;
	
	
	for(int i = 0; i<5; i++)
	{
	num[i] = 0;
	cost[i] = 0;
	}
}

void printByLetter(string a, int wait)
{
	for(int i=0; i<a.size(); i++)
	{
		cout<<a[i];
		Sleep(wait);
	}	
}


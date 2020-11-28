#include "headers.h"

using namespace std;

#include "prototypes.h"
#include "classes.h"
#include "functions.h"

int main()
{
	int choice,emp_type,emp_no,da,hra,ma,ptax;
	Permanent_Employee per;
	Contractual_Employee con;
	while(1)
	{
		getch();
		system("cls");
		cout<<endl;
		cout<<"::::::::::::::::::::::::::MENU::::::::::::::::::::::::::::"<<endl;
		cout<<"1. NEW EMPLOYEE"<<endl;
		cout<<"2. GENERATE PAY-SLIP"<<endl;
		cout<<"3. SET DEARNESS ALLOWANCE (DA) RATE"<<endl;
		cout<<"4. SET HOUSE RENTAL ALLOWANCE (HRA) RATE"<<endl;
		cout<<"5. SET MEDICAL ALLOWANCE (MA)"<<endl;
		cout<<"6. SET PROFESSIONAL TAX"<<endl;
		cout<<"7. DISPLAY DETAILS OF AN EMPLOYEE"<<endl;
		cout<<"8. OVER-TIME DUES OF ALL EMPLOYEES"<<endl;
		cout<<"9. QUIT"<<endl;
		cout<<"Enter your choice : ";
		cin>>choice;
		system("cls");
		switch(choice)
		{
			case 1:
				cout<<endl;
				cout<<"1. PERMANENT EMPLOYEE"<<endl;
				cout<<"2. CONTRACTUAL EMPLOYEE"<<endl;
				cout<<"Enter the Employee Type : ";
				cin>>emp_type;
				switch(emp_type)
				{
					case 1:
						per.getData();
						per.store_in_file();
						break;
					case 2:
						con.getData();
						con.store_in_file();
						break;
				}
				break;
			case 2:
				cout<<endl;
				cout<<"1. PERMANENT EMPLOYEE"<<endl;
				cout<<"2. CONTRACTUAL EMPLOYEE"<<endl;
				cout<<"Enter the Employee Type : ";
				cin>>emp_type;
				switch(emp_type)
				{
					case 1:
						cout<<"Enter the Employee Number : ";
						cin>>emp_no;
						if(search(emp_no,&per)==0)
						{
							cout<<"Invalid Employee Number"<<endl;
						}
						else
						{
							generate_pay_slip(per);
						}
						break;
					case 2:
						cout<<"Enter the Employee Number : ";
						cin>>emp_no;
						if(search(emp_no,&con)==0)
						{
							cout<<"Invalid Employee Number"<<endl;
						}
						else
						{
							generate_pay_slip(con);
						}
						break;
					default:
						cout<<"Wrong Type"<<endl;
						break;
				}
				break;
			case 3:
				cout<<"Enter New Dearness Allowance Rate : ";
				cin>>da;
				set_da_rate(da);
				break;
			case 4:
				cout<<"Enter New House Rental Allowance Rate : ";
				cin>>hra;
				set_hra_rate(hra);
				break;
			case 5:
				cout<<"Enter New Medical Allowance : ";
				cin>>ma;
				set_ma(ma);
				break;
			case 6:
				cout<<"Enter New Professional Tax : ";
				cin>>ptax;
				set_ptax(ptax);
				break;
			case 7:
				cout<<endl;
				cout<<"1. PERMANENT EMPLOYEE"<<endl;
				cout<<"2. CONTRACTUAL EMPLOYEE"<<endl;
				cout<<"Enter the Employee Type : ";
				cin>>emp_type;
				switch(emp_type)
				{
					case 1:
						cout<<"Enter the Employee Number : ";
						cin>>emp_no;
						if(search(emp_no,&per)==0)
						{
							cout<<"Invalid Employee Number"<<endl;
						}
						else
						{
							per.displayData();
						}
						break;
					case 2:
						cout<<"Enter the Employee Number : ";
						cin>>emp_no;
						if(search(emp_no,&con)==0)
						{
							cout<<"Invalid Employee Number"<<endl;
						}
						else
						{
							con.displayData();
						}
						break;
					default:
						cout<<"Wrong Type"<<endl;
						break;
				}
				break;
			case 8:
				compute_OT();
				break;
			case 9:
				cout<<"THANKS FOR USING!"<<endl;
				getch();
				exit(0);
			default:
				cout<<"WRONG CHOICE!!!"<<endl;
				cout<<"TRY AGAIN..."<<endl;
				break;
		}
	}
	return 0;
}

//************************************************************
//************************************************************
						//CLASSES
//************************************************************
//************************************************************




//************************************************************
					  //Employee Class
//************************************************************

class Employee
{
	protected:
		int emp_no;//Employee ID
		char emp_name[40];//Employee's Name
		char emp_add[100];//Employee's Address
		char emp_dep[30];//Employee's Department
		char emp_desg[30];//Employee's Designation
	public:
		void getData();
		void displayData();
};

//Definition of functions of Employee Class

void Employee::getData()
{
	emp_no = get_emp_no();
	cout<<"Enter the name of employee: ";
	cin>>emp_name;
	cout<<"Enter the address of the Employee: ";
	cin>>emp_add;
	cout<<"Enter the Department of Employee: ";
	cin>>emp_dep;
	cout<<"Enter the Designation of Employee: ";
	cin>>emp_desg;
}


void Employee::displayData()
{
	cout<<"Employee ID: "<<emp_no<<endl;
	cout<<"Employee Name: "<<emp_name<<endl;
	cout<<"Employee Address: "<<emp_add<<endl;
	cout<<"Employee Department: "<<emp_dep<<endl;
	cout<<"Employee Designation: "<<emp_desg<<endl;
}


//************************************************************
					//End of Employee Class
//************************************************************



//************************************************************
					//Permanent Employee Class
//************************************************************


class Permanent_Employee : public Employee//Child class of Employee Class
{
	private:
		char emp_type[20];//Employee Type
		long int emp_basic;//Basic Salary of Employee
		long int emp_da;//Dearness Allowance
		long int emp_hra;//House Rental Allowance
		long int emp_ma;//Medical Allowance
		long int emp_pf;//Provident Fund
		long int ptax;//Professional Tax
		long int itax;//Income Tax
		long int gross;//Gross Salary
		long int net;//Net Salary
	public:
		void getData();//Over-ridden Function
		void displayData();//Over-ridden Function
		void calculate();
		void store_in_file();
		friend int search(int emp_no , Permanent_Employee *per);
		friend void generate_pay_slip(Permanent_Employee per);
		friend void compute_OT();
};


//Definition of Functions of Permanent Employee Class


void Permanent_Employee :: getData()
{
	Employee::getData();
	try//Exception Handling for negative basic salary
	{
		cout<<"Enter the basic Salary of the Employee : ";
		cin>>emp_basic;
		if(emp_basic<0)
		{
			throw emp_basic;
		}
	}
	catch(...)
	{
		cout<<"\nBasic Salary should be positive\n";
		return;
	}
	try//Exception Handling for negative income tax
	{
		cout<<"Enter the Income Tax to be deducted : ";
		cin>>itax;
		if(itax<0)
		{
			throw itax;
		}
	}
	catch(...)
	{
		cout<<"\nIncome Tax should be positive\n";
		return;
	}
	calculate();
}

void Permanent_Employee::calculate()
{
	strcpy(emp_type,"Permanent");
	int da,hra;
	da = get_da_rate();
	emp_da = (emp_basic * da)/100;
	hra = get_hra_rate();
	emp_hra = (emp_basic * hra)/100;
	emp_ma = get_ma();
	emp_pf = ((emp_basic + emp_da) * 12)/100;
	ptax = get_ptax();
	gross = emp_basic + emp_da + emp_hra + emp_ma ;
	net = gross - itax - emp_pf - ptax;
}

void Permanent_Employee::displayData()
{
	Employee::displayData();
	cout<<"Employee Type : "<<emp_type<<endl;
	cout<<"Basic Salary of Employee : "<<emp_basic<<endl;
	cout<<"Dearness Allowance : "<<emp_da<<endl;
	cout<<"House Rental Allowance : "<<emp_hra<<endl;
	cout<<"Medical Allowance : "<<emp_ma<<endl;
	cout<<"Provident Fund : "<<emp_pf<<endl;
	cout<<"Professional Tax : "<<ptax<<endl;
	cout<<"Income Tax : "<<itax<<endl;
	cout<<"Gross Salary of Employee : "<<gross<<endl;
	cout<<"Net Salary of Employee : "<<net<<endl;
}

void Permanent_Employee::store_in_file()
{
	ofstream outfile;
	outfile.open("Per_Emp",ios::app);//File opened in append mode
	outfile<<emp_no<<endl;
	outfile<<emp_name<<endl;
	outfile<<emp_add<<endl;
	outfile<<emp_dep<<endl;
	outfile<<emp_desg<<endl;
	outfile<<emp_type<<endl;
	outfile<<emp_basic<<endl;
	outfile<<emp_da<<endl;
	outfile<<emp_hra<<endl;
	outfile<<emp_ma<<endl;
	outfile<<emp_pf<<endl;
	outfile<<ptax<<endl;
	outfile<<itax<<endl;
	outfile<<gross<<endl;
	outfile<<net<<endl;
	outfile.close();
}



//************************************************************
				//End of Permanent Employee Class
//************************************************************



//************************************************************
				//Contractual Employee Class
//************************************************************


class Contractual_Employee : public Employee
{
	private:
		char emp_type[20];
		long int ptax;
		long int itax;
		long int gross;
		long int net;
	public:
		void getData();//Over-ridden Function
		void displayData();//Over-ridden Function
		void calculate();
		void store_in_file();
		friend int search(int emp_no, Contractual_Employee *con);
		friend void generate_pay_slip(Contractual_Employee con);
		friend void compute_OT();
};


//Defintion of Functions of Contractual Class


void Contractual_Employee::getData()
{
	Employee::getData();
	try
	{
		cout<<"Enter the Gross Salary : ";
		cin>>gross;
		if(gross<0)
		{
			throw gross;
		}
	}
	catch(...)
	{
		cout<<"Gross Salary should be positive"<<endl;
		return ;
	}
	try
	{
		cout<<"Enter the Income Tax to be deducted : ";
		cin>>itax;
		if(itax<0)
		{
			throw itax;
		}
	}
	catch(...)
	{
		cout<<"Income Tax should be positive"<<endl;
		return ;
	}
	calculate();
}


void Contractual_Employee::calculate()
{
	strcpy(emp_type,"Contractual");
	ptax = get_ptax();
	net = gross - ptax - itax;
}

void Contractual_Employee::displayData()
{
	Employee::displayData();
	cout<<"Employee Type : "<<emp_type<<endl;
	cout<<"Professional Tax : "<<ptax<<endl;
	cout<<"Income Tax : "<<itax<<endl;
	cout<<"Gross Salary of Employee : "<<gross<<endl;
	cout<<"Net Salary of Employee : "<<net<<endl;
}


void Contractual_Employee::store_in_file()
{
	ofstream outfile;
	outfile.open("Cont_Emp",ios::app);//Open file in append mode
	outfile<<emp_no<<endl;
	outfile<<emp_name<<endl;
	outfile<<emp_add<<endl;
	outfile<<emp_dep<<endl;
	outfile<<emp_desg<<endl;
	outfile<<emp_type<<endl;
	outfile<<ptax<<endl;
	outfile<<itax<<endl;
	outfile<<gross<<endl;
	outfile<<net<<endl;
	outfile.close();
}


//************************************************************
				//End of Contractual Employee Class
//************************************************************

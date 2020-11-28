//********************************************************************
//********************************************************************
						//Other Functions
//********************************************************************
//********************************************************************


//********************************************************************
						//Search Functions
//********************************************************************


//Function of finding an employee details of Permanent Type

int search(int emp_no, Permanent_Employee *per)
{
	Permanent_Employee p;
	ifstream infile;
	infile.open("Per_Emp");
	if(!infile.fail())
	{
		while(!infile.eof())
		{
			infile>>p.emp_no;
			infile>>p.emp_name;
			infile>>p.emp_add;
			infile>>p.emp_dep;
			infile>>p.emp_desg;
			infile>>p.emp_type;
			infile>>p.emp_basic;
			infile>>p.emp_da;
			infile>>p.emp_hra;
			infile>>p.emp_ma;
			infile>>p.emp_pf;
			infile>>p.ptax;
			infile>>p.itax;
			infile>>p.gross;
			infile>>p.net;
			if(emp_no == p.emp_no)
			{
				*per = p;
				infile.close();
				return 1;//If employee is present in the list
			}
		}
	}
	infile.close();
	return 0;//If employee is not present in the list
}

//Function of finding an employee details of Contractual type

int search(int emp_no, Contractual_Employee *con)
{
	ifstream infile;
	Contractual_Employee e;
	infile.open("Cont_Emp");
	if(!infile.fail())
	{
		while(!infile.eof())
		{
			infile>>e.emp_no;
			infile>>e.emp_name;
			infile>>e.emp_add;
			infile>>e.emp_dep;
			infile>>e.emp_desg;
			infile>>e.emp_type;
			infile>>e.ptax;
			infile>>e.itax;
			infile>>e.gross;
			infile>>e.net;
			if(emp_no == e.emp_no)
			{
                *con = e;
				infile.close();
				return 1;//If employee is present in the list
			}
		}
	}
	infile.close();
	return 0;//If employee is not present in the list
}

//********************************************************************
					//PaySlip Generation Functions
//********************************************************************

//Function to Generate PaySlip of Permanent Employee
void generate_pay_slip(Permanent_Employee per)
{
	int no;
	char f1_name[8], num[8], emp[8];
	cout<<"Enter the Month Number (1-12) : ";
	cin>>no;
	if(no<0 || no>12)
	{
		cout<<"Invalid Month Number"<<endl;
		return;
	}
	system("cls");
	cout<<"::::::::::::PaySlip for Month Number "<<no<<"::::::::::::::::"<<endl;
	per.calculate();
	per.displayData();
	//Creation of file name with month number and employee number
	sprintf(num,"%d_",no);
	sprintf(emp,"%d",per.emp_no);
	strcpy(f1_name,num);
	strcat(f1_name,emp);
	f1_name[strlen(num)+strlen(emp)] = '\0';
	ofstream outfile;
	outfile.open("f1_name");
	cout<<":::::::::::::::PaySlip for month Number "<<no<<" ::::::::::::::::::"<<endl;
	outfile<<"Employee Number : "<<per.emp_no<<endl;
	outfile<<"Employee's Name : "<<per.emp_name<<endl;
	outfile<<"Employee's Address : "<<per.emp_add<<endl;
	outfile<<"Employee's Department : "<<per.emp_dep<<endl;
	outfile<<"Employee's Designation : "<<per.emp_desg<<endl;
	outfile<<"Employee Type : "<<per.emp_type<<endl;
	outfile<<"Employee's Basic salary : "<<per.emp_basic<<endl;
	outfile<<"Dearness Allowance : "<<per.emp_da<<endl;
	outfile<<"House Rental Allowance : "<<per.emp_hra<<endl;
	outfile<<"Medical Allowance : "<<per.emp_ma<<endl;
	outfile<<"Provident Fund : "<<per.emp_pf<<endl;
	outfile<<"Professional Tax : "<<per.ptax<<endl;
	outfile<<"Income Tax : "<<per.itax<<endl;
	outfile<<"Gross Salary : "<<per.gross<<endl;
	outfile<<"Net Salary : "<<per.net<<endl;
	outfile.close();
}


//Function to generate Payslip of Contractual Employee
void generate_pay_slip(Contractual_Employee con)
{
	int no;
	char f1_name[8], num[8], emp[8];
	cout<<"Enter the Month Number (1-12) : ";
	cin>>no;
	if(no<0 || no>12)
	{
		cout<<"Invalid Month Number"<<endl;
		return;
	}
	system("cls");
	cout<<"::::::::::::PaySlip for Month Number "<<no<<"::::::::::::::::"<<endl;
	con.calculate();
	con.displayData();
	//Creation of file name with month number and employee number
	sprintf(num,"%d_",no);
	sprintf(emp,"%d",con.emp_no);
	strcpy(f1_name,num);
	strcat(f1_name,emp);
	f1_name[strlen(num)+strlen(emp)] = '\0';
	ofstream outfile;
	outfile.open("f1_name");
	cout<<":::::::::::::::PaySlip for month Number "<<no<<" ::::::::::::::::::"<<endl;
	outfile<<"Employee Number : "<<con.emp_no<<endl;
	outfile<<"Employee's Name : "<<con.emp_name<<endl;
	outfile<<"Employee's Address : "<<con.emp_add<<endl;
	outfile<<"Employee's Department : "<<con.emp_dep<<endl;
	outfile<<"Employee's Designation : "<<con.emp_desg<<endl;
	outfile<<"Employee Type : "<<con.emp_type<<endl;
	outfile<<"Professional Tax : "<<con.ptax<<endl;
	outfile<<"Income Tax : "<<con.itax<<endl;
	outfile<<"Gross Salary : "<<con.gross<<endl;
	outfile<<"Net Salary : "<<con.net<<endl;
	outfile.close();
}

//********************************************************************
				//Function of Computing Over-Time Dues
//********************************************************************

void compute_OT()
{
	//For Permanent Employees
	ifstream infile;
	Permanent_Employee p;
	int hours;
	int ot;
	ofstream outfile;
	infile.open("Per_Emp");
	outfile.open("Per_Payroll");
	system("cls");
	cout<<"Computation of Overtime dues of Permanent Employees is in progress................."<<endl;
	while(!infile.eof())
	{
		infile>>p.emp_no;
		infile>>p.emp_name;
		infile>>p.emp_add;
		infile>>p.emp_dep;
		infile>>p.emp_desg;
		infile>>p.emp_type;
		infile>>p.emp_basic;
		infile>>p.emp_da;
		infile>>p.emp_hra;
		infile>>p.emp_ma;
		infile>>p.emp_pf;
		infile>>p.ptax;
		infile>>p.itax;
		infile>>p.gross;
		infile>>p.net;
		if(infile.eof())
		{
			break;
		}
		cout<<"Enter the Over-Time hours of Employee Number "<<p.emp_no<<" : "<<endl;
		cin>>hours;
		p.net = p.net + (hours*500);//500 Rupees for an every extra hour
		ot = hours*500;
		outfile<<p.emp_no<<endl;
		outfile<<p.emp_name<<endl;
		outfile<<p.emp_add<<endl;
		outfile<<p.emp_dep<<endl;
		outfile<<p.emp_desg<<endl;
		outfile<<p.emp_type<<endl;
		outfile<<p.emp_basic<<endl;
		outfile<<p.emp_da<<endl;
		outfile<<p.emp_hra<<endl;
		outfile<<p.emp_ma<<endl;
		outfile<<p.emp_pf<<endl;
		outfile<<p.ptax<<endl;
		outfile<<p.itax<<endl;
		outfile<<p.gross<<endl;
		outfile<<ot<<endl;
		outfile<<p.net<<endl;
	}
	infile.close();
	outfile.close();
	cout<<"Computation of Over-Time Dues of Permanent Employees has completed...................."<<endl;
	cin.get();
	//For Contractual Employees
	Contractual_Employee c;
	infile.open("Cont_Emp");
	outfile.open("Cont_Payroll");
	system("cls");
	cout<<"Computation of Overtime dues of Contractual Employees is in progress................."<<endl;
	while(!infile.eof())
	{
		infile>>c.emp_no;
		infile>>c.emp_name;
		infile>>c.emp_add;
		infile>>c.emp_dep;
		infile>>c.emp_desg;
		infile>>c.emp_type;
		infile>>c.ptax;
		infile>>c.itax;
		infile>>c.gross;
		infile>>c.net;
		if(infile.eof())
		{
			break;
		}
		cout<<"Enter the Over-Time hours of Employee Number "<<c.emp_no<<" : "<<endl;
		cin>>hours;
		c.net = c.net + (hours*500);
		ot = hours*500;
		outfile<<c.emp_no<<endl;
		outfile<<c.emp_name<<endl;
		outfile<<c.emp_add<<endl;
		outfile<<c.emp_dep<<endl;
		outfile<<c.emp_desg<<endl;
		outfile<<c.emp_type<<endl;
		outfile<<c.ptax<<endl;
		outfile<<c.itax<<endl;
		outfile<<c.gross<<endl;
		outfile<<ot<<endl;
		outfile<<c.net<<endl;
	}
	infile.close();
	outfile.close();
	cout<<"Computation of Over-Time Dues of Contractual Employees has completed...................."<<endl;
	//Printing of over-Time Dues
	cin.get();
	system("cls");
	infile.open("Per_Payroll");
	cout<<"Over-Time Dues of Employees : "<<endl;
	cout<<setw(20)<<"Employee Number"<<setw(40)<<"Employee Name"<<setw(20)<<"Over-Time Dues"<<endl;
	while(!infile.eof())
	{
		infile>>p.emp_no;
		infile>>p.emp_name;
		infile>>p.emp_add;
		infile>>p.emp_dep;
		infile>>p.emp_desg;
		infile>>p.emp_type;
		infile>>p.emp_basic;
		infile>>p.emp_da;
		infile>>p.emp_hra;
		infile>>p.emp_ma;
		infile>>p.emp_pf;
		infile>>p.ptax;
		infile>>p.itax;
		infile>>p.gross;
		infile>>ot;
		infile>>p.net;
		if(infile.eof())
		{
			break;
		}
		cout<<setw(20)<<p.emp_no<<setw(40)<<p.emp_name<<setw(20)<<ot<<endl;
	}
	infile.close();
	infile.open("Cont_Payroll");
	while(!infile.eof())
	{
		infile>>c.emp_no;
		infile>>c.emp_name;
		infile>>c.emp_add;
		infile>>c.emp_dep;
		infile>>c.emp_desg;
		infile>>c.emp_type;
		infile>>c.ptax;
		infile>>c.itax;
		infile>>c.gross;
		infile>>ot;
		infile>>c.net;
		if(infile.eof())
		{
			break;
		}
		cout<<setw(20)<<c.emp_no<<setw(40)<<c.emp_name<<setw(20)<<ot<<endl;
	}
	infile.close();
}

//********************************************************************
					//Get-Set Functions
//********************************************************************


//Function of getting Employee Number
int get_emp_no()//Function of generating Automatic Employee Number
{
	ifstream infile;
	if(infile.fail())
	{
		num = 1;
	}
	else
	{
		infile.open("empNo_file");
		infile>>num;
		num = num + 1;
		infile.close();
	}
	ofstream outfile;
	outfile.open("empNo_file");
	outfile<<num;
	outfile.close();
	
	return num;
}

//Function of Setting Dearness Allowance (DA) Rate
void set_da_rate(int da_rate)
{
	ofstream outfile;
	outfile.open("da_file");
	outfile<<da_rate;
	outfile.close();
}

//Function of Getting Dearness Allowance (DA) Rate
int get_da_rate()
{
	int da_rate;
	ifstream infile;
	infile.open("da_file");
	infile>>da_rate;
	infile.close();
	return da_rate;
}

//Function of Setting House Rental Allowance (HRA) Rate
void set_hra_rate(int hra_rate)
{
	ofstream outfile;
	outfile.open("hra_file");
	outfile<<hra_rate;
	outfile.close();
}

//Function of Getting House rental Allowance (HRA) Rate

int get_hra_rate()
{
	int hra_rate;
	ifstream infile;
	infile.open("hra_file");
	infile>>hra_rate;
	infile.close();
	return hra_rate;
}

//Function of Setting Medical Allowance (MA)
void set_ma(int ma)
{
	ofstream outfile;
	outfile.open("ma_file");
	outfile<<ma;
	outfile.close();
}

//Function of Getting Medical Allowance (MA)

int get_ma()
{
	int ma;
	ifstream infile;
	infile.open("ma_file");
	infile>>ma;
	infile.close();
	return ma;
}

//Function of Setting Professional Tax

void set_ptax(int ptax)
{
	ofstream outfile;
	outfile.open("ptax_file");
	outfile<<ptax;
	outfile.close();
}

//Function of Getting Professional Tax

int get_ptax()
{
	int ptax;
	ifstream infile;
	infile.open("ptax_file");
	infile>>ptax;
	infile.close();
	return ptax;
}

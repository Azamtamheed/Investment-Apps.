#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
    double 	Initial_investment, target_profit,yrly_profit, base_profit, annual_increment, total_profit, service_charge, profit_tax, profit_tax_rate, net_profit, penalty_charge, penalty_charge_rate=0;
    int Investor_age, investment_period, year;
    char option;
    
    // Input section
    
	cout<<"WELCOME\n"<<" Check if you are eligible for investment or not by filling the following info : "<<endl;
	//age validation
    do{
cout << "\nPlease enter your age: ";
    cin >> Investor_age;
    if (Investor_age <18 || Investor_age>=70 ) {
        cout << "Sorry, you are not eligible to invest , age should be between 18 and 70 ." << endl;
  
    }
}while(Investor_age < 18|| Investor_age>=70 );

    	cout<<"\nYou can only invest for "<<70-Investor_age<<" years"<<" (eligible investment period)"<<endl;
    //investment validation	
    	 do{
	
    cout << "\nPlease enter your investment amount : ";
    cin >> Initial_investment;
    if (Initial_investment < 5000 || Initial_investment > 200000)
	 {
        cout << "Sorry, the investment amount must be between 5000 and 200000." << endl;  
    }
}while (Initial_investment < 5000 || Initial_investment > 200000);
    //investment period validation
   do{

    cout << "\nPlease enter your investment period : ";
    
    cin >> investment_period;
    
    if (investment_period>70-Investor_age || investment_period > 25 || investment_period<=0) 
	{
        cout << "Sorry, the investment period must be above or equal to zero and between eligible investment period  to 25 years." << endl;
		}
	}while(investment_period>70-Investor_age|| investment_period > 25||investment_period<=0) ;
    //penalty charge for less than 5 years
    		if(investment_period>=0&&investment_period<5){
			cout<<"There will be a penalty charge of 7% because investment period is less than  5 year "<<endl;
			penalty_charge_rate=0.07;
			
		}
		
		cout<<"Congratulations you are eligible for investing "<<endl;
	
		cout<<" \n\n..................................................................................................\n\n"<<endl;
	do
	{
		
        cout<<".............................................Main meanu............................................. \n"<<"Please choose between option 1 2 and 3 \n"<<"1.Calculate Target Profit  \n"<<"2.Calculate No of years to reach target profit \n"<<"3. Rate of different service and investment charges\n"<<"4.EXIT the program \n";
        
	    cin>>option;
    //main menu using switch 

//	
    switch(option){
    	//calculating interest 
    	case'1':cout<<"\n...................................\n";
		cout<<"calculating interest"<<endl;
   
    	
    	cout<<"Enter Base Profit ";
    	
    	cin>>base_profit;
    	base_profit=base_profit*0.01;
    	 
    	
    	if (Initial_investment < 50000) {
    	
    	for(int count=1;count<=investment_period;count++)
		{
    		 yrly_profit= (Initial_investment)*(base_profit);
    		Initial_investment+= yrly_profit;
    		total_profit+=yrly_profit;
    		cout<<fixed<<setprecision(2);
    		cout<<count<<" ."<<"Total Profit earned after  "<<count<<" years "<<total_profit<<endl<<"Accumullated Investment "<<Initial_investment<<"\n\n";
    		base_profit+=0.0015;
		}
		
	}
	
	else if (Initial_investment >= 50000 && Initial_investment <= 100000) 
	{
    	
    	for(int count=1;count<=investment_period;count++)
		{
    	yrly_profit= (Initial_investment)*(base_profit);
    		Initial_investment+= yrly_profit;
    		total_profit+=yrly_profit;
    		cout<<fixed<<setprecision(2);
    		cout<<count<<" ."<<"Total Profit earned after  "<<count<<" years "<<total_profit<<endl<<"Accumullated Investment "<<Initial_investment<<"\n\n";
    		base_profit+=0.0025;
		}
		
	
	}
	
		else
		 {
    	
    	for(int count=1;count<=investment_period;count++)
		{
			if(count<=10){
			
    		yrly_profit= (Initial_investment)*(base_profit);
    		Initial_investment+= yrly_profit;
    		total_profit+=yrly_profit;
    		cout<<fixed<<setprecision(2);
    		cout<<count<<" ."<<"Total Profit earned after  "<<count<<" years "<<total_profit<<endl<<"Accumullated Investment "<<Initial_investment<<"\n\n";
    		base_profit+=0.0035;
    	}
		if(count>=11){
    	yrly_profit= (Initial_investment)*(base_profit);
    		Initial_investment+= yrly_profit;
    		total_profit+=yrly_profit;
    		cout<<fixed<<setprecision(2);
    		cout<<count<<" ."<<"Total Profit earned after  "<<count<<" years "<<total_profit<<endl<<"Accumullated Investment "<<Initial_investment<<"\n\n";
    		base_profit+=0.0055;
		
	}
}
	  
}
     service_charge=(total_profit)*0.025;
    penalty_charge= (Initial_investment)*(penalty_charge_rate);
	
	
		if (total_profit < 70000)
		{
			profit_tax_rate=0.03;
		}
		
		else if (total_profit >= 70000 && total_profit <= 150000)
		{
			profit_tax_rate=0.05;
		}
		
		else
		{
			profit_tax_rate=0.07;
		}
		profit_tax=(total_profit-service_charge)*(profit_tax_rate);
		net_profit=total_profit-(penalty_charge+profit_tax+service_charge) ;
		cout<<fixed<<setprecision(2);
		cout<<"Profit tax :"<<" \n"<<profit_tax<<endl;
		cout<<" service charge : \n"<<service_charge<<endl;
		cout<<"Net Profit :\n"<<net_profit<<endl;
    
    	break;
    	
    	
    	case'2':
    		
    		
		cout<<"calculating no of years to reach goal\n (IMPORTANT :extra charges may apply at the end of investment period)"<<endl;
		
    	cout<<"Enter target profit ";
    	
    	cin>>target_profit;
    	
    	cout<<"Enter base profit";
    	
    	cin>>base_profit;
    	base_profit=base_profit*0.01;
    	
    		if (Initial_investment < 50000) 
			{
    			while(total_profit<=target_profit)
				{
    	
    	
    	yrly_profit= (Initial_investment)*(base_profit);
    		Initial_investment+= yrly_profit;
    		total_profit+= yrly_profit;
    		base_profit+=0.0015;
    		year++;
		
	}
	    cout<<fixed<<setprecision(2);
		cout<<"It will take "<<year<<" years to reach your targetprofit of "<<target_profit<<endl; 
		cout<<"profit after "<<year<<" years will be : "<<total_profit<<endl;
		
	
	
}
	else if (Initial_investment >= 50000 && Initial_investment <= 100000)
	{
    	
    	while(total_profit<=target_profit)
		{
    		yrly_profit= (Initial_investment)*(base_profit);
    		Initial_investment+= yrly_profit;
    		total_profit+=yrly_profit;
    		base_profit+=0.0025;
    		year++;
		}
		
}
	
		else
		 {
		 
		
		while(total_profit<=target_profit){
			int count=1;
		
    	if( count<=10){
			
    		yrly_profit= (Initial_investment)*(base_profit);
    		Initial_investment+= yrly_profit;
    		total_profit+=yrly_profit;
    		base_profit+=0.0035;
    	}
		if( count>=11){
    		yrly_profit= (Initial_investment)*(base_profit);
    		Initial_investment+= yrly_profit;
    		total_profit+=yrly_profit;
    		base_profit+=0.0055;
		
	}
	year++;
    	}
            cout<<fixed<<setprecision(2);
    		cout<<"It will take "<<year<<" years to reach your targetprofit of "<<target_profit<<endl; 
		cout<<"profit after "<<year<<" years will be : "<<total_profit<<endl;
		
			
		}
	
		break;
		
		case'3':// switch case to get the info regarding the charges and rate	
		
		cout<<"Rate of different service and investment charges: \n"<<endl;
		cout<<"\n..........................\n";
		cout<<"\nService charge is 2.5% of total profit at the end of investment period "<<endl;
		cout<<"\nProfit Tax is applied  on the netprofit earned after deducting the service charge "<<endl;
		cout<<"\nProfit Tax rate for\n\n total profit  :\n below MYR 70,000 =>  3% \n\n above MYR 70,000 and below MYR 150,000 => 5% \n\n above MYR 150,000=> 7% ";
		cout<<"\nThere is a penalty charge of 7% for investment period of less than 5 years";
    		break;
    		
    	case'4':cout<<"EXIT"<<endl;
    	cout<<"....................THANK YOU...................."<<endl;
    	break;
    	default:cout<<"wrong input try again "<<endl;
    	break;
	}
      }while(option!=4);
   
    

        return 0;
     }



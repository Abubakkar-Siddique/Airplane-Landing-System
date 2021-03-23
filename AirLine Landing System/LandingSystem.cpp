#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

const int x = 10;

struct flight
{
	char id[20];
	char city[20];
	int DeptTime;
	int LandTime;
	int fuel; //fuel in gallons
};

class LandingSystem {
private:
	flight runway1[x];
	int count1;
	flight runway2[x];
	int count2;
	flight flights[30];
	int count3;
public:

	LandingSystem()
	{
		count1 = 0;
		count2 = 0;
		count3 = 0;
	}

	bool chkFlightID(char id[20])
	{
		string s;
		string s1 = id;
		for (int i = 0; i < count1; i++)
		{
			s = runway1[i].id;
			if (s == id)
			{
				return true;
			}
		}
		for (int i = 0; i < count2; i++)
		{
			s = runway2[i].id;
			if (s == id)
			{
				return true;
			}
		}
		return false;
	}

	void enterFlight()
	{
		if (count1 < x && count2 < x)
		{
			if (count1 < count2)
			{
				cout << " Enter Flight ID : ";
				cin.getline(runway1[count1].id, 20);
				cin.getline(runway1[count1].id, 20);
				if (chkFlightID(runway1[count1].id) != true)
				{
					cout << " From where the Flight is : ";
					cin.getline(runway1[count1].city, 20);
					cout << " Enter Flight Arrival time : ";
					cin >> runway1[count1].DeptTime;
					cout << " Enter Flight Landing time : ";
					cin >> runway1[count1].LandTime;
					cout << " Enter fuel remaining in Flight  : ";
					cin >> runway1[count1].fuel;
					count1++;
					cout << "\n Flight entered in Runway1 Queue! " << endl;
				}	
				else
				{
					cout << "\n Enter Unique Flight ID! " << endl;
				}
			}
			else
			{
				cout << " Enter Flight ID : ";
				cin.getline(runway2[count2].id, 20);
				cin.getline(runway2[count2].id, 20);
				if (chkFlightID(runway2[count2].id) != true)
				{
					cout << " From where the Flight is : ";
					cin.getline(runway2[count2].city, 20);
					cout << " Enter Flight Arrival time : ";
					cin >> runway2[count2].DeptTime;
					cout << " Enter Flight Landing time : ";
					cin >> runway2[count2].LandTime;
					cout << " Enter fuel remaining in Flight  : ";
					cin >> runway2[count2].fuel;
					count2++;
					cout << "\n Flight entered in Runway2 Queue! " << endl;
				}
				else
				{
					cout << "\n Enter Unique Flight ID! " << endl;
				}
			}
		}
		else
		{
			cout << "\n Move to another airport runways full" << endl;
		}
	}

	void landingFlight(int cases, int runway)
	{
		switch (cases)
		{
		case 1:
		{
			switch (runway)
			{
			case 1:
			{
				if (count1 > 0)
				{
					count1--;
					for (int i = 0; i < count1; i++)
					{
						runway1[i] = runway1[i + 1];
					}
					cout << "\n Flight Landed Successfully!\n " << endl;
				}
				else
				{
					cout << "\n No Flight in Runway1 Queue!\n " << endl;
				}
			}
			break;

			case 2:
			{
				if (count2 > 0)
				{
					count2--;
					for (int i = 0; i < count2; i++)
					{
						runway2[i] = runway2[i + 1];
					}
					cout << "\n Flight Landed Successfully!\n " << endl;
				}
				else
				{
					cout << "\n No Flight in Runway2 Queue!\n " << endl;
				}
			}
			break;

			default:
			{
				cout << "\n Enter exact Runway! " << endl;
			}
			}
		}
		break;

		case 0:
		{
			switch (runway)
			{
			case 1:
			{
				int y;
				for (int i = 0; i < count1; i++)
				{
					if (runway1[i].fuel < 100)
					{
						y = i;
						char a;
						cout << " "<<runway1[i].id<<" Fuel low from Runway1 Queue do you want to immediately land Flight (y/n) : ";
						cin >> a;
						if (a == 'Y' || a == 'y')
						{
							count1--;
							for (int j = y; j < count1; j++)
							{
								runway1[i] = runway1[i + 1];
							}
							cout << "\n Flight Landed Successfully! " << endl;
							cout << "\n\n";
						}
					}
				}
			}
			break;

			case 2:
			{
				int y;
				for (int i = 0; i < count2; i++)
				{
					if (runway2[i].fuel < 100)
					{
						y = i;
						char a;
						cout << " " << runway2[i].id << " Fuel low from Runway2 Queue do you want to immediately land Flight (y/n) : ";						cin >> a;
						if (a == 'Y' || a == 'y')
						{
							count2--;
							for (int i = y; i < count2; i++)
							{
								runway2[i] = runway2[i + 1];
							}
							cout << "\n Flight  Landed Successfully! " << endl;
							cout << "\n\n";
						}
					}
				}	
			}
			break;

			default:
			{
				cout << "\n Enter exact Runway! " << endl;
			}
			}
		}
		break;
		}
	}

	void Iterations()
	{
		for (int i = 0; i < count1; i++)
		{
			runway1[i].fuel=runway1[i].fuel - 100;
			runway1[i].LandTime=runway1[i].LandTime + 10;
			landingFlight(0, 1);
		}
		for (int i = 0; i < count2; i++)
		{
			runway2[i].fuel = runway2[i].fuel - 100;
			runway2[i].LandTime = runway2[i].LandTime + 10;
			landingFlight(0, 2);
		}		
	}

	void runwaysTraffic()
	{
		cout << " " << endl;
		cout << " Flights on Runway1 Queue \n";
		cout << " -------------------------\n";
		cout << " FlightID | ";
	    cout << "\tArrival City | ";
		cout << "\tArrival Time | ";
		cout << "\t Landing Time | ";
		cout << "\tPresent Fuel ";
		cout << "\n " << endl;
		if (count1 > 0)
		{
			for (int i = 0; i < count1; i++)
			{
				cout << " " << runway1[i].id;
				cout << "\t\t" << runway1[i].city;
				cout << "\t\t" << runway1[i].DeptTime;
				cout << "\t\t" << runway1[i].LandTime;
				cout << "\t\t" << runway1[i].fuel;
				cout << "\n";
			}
		}
		else
		{
			cout << " No Flights in Runway1 Queue \n" << endl;
		}
		cout << " " << endl;
		cout << " Flights on Runway2 Queue \n";
		cout << " -------------------------\n";
		cout << " FlightID | ";
		cout << "\tArrival City | ";
		cout << "\tArrival Time | ";
		cout << "\t Landing Time | ";
		cout << "\tPresent Fuel ";
		cout << "\n " << endl;
		if (count2 > 0)
		{
			for (int i = 0; i < count2; i++)
			{
				cout << " " << runway2[i].id;
				cout << "\t\t" << runway2[i].city;
				cout << "\t\t" << runway2[i].DeptTime;
				cout << "\t\t" << runway2[i].LandTime;
				cout << "\t\t" << runway2[i].fuel;
				cout << "\n";
			}
		}
		else
		{
			cout << " No Flights in Runway2 Queue \n" << endl;
		}
		cout << " " << endl;
	}

};

int main() {
	LandingSystem oa;
	int a;
	cout << " " << endl;
	cout << " Welcome to Flight Landing System! " << endl;
	cout << " " << endl;
	cout << " 1. Insert Flight in Queue " << endl;
	cout << " 2. Land Flight " << endl;
	cout << " 3. Display Runways Traffic " << endl;
	cout << " 0. Exit from System " << endl;
	cout << " " << endl;
	cout << " Enter value from above menu : ";
	cin >> a;

	while (a != 0)
	{
		switch (a)
		{
		case 1:
		{
			cout << "\n " << endl;
			oa.enterFlight();
			cout << "\n " << endl;
		}
		break;

		case 2:
		{
			int run;
			cout << "\n " << endl;
			cout << " Which Runway you want to land the flight : ";
			cin >> run;
			cout << " " << endl;
			oa.landingFlight(1,run);
			cout << "\n " << endl;
		}
		break;

		case 3:
		{
			oa.runwaysTraffic();
		}
		break;

		default:
		{
			cout << "\n Enter appropriate value from menu!\n\n";
		}
		}
		oa.Iterations();
		cout << " 1. Insert Flight in Queue " << endl;
		cout << " 2. Land Flight " << endl;
		cout << " 3. Display Runways Traffic " << endl;
		cout << " 0. Exit from System " << endl;
		cout << " " << endl;
		cout << " Enter value from above menu : ";
		cin >> a;
	}

	system("pause");
	return 0;
}
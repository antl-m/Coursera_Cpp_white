#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


int main()
{
	//vector<string> BusNames;
	//vector<string> StopNames;
	map<string, vector<string>> StopForBus;
	map<string, vector<string>> BusForStop;

	int q;
	cin >> q;
	string cmd;
	for (size_t j = 0; j < q; j++)
	{
		cin >> cmd;
		if (cmd == "NEW_BUS")
		{
			string bus;
			string stop;
			int count;
			cin >> bus;
			//BusNames.push_back(bus);
			cin >> count;
			for (size_t i = 0; i < count; i++)
			{
				cin >> stop;
				//StopNames.push_back(stop);
				StopForBus[bus].push_back(stop);
				BusForStop[stop].push_back(bus);
			}
		}
		else if (cmd == "BUSES_FOR_STOP")
		{
			string stop;
			cin >> stop;
			if (BusForStop.count(stop) == 0)
			{
				cout << "No stop" << endl;
			}
			else
			{
				for (const auto& bus : BusForStop[stop])
				{
					cout << bus << ' ';
				}
				cout << endl;
			}
		}
		else if (cmd == "STOPS_FOR_BUS")
		{
			string bus;
			cin >> bus;
			if (StopForBus.count(bus) == 0)
			{
				cout << "No bus" << endl;
			}
			else
			{
				for (const auto& stop : StopForBus[bus])
				{
					cout << "Stop " << stop << ": ";
					if (BusForStop[stop].size() > 1)
						for (const auto& prsdk : BusForStop[stop])
						{
							if (prsdk != bus)
								cout << prsdk << ' ';
						}
					else
						cout << "no interchange";
					cout << endl;
				}
			}
		}
		else if (cmd == "ALL_BUSES")
		{
			if (StopForBus.size() == 0)
				cout << "No buses" << endl;
			else
			{
				for (const auto& pair : StopForBus)
				{
					cout << "Bus " << pair.first<<": ";
					for (const auto& stop: pair.second)
					{
						cout << stop << ' ';
					}
					cout << endl;
				}
			}
		}
	}
	return 0;
}
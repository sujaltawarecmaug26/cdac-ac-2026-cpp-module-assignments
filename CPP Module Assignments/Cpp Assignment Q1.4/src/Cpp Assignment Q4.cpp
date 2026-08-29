#include <iostream>
using namespace std;

int main(int argc, char * argv[]){

  cout << "You have entered " << argc
         << " arguments:" << endl;

    if (argc < 4)
    {
        cout << "Usage   : ./sensor_monitor <warn_threshold> <critical_threshold> <num_readings>";
        return 1;
    }
    else
    {
        int warn = stoi(argv[1]);
        int critical = stoi(argv[2]);
        int numReadings = stoi(argv[3]);

        if (warn >= critical)
        {
            cout << "threshold error";
            return 1;
        }
        else if (numReadings < 1 || numReadings > 500)
        {
            cout << "readings error";
            return 1;
        }

       int normal = 0;
       int warning = 0;
       int criticalCount = 0;

            for (int i = 0; i < numReadings; i++)
            {
                int temperature = rand() % 70;

                if (temperature < warn)
                {
                    normal++;
                }
                else if (temperature < critical)
                {
                    warning++;
                }
                else
                {
                    criticalCount++;
                }
            }

            cout << "Warn = " << warn << "C" << endl;
            cout << "Critical = " << critical << "C" << endl;
            cout << "Readings = " << numReadings << endl;

            cout << "Normal = " << normal << endl;
            cout << "Warning = " << warning << endl;
            cout << "Critical = " << criticalCount << endl;
    }

    return 0;



}

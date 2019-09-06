/**
UBA Awareness App
Version 1.0
Author Branislav
*/

#include <iostream>
#include <ctime>
#include <windows.h>
#include <mmsystem.h>
#include <fstream>
#include "resource.h"

using namespace std;

int main() {
    /**
    //resource test
    bool play = PlaySound(
                MAKEINTRESOURCE(IDR_SOUND),
                GetModuleHandle(NULL),
                SND_RESOURCE | SND_SYNC
            );

    cout << play << endl;
    system("pause");

    //end resource test
    */



    time_t savedTime = time(NULL);
    //cout << "Seconds elapsed: " << savedTime << endl;
    //int oneHour = 60 * 60;
    int oneHour = 5 * 1; //for testing

    //set console title
    tm* getDate = localtime(&savedTime);
    int getMonth = ((++getDate->tm_mon));
    int getYear = (getDate->tm_year + 1900);
    int getDay = (getDate->tm_mday);

    char printD[25];
    sprintf(printD, "%02d/ %02d/ %04d", getDay, getMonth, getYear);

    string finalDatePrint;
    finalDatePrint += printD;

    //cout << finalDatePrint;

    //return EXIT_FAILURE;

    /*string makeDate = (getDay) + "/"
                    + (getMonth) + "/"
                    + (getYear);*/

    //string timeGet = asctime(localTime);
    //timeGet.replace(0, 6, "1");
    //cout << makeDate;

    string appName = "UBA Awareness App --- Date: ";
    appName.append(finalDatePrint);
    SetConsoleTitle(appName.c_str());
    system("pause");

    while (true) {
        time_t currentTime = time(NULL);
        time_t oneHourMore = savedTime + oneHour;

        if (currentTime >= oneHourMore) {
            cout << "Take a break...." << endl;
            savedTime = time(NULL);
            //Beep(523,500); // beep sound
            //printf("\a"); // error sound - print bell char

            //play sound directly

            //PlaySound(TEXT("police.wav"), NULL, SND_ASYNC);

            //play resource - must compile resource
            PlaySound(MAKEINTRESOURCE(IDR_SOUND),GetModuleHandle(NULL),
                SND_RESOURCE | SND_ASYNC
            );
        }
    }

    return 0;
}

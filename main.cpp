/**

- UBA Awareness App
- Version: 1.1
- Author: Branislav
- GitHub repo: https://github.com/branislav-markovic/uba_app
- GitHub site: https://branislav-markovic.github.io/

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

    //set bg color
    system("color 75");

    //set text color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 39);

    //cout << "Test color" << endl;

    time_t savedTime = time(NULL);
    //cout << "Seconds elapsed: " << savedTime << endl;
    int oneHour = 60 * 60;
    //int oneHour = 5 * 1; //for testing

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
    //system("pause");

    //LPCTSTR selectedSong = IDR_SOUND;

    //select alert song
    //while loop here

    int selectedSong = false;

    do {
        cout << "Please select alert tone: " << endl << "1 - Alarm alert" << endl
         << "2 - Bird song" << endl
         << "3 - Church bell" << endl
         << "4 - Countdown" << endl
         << "5 - Crickets at night" << endl
         << "6 - Finger snapping" << endl
         << "7 - Pool shot" << endl
         << "Enter your tone: (only numbers, for example 1) : ";

        string userChoice;
        cin >> userChoice;

        try {
            selectedSong = stoi(userChoice);

            if (!selectedSong) {
                throw invalid_argument("Invalid syntax.");
            }
        } catch(const invalid_argument& err) {
            selectedSong = false;

            //reset bg and text color
            system("CLS && color 75");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 39);

            //cout << "Please enter only numbers" << endl;
            //cout << "Your error: " << &err << endl;
        }

    } while (!selectedSong);


    //cout << "song: " << selectedSong;

    /*while (!selectedSong) {
        selectedSong = true;
    }*/

    int soundLength = 7000;
    savedTime = time(NULL);
    //cout << "Ulaz: " <<  savedTime;

    while (true && selectedSong) {
        system("CLS && color 75");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 39);

        time_t currentTime = time(NULL);
        time_t oneHourMore = savedTime + oneHour;

        if (currentTime >= oneHourMore) {
            //cout << "Izlaz: " << savedTime << endl;
            cout << "Take a break...." << endl;
            savedTime = time(NULL);
            //Beep(523,500); // beep sound
            //printf("\a"); // error sound - print bell char

            //play sound directly

            //PlaySound(TEXT("police.wav"), NULL, SND_ASYNC);

            //play resource - must compile resource
            PlaySound(MAKEINTRESOURCE(selectedSong),GetModuleHandle(NULL),
                SND_RESOURCE | SND_SYNC
            );

            Sleep(soundLength);
        }
    }

    return 0;
}

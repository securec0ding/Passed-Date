#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

int day = 0;
int month = 0;
int year = 0;
int hour = 0;
int minute = 0;
int second = 0;
int wday = 0;

string day_names[7] = {"Sunday",
                       "Monday",
                       "Tuesday",
                       "Wednesday",
                       "Thursday",
                       "Friday",
                       "Saturday"};

void refresh_date() {
  time_t t = time(0);
  tm* now = localtime(&t);

  day = now->tm_mday;
  month = now->tm_mon;
  year = now->tm_year + 1900;
  hour = now->tm_hour;
  minute = now->tm_min;
  second = now->tm_sec;
  wday = now->tm_wday;
}

void handle_message() {
  string message;
  getline(cin, message);

  int message_len = message.length();

  for (int n=0; n != message_len;) {
    char m = message[n];
    if (m == '%') {
      if (m == message_len - 1)
        break;
      switch(message[n + 1]) {
        case 'd': cout << day; break;
        case 'M': cout << month; break;
        case 'y': cout << year; break;
        case 'h': cout << hour; break;
        case 'm': cout << minute; break;
        case 's': cout << second; break;
        case 'w': cout << day_names[wday]; break;
        case '%': cout << '%'; break;
        default: cout << m << message[n+1]; break;
      }
      n += 2;
    } else {
      cout << m;
      n += 1;
    }
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  cout << "Enter string to format as date (i.e. %y for year):" << endl;
  while(1) {
    refresh_date();
    handle_message();
  }

  return 0;
}
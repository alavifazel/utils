/* Example output:
Timer started at [ 00:43:36 PM ] -> 00:44:45
*/

#ifndef _WIN32
#include <unistd.h>
#else
#include <windows.h>
#endif
#include <stdio.h>
#include <time.h>
#include <math.h>

size_t getNumOfDigits(size_t n) {
  return n > 0 ? (int) log10((double) n) + 1: -1;
}

void printBackspace(size_t n) {
  for(size_t i = 0; i < n; ++i) printf("\b");
}

const char* getCurrentTime() {
  time_t time_object;
  struct tm * timeinfo;
  time(&time_object);
  timeinfo = localtime(&time_object);
  static char output[32];
  if(timeinfo->tm_hour < 12) {
    sprintf(output, "[ %02d:%02d:%02d AM ]", 
	    timeinfo->tm_hour,
	    timeinfo->tm_min,
	    timeinfo->tm_sec);
  } else {
    sprintf(output, "[ %02d:%02d:%02d PM ]", 
	    timeinfo->tm_hour % 12,
	    timeinfo->tm_min,
	    timeinfo->tm_sec);
  }
  return output;
}

const char* getTimeString(size_t seconds) {
  size_t hours = (seconds / 3600);
  size_t minutes = (seconds - (hours * 3600)) / 60;
  seconds = seconds - (hours * 3600 + minutes * 60);
  static char res[10];
  sprintf(res, "%02zu:%02zu:%02zu", hours, minutes, seconds);
  return res;
}

int main() {
  size_t sec = 0;
  printf("Timer started at %s -> ", getCurrentTime());;
  printf("%s", getTimeString(sec));;
  while(1) {
    printBackspace(8);
    printf("%s", getTimeString(sec));
    sleep(1);
    sec++;
    fflush(stdout);
  }
}

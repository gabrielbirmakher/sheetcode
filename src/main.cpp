#include <iostream>
#include "../sqlite3/sqlite3.h"
#include "../include/setup.hpp"

int main(){
    /*
        Opens activity_log_file
    */
    FILE *activity_log_file;
    activity_log_file = fopen("activityLog.txt", "w");

    int test = setup();
    if(test == 0){
        fprintf(activity_log_file, "Cannot continue with operation, setup was unsuccessful\n");
        return 0;
    }

    return 0;
}


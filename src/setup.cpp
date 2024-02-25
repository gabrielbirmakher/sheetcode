#include <iostream>
#include "../sqlite3/sqlite3.h"
#include "setup.hpp"

int setup(void){
    /*
        Creates file to record program activity 
    */
    FILE *activity_log_file;
    activity_log_file = fopen("activityLog.txt", "w");
    /*
        Initializes variables for the database, error messages, and the query
    */
    sqlite3 *db;
    char *errMsg = 0;
    const char *query = nullptr;
    /*
        Create new database and make sure that it was created.
        Prints error messages to activityLog.txt if database was not created, close attempted database, and return
    */
    int rc = sqlite3_open("sheetcode.db", &db);
    if(rc != SQLITE_OK){
        fprintf(activity_log_file, "Not able to create database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 0;
    } else {
        fprintf(activity_log_file, "Database created\n"); 
    }
    /*
        Attempts to create user table;
    */
    query = "CREATE TABLE user(id INTEGER, pass TEXT, total INTEGER, easy INTEGER, medium INTEGER, hard INTEGER, recentid INTEGER);";
    rc = sqlite3_exec(db, query, 0, 0, &errMsg);
    if(rc != SQLITE_OK){
        fprintf(activity_log_file, "Failed to create user table in database: %s\n", errMsg);
        sqlite3_free(errMsg); 
        return 0;
    } else {
        fprintf(activity_log_file, "Made users table in database\n");
    }
    /*
        Attempts to create leetcodes table;
    */
    query = "CREATE TABLE leetcodes(id INTEGER, title TEXT, status INTEGER);";
    rc = sqlite3_exec(db, query, 0, 0, &errMsg);
    if(rc != SQLITE_OK){
        fprintf(activity_log_file, "Failed to create leetcodes table in database: %s\n", errMsg);
        sqlite3_free(errMsg); 
        return 0;
    } else {
        fprintf(activity_log_file, "Made leetcodes table in database\n"); 
    }
    /*
        Close databse and activityLog.txt
    */
    sqlite3_close(db);
    fclose(activity_log_file);

    return 1;
}
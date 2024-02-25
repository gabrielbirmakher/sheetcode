#include <iostream>
#include "../sqlite3/sqlite3.h"
#include "../include/setup.hpp"

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
    query = "CREATE TABLE IF NOT EXISTS user(id INTEGER, pass TEXT, total INTEGER, easy INTEGER, medium INTEGER, hard INTEGER, recentid INTEGER);";
    rc = sqlite3_exec(db, query, nullptr, nullptr, &errMsg);
    if(rc != SQLITE_OK){
        fprintf(activity_log_file, "Failed to create user table in database: %s\n", errMsg);
        sqlite3_free(errMsg); 
        sqlite3_close(db);
        return 0;
    } else {
        fprintf(activity_log_file, "Made users table in database\n");
    }
    /*
        Attempts to create leetcodes table;
    */
    query = "CREATE TABLE IF NOT EXISTS leetcodes(id INTEGER, title TEXT, status INTEGER);";
    rc = sqlite3_exec(db, query, nullptr, nullptr, &errMsg);
    if(rc != SQLITE_OK){
        fprintf(activity_log_file, "Failed to create leetcodes table in database: %s\n", errMsg);
        sqlite3_free(errMsg); 
        sqlite3_close(db);
        return 0;
    } else {
        fprintf(activity_log_file, "Made leetcodes table in database\n"); 
    }
    /*
        Checks if the user table is empty, if so, create default user
    */
    query = "SELECT COUNT(*) FROM user";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);
    if(rc != SQLITE_OK){
        fprintf(activity_log_file, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 0;
    }
    rc = sqlite3_step(stmt);
    if(rc != SQLITE_ROW){
        fprintf(activity_log_file, "sqlite3_step failed: %s\n", sqlite3_errmsg(db));
        fprintf(activity_log_file, "sqlite3_step result code: %d\n", rc);
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 0;
    }
    int count = sqlite3_column_int(stmt, 0);
    if(count == 0){
        query = "INSERT INTO user(id, pass, total, easy, medium, hard, recentid) VALUES (1, 'temp', 0, 0, 0, 0, 0)";
        rc = sqlite3_exec(db, query, nullptr, nullptr, &errMsg);
        if(rc != SQLITE_OK){
            fprintf(activity_log_file, "Failed to insert user into database: %s\n", errMsg);
            sqlite3_free(errMsg);
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return 0;
        } else {
            fprintf(activity_log_file, "User created\n");
        }
    } else if(count == 1){
        fprintf(activity_log_file, "User already exists\n");
    } else {
        fprintf(activity_log_file, "Problem with user table\n");
    }
    sqlite3_finalize(stmt);
    /*
        Close databse and activityLog.txt
    */
    sqlite3_close(db);
    fclose(activity_log_file);

    return 1;
}
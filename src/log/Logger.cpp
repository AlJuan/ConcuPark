/*
 * Logger.cpp
 *
 *  Created on: 9 de abr. de 2016
 *      Author: kevin
 */

#include "Logger.h"

string Logger::TYPE_INFO = "INFO";
string Logger::TYPE_DEBUG = "DEBUG";
string Logger::TYPE_ERROR = "ERROR";

void Logger::insert(string typeLog, string message){
	ofstream logFile;
	logFile.open("concupark.log", ios::out | ios::app | ios::binary);
	logFile << typeLog << ": " << message << endl;
	logFile.close();
}

Logger::~Logger() {
	// TODO Auto-generated destructor stub
}


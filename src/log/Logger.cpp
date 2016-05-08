/*
 * Logger.cpp
 *
 *  Created on: 9 de abr. de 2016
 *      Author: kevin
 */

#include "Logger.h"

#include <ctime>
#include <sstream>

string Logger::TYPE_INFO = "INFO";
string Logger::TYPE_DEBUG = "DEBUG";
string Logger::TYPE_ERROR = "ERROR";

void Logger::insert(string typeLog, string message){
	ofstream logFile;
	logFile.open("concupark.log", ios::out | ios::app | ios::binary);

	logFile << "["<< Logger::getDatetime() << "]" << typeLog << ": " << message << endl;
	logFile.close();
}

void Logger::insert(string typeLog, int cod){
	stringstream ss;
	ss << cod;
	insert(typeLog, ss.str());
}

string Logger::getDatetime() {
	time_t  timev;
	struct tm * timeinfo;
	time(&timev);
	char buffer[80];
	timeinfo = localtime(&timev);
	strftime(buffer,80,"%Y-%m-%d %I:%M:%S",timeinfo);

	return string(buffer);
}


Logger::~Logger() {
}


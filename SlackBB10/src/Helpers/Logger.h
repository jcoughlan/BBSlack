/*
 * Logger.h
 *
 *  Created on: 10 Mar 2014
 *      Author: James
 */

#ifndef LOGGER_H_
#define LOGGER_H_
#include <QObject>
#include <QDebug>
#include <stdio.h>
class Logger
{
public:
	static void writeOut(const char* message)
	{
		qDebug() << message << endl;
	}
};


#endif /* LOGGER_H_ */

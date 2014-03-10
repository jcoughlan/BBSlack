/*
 * SlackRequest.h
 *
 *  Created on: 10 Mar 2014
 *      Author: James
 */

#ifndef SLACKREQUEST_H_
#define SLACKREQUEST_H_
#include <QObject>
#include <QNetworkReply>
class SlackRequestManager: public QObject {
Q_OBJECT
public slots:
	void onRequestFinished(QNetworkReply* reply);
public:
	SlackRequestManager();
	~SlackRequestManager();

	void Login(QString username, QString password);

};

#endif /* SLACKREQUEST_H_ */

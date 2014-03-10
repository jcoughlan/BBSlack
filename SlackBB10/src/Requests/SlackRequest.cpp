/*
 * SlackRequest.cpp
 *
 *  Created on: 10 Mar 2014
 *      Author: James
 */
#include "SlackRequest.h"
#include "Helpers/Logger.h"
SlackRequestManager::SlackRequestManager() {
}

SlackRequestManager::~SlackRequestManager() {
}

void SlackRequestManager::Login(QString username, QString password) {
	// Creates the network request and sets the destination URL.
	QNetworkRequest request = QNetworkRequest();
	request.setUrl(QUrl("https://slack.com/api/auth.test"));

	// Create the network access manager and connect a custom slot to its
	// finished signal. Check the return value for errors.
	QNetworkAccessManager *pNetworkAccessManager = new QNetworkAccessManager(
			this);

	// If any Q_ASSERT statement(s) indicate that the slot failed to connect to
	// the signal, make sure you know exactly why this has happened. This is not
	// normal, and will cause your app to stop working!!
	bool result;

	// This is added to avoid a compiler warning.
	Q_UNUSED(result);

	result = connect(pNetworkAccessManager, SIGNAL(finished(QNetworkReply*)),
			this, SLOT(onRequestFinished(QNetworkReply*)));

	// This is only available in Debug builds.
	Q_ASSERT(result);

	// Sends the HTTP request.
	pNetworkAccessManager->get(request);
	Logger::writeOut("sent login request");
}

void SlackRequestManager::onRequestFinished(QNetworkReply* reply) {
	// Check the network reply for errors.
	Logger::writeOut("Request Returned");
	if (reply->error() == QNetworkReply::NoError) {
		Logger::writeOut("No Error");
	/*	// Open the file and print an error if the
		// file cannot be opened.
		if (!myFile->open(QIODevice::ReadWrite)) {
			// The file failed to open.
			return;
		}

		// Write to the file using the reply data and close the file.
		myFile->write(reply->readAll());
		myFile->flush();
		myFile->close();

		// Create the data model using the contents of the file.
		XmlDataModel *dataModel = new XmlDataModel();
		dataModel->setSource(QUrl("file://" + QDir::homePath() + "/model.xml"));

		// Set the new data model on the list.
		myListView->setDataModel(dataModel);*/
	} else {
		// Problem with the reply.
		// ...
	}

	// Deletes the reply the next time
	// the event loop is entered.
	reply->deleteLater();
}

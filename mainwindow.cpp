#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkProxyFactory>
#include <QRegExp>

/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);
	QNetworkProxyFactory::setUseSystemConfiguration (true);
	QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);
	QWebSettings::globalSettings()->setAttribute(QWebSettings::AutoLoadImages, true);
}

/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow() {
	delete ui;
}

/**
 * @brief MainWindow::on_loadButton_clicked
 */
void MainWindow::on_loadButton_clicked() {
	QRegExp exp("youtu(?:\\.be|be\\.com)/(?:.*v(?:/|=)|(?:.*/)?)([a-zA-Z0-9-_]+)");
	exp.indexIn(ui->textURL->text());
	if( exp.capturedTexts().length() >= 2 ) {
		QString video_url = "http://www.youtube.com/embed/";
		video_url += exp.capturedTexts().at(1);
		ui->webView->load( QUrl( video_url ));
	}
}

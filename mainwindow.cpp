#include "mainwindow.h"
#include "packagestatuswindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(QSharedPointer<Ui::MainWindow>(new Ui::MainWindow)),
    database(QSharedPointer<CourierDatabase>(new CourierDatabase))
{
    ui->setupUi(this);
    connect(ui->quit, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->status, SIGNAL(clicked()), this, SLOT(on_status_clicked()));
    connect(ui->send, SIGNAL(clicked()), this, SLOT(on_send_clicked()));

    for(auto i : {"undefined", "fast", "medium", "slow"}) {
        ui->transportComboBox->addItem(i);
    }

    for(auto i : {"undefined", "fragile", "precious", "dangerous"}) {
        ui->typeComboBox->addItem(i);
    }

    for(auto i : database->getAllDestinations()) {
        ui->client_destination_combo->addItem(i);
    }
}

MainWindow::~MainWindow()
{
    qDebug().nospace() << "~MainWindow()";
    //ui.clear();
}

void MainWindow::on_status_clicked() {
    if(!status_ui) {
        status_ui = QSharedPointer<PackageStatusWindow>(new PackageStatusWindow);
    }
    status_ui->show();
}

void MainWindow::on_send_clicked() {
    if(!confirmation_ui) {
        confirmation_ui = QSharedPointer<ConfirmationWindow>(new ConfirmationWindow);
    }
    confirmation_ui->show();
}

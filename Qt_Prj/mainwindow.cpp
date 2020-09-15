#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {

    ui->setupUi(this);
    setWindowTitle("Распределятор фотографий");
    setFixedSize(332, 265);

}

MainWindow::~MainWindow() {

    delete ui;

}

void MainWindow::on_Input_Folder_clicked() {

    QString ip = QFileDialog::getExistingDirectory(this, "Папка с фотографиями",
                                                    QDir::current().path());

    ui->InputPath->setText(ip);

}

void MainWindow::on_Output_Folder_clicked() {

    QString op = QFileDialog::getExistingDirectory(this, "Папка с каталогами",
                                                    QDir::current().path());

    ui->OutputPath->setText(op);

}

void MainWindow::on_Move_Pics_clicked() {

    QDir inputDir(ui->InputPath->text());
    QDir outputDir(ui->OutputPath->text());
    inputDir.cdUp();

    //foreach()




}

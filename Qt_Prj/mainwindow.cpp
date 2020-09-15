#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {

    ui->setupUi(this);
    setWindowTitle("Распределятор фотографий");
    setFixedSize(332, 482);

        auto fileSystemModel = new QFileSystemModel(this);
        fileSystemModel->setRootPath(QDir::rootPath());
        fileSystemModel->setReadOnly(true);

            ui->Pictures->setModel(fileSystemModel);
            ui->Folders->setModel(fileSystemModel);

}

MainWindow::~MainWindow() {

    delete ui;

}

void MainWindow::on_Input_Folder_clicked() {

    QString ip = QFileDialog::getExistingDirectory(this, "Папка с фотографиями",
                                                    QDir::current().path());

    ui->InputPath->setText(ip);

    auto fileSystemModel = new QFileSystemModel(this);
    fileSystemModel->setRootPath(QDir::rootPath());
    fileSystemModel->setReadOnly(true);

        ui->Pictures->setModel(fileSystemModel);
        ui->Pictures->setRootIndex(fileSystemModel->index(ip));

}

void MainWindow::on_Output_Folder_clicked() {

    QString op = QFileDialog::getExistingDirectory(this, "Папка с каталогами",
                                                    QDir::current().path());

    ui->OutputPath->setText(op);

    auto fileSystemModel = new QFileSystemModel(this);
    fileSystemModel->setRootPath(QDir::rootPath());
    fileSystemModel->setReadOnly(true);

        ui->Folders->setModel(fileSystemModel);
        ui->Folders->setRootIndex(fileSystemModel->index(op));

}

void MainWindow::on_Move_Pics_clicked() {

    QDir inputDir(ui->InputPath->text());
    QDir outputDir(ui->OutputPath->text());

    QStringList iDir = inputDir.entryList(QDir::Files, QDir::Name);
    QStringList oDir = outputDir.entryList(QDir::Dirs, QDir::Name);

    foreach(QString fold, oDir) {

        if (fold == "." || fold == "..") {

            continue;

        }

        foreach(QString pic, iDir) {



        }

    }

}

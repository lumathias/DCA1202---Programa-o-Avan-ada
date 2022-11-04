#include "incluirdvd.h"
#include "ui_incluirdvd.h"

IncluirDVD::IncluirDVD(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IncluirDVD)
{
    ui->setupUi(this);
}

IncluirDVD::~IncluirDVD()
{
    delete ui;
}

void IncluirDVD::clear(){
    ui->getName->setText("");
    ui->getPrice->setText("");
    ui->getDuration->setText("");
}

void IncluirDVD::signIncluirDVD (QString nome, QString preco, QString duracao){

}

void IncluirDVD::on_buttonBox_accepted()
{
    signIncluirDVD(ui->getName->text(), ui->getPrice->text(), ui->getDuration->text());
}


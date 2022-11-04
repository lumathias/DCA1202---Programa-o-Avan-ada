#include "incluircd.h"
#include "ui_incluircd.h"

IncluirCD::IncluirCD(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IncluirCD)
{
    ui->setupUi(this);
}

IncluirCD::~IncluirCD()
{
    delete ui;
}

void IncluirCD::clear(){
    ui->getName->setText("");
    ui->getPrice->setText("");
    ui->getNtracks->setText("");

}

void IncluirCD::signIncluirCD (QString nome, QString preco, QString numfaixas)
{

}

void IncluirCD::on_buttonBox_accepted()
{
    signIncluirCD(ui->getName->text(), ui->getPrice->text(), ui->getNtracks->text());
}


#include "incluirlivro.h"
#include "ui_incluirlivro.h"

IncluirLivro::IncluirLivro(QWidget *parent): QDialog(parent), ui(new Ui::IncluirLivro)
{
    ui->setupUi(this);
}

IncluirLivro::~IncluirLivro()
{
    delete ui;
}

void IncluirLivro::clear(){
    ui->getName->setText("");
    ui->getPrice->setText("");
    ui->getAuthor->setText("");
}

void IncluirLivro::signIncluirLivro (QString nome, QString preco, QString autor)
{

}

void IncluirLivro::on_buttonBox_accepted()
{
    signIncluirLivro(ui->getName->text(), ui->getPrice->text(), ui->getAuthor->text());

}


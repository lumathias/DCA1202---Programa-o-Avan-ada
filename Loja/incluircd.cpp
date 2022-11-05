#include "incluircd.h"
#include "ui_incluircd.h"

IncluirCD::IncluirCD(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IncluirCD)
{
    ui->setupUi(this);

    error_box = new QMessageBox();
    error_box->setIcon(QMessageBox::Critical);
    error_box->setWindowTitle("CD Invalido");
}

IncluirCD::~IncluirCD()
{
    delete ui;
    delete error_box;
}

void IncluirCD::clear(){
    ui->getName->setText("");
    ui->getPrice->setText("");
    ui->getNtracks->setText("");
}

void IncluirCD::on_buttonBox_accepted()
{
    nome = ui->getName->text();
    preco = ui->getPrice->text();
    numfaixas = ui->getNtracks->text();

    if(preco.toFloat() <= 0.0 || nome.isEmpty() || numfaixas.toInt() <= 0)
    {
        error_box->setText("Não foi possivel incluir o CD:\nNome = " + nome + "\n" + "Preço = " + preco +"\n" + "N Faixas= " + numfaixas);
        error_box->exec();

        return;
    }

    clear();

    emit signIncluirCD(nome, preco, numfaixas);

    this->close();
}

void IncluirCD::on_buttonBox_rejected()
{
    this->close();
}

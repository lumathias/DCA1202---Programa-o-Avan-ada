#include "incluirdvd.h"
#include "ui_incluirdvd.h"

IncluirDVD::IncluirDVD(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IncluirDVD)
{
    ui->setupUi(this);

    error_box = new QMessageBox();
    error_box->setIcon(QMessageBox::Critical);
    error_box->setWindowTitle("DVD Invalido");
}

IncluirDVD::~IncluirDVD()
{
    delete ui;
    delete error_box;
}

void IncluirDVD::clear(){
    ui->getName->setText("");
    ui->getPrice->setText("");
    ui->getDuration->setText("");
}

void IncluirDVD::on_buttonBox_accepted()
{
    nome = ui->getName->text();
    preco = ui->getPrice->text();
    duracao = ui->getDuration->text();

    if(preco.toFloat() < 0 || nome.isEmpty() || duracao.toFloat() <= 0)
    {
        error_box->setText("Não foi possivel incluir o DVD:\nNome = " + nome + "\n" + "Preço = " + preco +"\n" + "Duração = " + duracao);
        error_box->exec();

        return;
    }

    clear();

    emit signIncluirDVD(nome, preco, duracao);
}
//END

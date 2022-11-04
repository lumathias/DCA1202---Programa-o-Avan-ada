#include "incluirlivro.h"
#include "ui_incluirlivro.h"

IncluirLivro::IncluirLivro(QWidget *parent): QDialog(parent), ui(new Ui::IncluirLivro)
{
    ui->setupUi(this);

    error_box = new QMessageBox();
    error_box->setIcon(QMessageBox::Critical);
    error_box->setWindowTitle("LIVRO Invalido");
}

IncluirLivro::~IncluirLivro()
{
    delete ui;
    delete error_box;
}

void IncluirLivro::clear(){
    ui->getName->setText("");
    ui->getPrice->setText("");
    ui->getAuthor->setText("");
}

void IncluirLivro::on_buttonBox_accepted()
{
    nome = ui->getName->text();
    preco = ui->getPrice->text();
    autor = ui->getAuthor->text();

    if(preco.toFloat() < 0 || nome.isEmpty() || autor.isEmpty())
    {
        error_box->setText("Não foi possivel incluir o LIVRO:\nNome = " + nome + "\n" + "Preco = " + preco +"\n" + "Autor = " + autor);
        error_box->exec();

        return;
    }

    clear();

    emit signIncluirLivro(nome, preco, autor);
}
//END

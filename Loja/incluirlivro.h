#ifndef INCLUIRLIVRO_H
#define INCLUIRLIVRO_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class IncluirLivro;
}

class IncluirLivro : public QDialog
{
    Q_OBJECT

public:
    explicit IncluirLivro(QWidget *parent = nullptr);
    ~IncluirLivro();
    void clear();
    void signIncluirLivro (QString nome, QString preco, QString autor);


private slots:
    void on_buttonBox_accepted();

private:
    Ui::IncluirLivro *ui;

    QMessageBox  *error_box;

    QString nome;
    QString preco;
    QString autor;
};

#endif // INCLUIRLIVRO_H

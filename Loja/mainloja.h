#ifndef MAINLOJA_H
#define MAINLOJA_H

#include <iostream>

#include <incluircd.h>
#include <incluirdvd.h>
#include <incluirlivro.h>

#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <QVector>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainLoja; }
QT_END_NAMESPACE

class Produto
{
private:
    string nome;
    int preco;
public:
    /// Construtor
    Produto(const string& N="", int P=0);

    /// Funcoes de consulta
    string getNome() const;
    double getPreco() const;

    /// Funcoes de entrada/saida
    void digitar();
    void imprimir() const;

    bool ler(istream& I);
    void salvar(ostream& O) const;
};

istream& operator>>(istream& I, Produto& P);
ostream& operator<<(ostream& O, const Produto& P);

class Livro: public Produto
{
private:
    string autor;
public:
    /// Construtor
    Livro(const string& N="", int P=0, const string& A="");

    /// Funcoes de consulta
    string getAutor() const;

    /// Funcoes de entrada/saida
    void digitar();
    void imprimir() const;

    bool ler(istream& I);
    void salvar(ostream& O) const;
};

istream& operator>>(istream& I, Livro& L);
ostream& operator<<(ostream& O, const Livro& L);

class CD: public Produto
{
private:
    int nfaixas;
public:
    /// Construtor
    CD(const string& N="", int P=0, int NF=0);

    /// Funcoes de consulta
    int getNumFaixas() const;

    /// Funcoes de entrada/saida
    void digitar();
    void imprimir() const;

    bool ler(istream& I);
    void salvar(ostream& O) const;
};

istream& operator>>(istream& I, CD& C);
ostream& operator<<(ostream& O, const CD& C);

class DVD: public Produto
{
private:
    int duracao;
public:
    /// Construtor
    DVD(const string& N="", int P=0, int D=0);

    /// Funcoes de consulta
    int getDuracao() const;

    /// Funcoes de entrada/saida
    void digitar();
    void imprimir() const;

    bool ler(istream& I);
    void salvar(ostream& O) const;
};

istream& operator>>(istream& I, DVD& D);
ostream& operator<<(ostream& O, const DVD& D);

class Loja
{
private:
    vector<Livro> LL;
    vector<CD>    LC;
    vector<DVD>   LD;
public:
    /// Construtor
    Loja();

    /// Funcoes de consulta
    int getNumLivro() const;
    int getNumCD() const;
    int getNumDVD() const;
    Livro getLivro(int id) const;
    CD getCD(int id) const;
    DVD getDVD(int id) const;

    /// Funcoes de manipulacao (inclusao/exclusao) de itens do estoque
    void incluirLivro(const Livro& X);
    bool excluirLivro(int id);
    void incluirCD(const CD& X);
    bool excluirCD(int id);
    void incluirDVD(const DVD& X);
    bool excluirDVD(int id);

    /// Funcoes de entrada/saida
    bool ler(const string& arq);
    bool salvar(const string& arq) const;
    void imprimir() const;
};

class MainLoja : public QMainWindow
{
    Q_OBJECT

public:
    MainLoja(QWidget *parent = nullptr);
    ~MainLoja();

private slots:
    void on_tabela_livros_cellDoubleClicked(int row, int column);

    void on_tabela_cds_cellDoubleClicked(int row, int column);

    void on_tabela_dvds_cellDoubleClicked(int row, int column);

    void on_actionLer_triggered();

    void on_actionSalvar_triggered();

    void on_actionSair_triggered();

    void on_actionIncluir_Livro_triggered();

    void on_actionIncluir_CD_triggered();

    void on_actionIncluir_DVD_triggered();

private:
    Ui::MainLoja *ui;
    //Armazena informações do estoque, fazendo um link de Loja e MainLoja.
    Loja x;
    //Representa a janela para incluir novos arquivos
    IncluirLivro *inclLivro;
    IncluirCD *inclCD;
    IncluirDVD *inclDVD;

    QLabel *total_itens;

    //Slots para incluir objetos no estoque
    void slotIncluirLivro(QString nome, QString preco, QString autor);
    void slotIncluirCD(QString nome, QString preco, QString numfaixas);
    void slotIncluirDVD(QString nome, QString preco, QString duracao);
};

#endif // MAINLOJA_H

#ifndef LIBRO_H
#define LIBRO_H

#include <QString>

class libro
{
public:
    // Métodos getters
    libro(const QString &titulo, const QString &autor, const QString &editorial, int año, int stock);
    QString getTitulo() const;
    QString getAutor() const;
    QString getEditorial() const;
    int getAño() const;
    int getStock() const;

    // Métodos setters
    void setTitulo(const QString &titulo);
    void setAutor(const QString &autor);
    void setEditorial(const QString &editorial);
    void setAño(int año);
    void setStock(int stock);

private:
    QString m_titulo;
    QString m_autor;
    QString m_editorial;
    int m_año;
    int m_stock;
};

#endif // LIBRO_H

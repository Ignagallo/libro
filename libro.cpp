#include "libro.h"

libro::libro(const QString &titulo, const QString &autor, const QString &editorial, int año, int stock)
    : m_titulo(titulo), m_autor(autor), m_editorial(editorial), m_año(año), m_stock(stock)
{}

// Métodos getters
QString libro::getTitulo() const { return m_titulo; }
QString libro::getAutor() const { return m_autor; }
QString libro::getEditorial() const { return m_editorial; }
int libro::getAño() const { return m_año; }
int libro::getStock() const { return m_stock; }

// Métodos setters
void libro::setTitulo(const QString &titulo) { m_titulo = titulo; }
void libro::setAutor(const QString &autor) { m_autor = autor; }
void libro::setEditorial(const QString &editorial) { m_editorial = editorial; }
void libro::setAño(int año) { m_año = año; }
void libro::setStock(int stock) { m_stock = stock; }

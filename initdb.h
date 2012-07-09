#ifndef INITDB_H
#define INITDB_H

#include <QtSql>


void addBook(QSqlQuery &q, const QString &title, int year, const QVariant &authorId,
             const QVariant &genreId, int rating)
{
    q.addBindValue(title);
    q.addBindValue(year);
    q.addBindValue(authorId);
    q.addBindValue(genreId);
    q.addBindValue(rating);
    q.exec();
}

QVariant addGenre(QSqlQuery &q, const QString &name)
{
    q.addBindValue(name);
    q.exec();
    return q.lastInsertId();
}

QVariant addAuthor(QSqlQuery &q, const QString &name, const QDate &birthdate)
{
    q.addBindValue(name);
    q.addBindValue(birthdate);
    q.exec();
    return q.lastInsertId();
}

QSqlError initDb()
{
    QSqlDatabase dbtest = QSqlDatabase::addDatabase("QMYSQL");
    dbtest.setHostName("localhost");
    dbtest.setUserName("root");
    dbtest.setPassword("");
    dbtest.setDatabaseName("mysql");
    dbtest.open();
    QSqlQuery qsqltest(dbtest);
    qsqltest.exec(QString("create database if not exists libbird"));
    dbtest.close();
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("sadi");
    db.setDatabaseName("libbird");
    if (!db.open())
        return db.lastError();

    QStringList tables = db.tables();
    if (tables.contains("books", Qt::CaseInsensitive)
        && tables.contains("authors", Qt::CaseInsensitive))
        return QSqlError();

    QSqlQuery q;
    if (!q.exec(QLatin1String("CREATE TABLE books(Id INTEGER PRIMARY KEY, Title VARCHAR(100),Author VARCHAR(60),quantity INTEGER,genre integer, year integer, rating integer)")))
        return q.lastError();
    if (!q.exec(QLatin1String("create table authors(id integer primary key, name varchar(100), birthdate DATE)")))
        return q.lastError();
    if (!q.exec(QLatin1String("create table genres(id integer primary key, name varchar(100))")))
        return q.lastError();

    if (!q.prepare(QLatin1String("insert into authors(name, birthdate) values(?, ?)")))
        return q.lastError();
    QVariant schildtId = addAuthor(q, QLatin1String("herbert schildt"), QDate(1920, 2, 1));
    QVariant laforeId = addAuthor(q, QLatin1String("robert lafore"), QDate(1904, 10, 2));
    QVariant deitelId = addAuthor(q, QLatin1String("deitel "), QDate(1948, 4, 28));

    if (!q.prepare(QLatin1String("insert into genres(name) values(?)")))
        return q.lastError();
    QVariant sfiction = addGenre(q, QLatin1String("programming"));
    QVariant fiction = addGenre(q, QLatin1String("networking"));
    QVariant fantasy = addGenre(q, QLatin1String("Hardware"));

    if (!q.prepare(QLatin1String("insert into books(title, year, author, genre, rating) values(?, ?, ?, ?, ?)")))
        return q.lastError();
    addBook(q, QLatin1String("c complete reference"), 1998,schildtId, sfiction, 3);
    addBook(q, QLatin1String("Foundation and Empire"), 1952, schildtId, sfiction, 4);
    addBook(q, QLatin1String("Second Foundation"), 1953, schildtId, sfiction, 3);
    addBook(q, QLatin1String("Foundation's Edge"), 1982, schildtId, sfiction, 3);
    addBook(q, QLatin1String("Foundation and Earth"), 1986, schildtId, sfiction, 4);
    addBook(q, QLatin1String("Prelude to Foundation"), 1988, schildtId, sfiction, 3);
    addBook(q, QLatin1String("Forward the Foundation"), 1993, schildtId, sfiction, 3);
    addBook(q, QLatin1String("The Power and the Glory"), 1940, deitelId, fiction, 4);
    addBook(q, QLatin1String("The Third Man"), 1950, deitelId, fiction, 5);
    addBook(q, QLatin1String("Our Man in Havana"), 1958, deitelId, fiction, 4);
    addBook(q, QLatin1String("Guards! Guards!"), 1989, laforeId, fantasy, 3);
    addBook(q, QLatin1String("Night Watch"), 2002, laforeId,fiction, 3);
    addBook(q, QLatin1String("Going Postal"), 2004, laforeId,fantasy, 3);

    return QSqlError();
}

#endif

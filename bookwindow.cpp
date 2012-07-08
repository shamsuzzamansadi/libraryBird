 #include "bookwindow.h"
 #include "bookdelegate.h"
 #include "initdb.h"

 #include <QtSql>

 BookWindow::BookWindow()
 {
     ui.setupUi(this);

     if (!QSqlDatabase::drivers().contains("QMYSQL"))
         QMessageBox::critical(this, "Unable to load database", "This needs the MySQL driver");

     // initialize the database
     QSqlError err = initDb();
     if (err.type() != QSqlError::NoError) {
         showError(err);
         return;
     }

     // Create the data model
     model = new QSqlRelationalTableModel(ui.bookTable);
     model->setEditStrategy(QSqlTableModel::OnManualSubmit);
     model->setTable("books");

     // Remember the indexes of the columns
     authorIdx = model->fieldIndex("author");
     genreIdx = model->fieldIndex("genre");

     // Set the relations to the other database tables
     model->setRelation(authorIdx, QSqlRelation("authors", "id", "name"));
     model->setRelation(genreIdx, QSqlRelation("genres", "id", "name"));

     // Set the localized header captions
     model->setHeaderData(authorIdx, Qt::Horizontal, tr("Author Name"));
     model->setHeaderData(genreIdx, Qt::Horizontal, tr("Genre"));
     model->setHeaderData(model->fieldIndex("title"), Qt::Horizontal, tr("Title"));
     model->setHeaderData(model->fieldIndex("year"), Qt::Horizontal, tr("Year"));
     model->setHeaderData(model->fieldIndex("rating"), Qt::Horizontal, tr("Rating"));

     // Populate the model
     if (!model->select()) {
         showError(model->lastError());
         return;
     }

     // Set the model and hide the ID column
     ui.bookTable->setModel(model);
     ui.bookTable->setItemDelegate(new BookDelegate(ui.bookTable));
     ui.bookTable->setColumnHidden(model->fieldIndex("id"), true);
     ui.bookTable->setSelectionMode(QAbstractItemView::SingleSelection);

     // Initialize the Author combo box
     ui.authorEdit->setModel(model->relationModel(authorIdx));
     ui.authorEdit->setModelColumn(model->relationModel(authorIdx)->fieldIndex("name"));

     ui.genreEdit->setModel(model->relationModel(genreIdx));
     ui.genreEdit->setModelColumn(model->relationModel(genreIdx)->fieldIndex("name"));

     QDataWidgetMapper *mapper = new QDataWidgetMapper(this);
     mapper->setModel(model);
     mapper->setItemDelegate(new BookDelegate(this));
     mapper->addMapping(ui.titleEdit, model->fieldIndex("title"));
     mapper->addMapping(ui.yearEdit, model->fieldIndex("year"));
     mapper->addMapping(ui.authorEdit, authorIdx);
     mapper->addMapping(ui.genreEdit, genreIdx);
     mapper->addMapping(ui.ratingEdit, model->fieldIndex("rating"));

     connect(ui.bookTable->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
             mapper, SLOT(setCurrentModelIndex(QModelIndex)));

     ui.bookTable->setCurrentIndex(model->index(0, 0));
 }

 void BookWindow::showError(const QSqlError &err)
 {
     QMessageBox::critical(this, "Unable to initialize Database",
                 "Error initializing database: " + err.text());
 }

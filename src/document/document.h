// -*- mode: c++ -*-
// This file was automatically generated by SqlOrm
/***************************************************************************************************
 *
 * $QTCARTO_BEGIN_LICENSE:GPL3$
 *
 * Copyright (C) 2016 Fabrice Salvaire
 * Contact: http://www.fabrice-salvaire.fr
 *
 * This file is part of the QtCarto library.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * $QTCARTO_END_LICENSE$
 *
 **************************************************************************************************/

/**************************************************************************************************/

#ifndef __DOCUMENT_H__
#define __DOCUMENT_H__

/**************************************************************************************************/

#include <QBitArray>
#include <QDataStream>
#include <QDateTime>
#include <QJsonObject>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QString>
#include <QUrl>
#include <QVariant>
#include <QVariantList>
#include <QtDebug>

#include "database/schema.h"
#include "database/database_schema.h"

/**************************************************************************************************/


class DocumentSchema : public QcSchema
{
public:
  enum Fields {
    ID,
    NAME,
    AUTHOR,
    VERSION,
    DATE,
    DESCRIPTION,
    URL,
    SIZE
  };

public:
  static DocumentSchema & instance()
  {
    static DocumentSchema m_instance;
    return m_instance;
  }

  // delete copy and move constructors and assign operators
  DocumentSchema(const DocumentSchema &) = delete;              // Copy constructor
  DocumentSchema(DocumentSchema &&) = delete;                   // Move constructor
  DocumentSchema & operator=(const DocumentSchema &) = delete;  // Copy assign
  DocumentSchema & operator=(DocumentSchema &&) = delete;       // Move assign

protected:
  DocumentSchema();
  ~DocumentSchema();
};

/**************************************************************************************************/

class Document : public QObject
{
  Q_OBJECT
  Q_PROPERTY(int id READ id WRITE set_id NOTIFY idChanged)
  Q_PROPERTY(QString name READ name WRITE set_name NOTIFY nameChanged)
  Q_PROPERTY(QString author READ author WRITE set_author NOTIFY authorChanged)
  Q_PROPERTY(int version READ version WRITE set_version NOTIFY versionChanged)
  Q_PROPERTY(QDateTime date READ date WRITE set_date NOTIFY dateChanged)
  Q_PROPERTY(QString description READ description WRITE set_description NOTIFY descriptionChanged)
  Q_PROPERTY(QUrl url READ url WRITE set_url NOTIFY urlChanged)
  Q_PROPERTY(int size READ size WRITE set_size NOTIFY sizeChanged)

public:
  static DocumentSchema & schema() { return DocumentSchema::instance(); }

public:
  Document();
  Document(const Document & other);
  Document(const QJsonObject & json_object); // JSON deserializer
  Document(const QVariantHash & variant_hash);
  Document(const QVariantList & variants);
  Document(const QSqlRecord & record); // SQL deserializer
  Document(const QSqlQuery & query); // SQL deserializer
  ~Document();

  Document & operator=(const Document & other);

  bool operator==(const Document & other);

  // Getter/Setter
  
  int id() const { return m_id; }
  void set_id(int value);

  const QString & name() const { return m_name; }
  void set_name(const QString & value);

  const QString & author() const { return m_author; }
  void set_author(const QString & value);

  int version() const { return m_version; }
  void set_version(int value);

  const QDateTime & date() const { return m_date; }
  void set_date(const QDateTime & value);

  const QString & description() const { return m_description; }
  void set_description(const QString & value);

  const QUrl & url() const { return m_url; }
  void set_url(const QUrl & value);

  int size() const { return m_size; }
  void set_size(int value);

  // JSON Serializer
  QJsonObject to_json(bool only_changed = false) const;

  // Generic Variant Serializer
  QVariantHash to_variant_hash(bool only_changed = false) const;
  QVariantList to_variant_list() const;

  // SQL Serializer
  QVariantHash to_variant_hash_sql(bool only_changed = false) const;
  QVariantList to_variant_list_sql() const;

  // Query for update
  bool is_modified() const { return not m_bits.isNull(); }
  bool is_id_modified() const { return m_bits[DocumentSchema::Fields::ID]; }
  bool is_name_modified() const { return m_bits[DocumentSchema::Fields::NAME]; }
  bool is_author_modified() const { return m_bits[DocumentSchema::Fields::AUTHOR]; }
  bool is_version_modified() const { return m_bits[DocumentSchema::Fields::VERSION]; }
  bool is_date_modified() const { return m_bits[DocumentSchema::Fields::DATE]; }
  bool is_description_modified() const { return m_bits[DocumentSchema::Fields::DESCRIPTION]; }
  bool is_url_modified() const { return m_bits[DocumentSchema::Fields::URL]; }
  bool is_size_modified() const { return m_bits[DocumentSchema::Fields::SIZE]; }

  // Field accessor by position
  QVariant field(int position) const;
  void set_field(int position, const QVariant & value);

signals:
  void idChanged();
  void nameChanged();
  void authorChanged();
  void versionChanged();
  void dateChanged();
  void descriptionChanged();
  void urlChanged();
  void sizeChanged();

private:
  QBitArray m_bits;
  int m_id;
  QString m_name;
  QString m_author;
  int m_version;
  QDateTime m_date;
  QString m_description;
  QUrl m_url;
  int m_size;
};

QDataStream & operator<<(QDataStream & out, const Document & obj);
QDataStream & operator>>(QDataStream & in, Document & obj);
// qRegisterMetaTypeStreamOperators<Document>("Document");

#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug debug, const Document & obj);
#endif

/**************************************************************************************************/


class DocumentDatabaseSchema : public QcDatabaseSchema
{
public:
  DocumentDatabaseSchema(QcDatabase & database);
  DocumentDatabaseSchema(const DocumentDatabaseSchema & other) = delete;
  ~DocumentDatabaseSchema();

  DocumentDatabaseSchema & operator=(const DocumentDatabaseSchema & other) = delete;

  QcDatabaseTable * document() { return m_document; }

private:
  QcDatabaseTable * m_document;
};

/**************************************************************************************************/

#endif /* __DOCUMENT_H__ */

/***************************************************************************************************
 *
 * End
 *
 **************************************************************************************************/

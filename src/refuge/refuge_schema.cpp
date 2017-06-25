// This file was automatically generated by SqlOrm

/***************************************************************************************************
 *
 * $ALPINE_TOOLKIT_BEGIN_LICENSE:GPL3$
 *
 * Copyright (C) 2017 Fabrice Salvaire
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
 * $ALPINE_TOOLKIT_END_LICENSE$
 *
 **************************************************************************************************/

/**************************************************************************************************/

#include "refuge_schema.h"

#include "orm/type_conversion.h"

#include <QtDebug>

/**************************************************************************************************/

// QC_BEGIN_NAMESPACE


RefugeSchema::RefugeSchema()
: QcSchema(QLatin1String("Refuge"), QLatin1String("refuge"))
{
  {
    QcSchemaPrimaryKey field(
      QLatin1String("id"),
      QLatin1String("int"),
      QLatin1String("integer"),
      QLatin1String("id"),
      QLatin1String("id"),
      QLatin1String(""),
      QLatin1String(""));
    // Optional parameters
    field.set_nullable(false);
    add_field(field);
  }
  {
    QcSchemaField field(
      QLatin1String("name"),
      QLatin1String("QString"),
      QLatin1String("text"),
      QLatin1String("name"),
      QLatin1String("name"),
      QLatin1String(""),
      QLatin1String(""));
    // Optional parameters
    add_field(field);
  }
  {
    QcSchemaField field(
      QLatin1String("short_name"),
      QLatin1String("QString"),
      QLatin1String("text"),
      QLatin1String("short_name"),
      QLatin1String("short_name"),
      QLatin1String(""),
      QLatin1String(""));
    // Optional parameters
    add_field(field);
  }
  {
    QcSchemaField field(
      QLatin1String("altitude"),
      QLatin1String("int"),
      QLatin1String("integer"),
      QLatin1String("altitude"),
      QLatin1String("altitude"),
      QLatin1String(""),
      QLatin1String(""));
    // Optional parameters
    add_field(field);
  }
  {
    QcSchemaField field(
      QLatin1String("description"),
      QLatin1String("QString"),
      QLatin1String("text"),
      QLatin1String("description"),
      QLatin1String("description"),
      QLatin1String(""),
      QLatin1String(""));
    // Optional parameters
    add_field(field);
  }
  {
    QcSchemaField field(
      QLatin1String("guardian"),
      QLatin1String("QString"),
      QLatin1String("text"),
      QLatin1String("guardian"),
      QLatin1String("guardian"),
      QLatin1String(""),
      QLatin1String(""));
    // Optional parameters
    add_field(field);
  }
  {
    QcSchemaField field(
      QLatin1String("picture_path"),
      QLatin1String("QString"),
      QLatin1String("text"),
      QLatin1String("picture_path"),
      QLatin1String("picture_path"),
      QLatin1String(""),
      QLatin1String(""));
    // Optional parameters
    add_field(field);
  }
  {
    QcSchemaField field(
      QLatin1String("coordinate"),
      QLatin1String("QGeoCoordinate"),
      QLatin1String("text"),
      QLatin1String("coordinate"),
      QLatin1String("coordinate"),
      QLatin1String(""),
      QLatin1String(""));
    // Optional parameters
    add_field(field);
  }
  {
    QcSchemaField field(
      QLatin1String("number_of_places"),
      QLatin1String("QString"),
      QLatin1String("text"),
      QLatin1String("number_of_places"),
      QLatin1String("number_of_places"),
      QLatin1String(""),
      QLatin1String(""));
    // Optional parameters
    add_field(field);
  }
  {
    QcSchemaField field(
      QLatin1String("region"),
      QLatin1String("QString"),
      QLatin1String("text"),
      QLatin1String("region"),
      QLatin1String("region"),
      QLatin1String(""),
      QLatin1String(""));
    // Optional parameters
    add_field(field);
  }
  {
    QcSchemaField field(
      QLatin1String("url"),
      QLatin1String("QString"),
      QLatin1String("text"),
      QLatin1String("url"),
      QLatin1String("url"),
      QLatin1String(""),
      QLatin1String(""));
    // Optional parameters
    add_field(field);
  }
  {
    QcSchemaField field(
      QLatin1String("phone"),
      QLatin1String("QString"),
      QLatin1String("text"),
      QLatin1String("phone"),
      QLatin1String("phone"),
      QLatin1String(""),
      QLatin1String(""));
    // Optional parameters
    add_field(field);
  }
}

RefugeSchema::~RefugeSchema()
{}

/**************************************************************************************************/

Refuge::Refuge()
  : QcRow<RefugeSchema>(),
    m_id(),
    m_name(),
    m_short_name(),
    m_altitude(),
    m_description(),
    m_guardian(),
    m_picture_path(),
    m_coordinate(),
    m_number_of_places(),
    m_region(),
    m_url(),
    m_phone()
{
  post_init();
}

Refuge::Refuge(const Refuge & other)
  : QcRow<RefugeSchema>(other),
    m_id(other.m_id),
    m_name(other.m_name),
    m_short_name(other.m_short_name),
    m_altitude(other.m_altitude),
    m_description(other.m_description),
    m_guardian(other.m_guardian),
    m_picture_path(other.m_picture_path),
    m_coordinate(other.m_coordinate),
    m_number_of_places(other.m_number_of_places),
    m_region(other.m_region),
    m_url(other.m_url),
    m_phone(other.m_phone)
{
  post_init();
}

Refuge::Refuge(const QJsonObject & json_object)
 : Refuge()
{
  m_id = json_object[QLatin1String("id")].toInt();
  m_name = json_object[QLatin1String("name")].toString();
  m_short_name = json_object[QLatin1String("short_name")].toString();
  m_altitude = json_object[QLatin1String("altitude")].toInt();
  m_description = json_object[QLatin1String("description")].toString();
  m_guardian = json_object[QLatin1String("guardian")].toString();
  m_picture_path = json_object[QLatin1String("picture_path")].toString();
  m_coordinate = orm_type_conversion::load_json_coordinate(json_object[QLatin1String("coordinate")]);
  m_number_of_places = json_object[QLatin1String("number_of_places")].toString();
  m_region = json_object[QLatin1String("region")].toString();
  m_url = json_object[QLatin1String("url")].toString();
  m_phone = json_object[QLatin1String("phone")].toString();

  post_init();
}

Refuge::Refuge(const QVariantHash & variant_hash)
 : Refuge()
{
  m_id = variant_hash[QLatin1String("id")].toInt();
  m_name = variant_hash[QLatin1String("name")].toString();
  m_short_name = variant_hash[QLatin1String("short_name")].toString();
  m_altitude = variant_hash[QLatin1String("altitude")].toInt();
  m_description = variant_hash[QLatin1String("description")].toString();
  m_guardian = variant_hash[QLatin1String("guardian")].toString();
  m_picture_path = variant_hash[QLatin1String("picture_path")].toString();
  m_coordinate = variant_hash[QLatin1String("coordinate")].value<QGeoCoordinate>();
  m_number_of_places = variant_hash[QLatin1String("number_of_places")].toString();
  m_region = variant_hash[QLatin1String("region")].toString();
  m_url = variant_hash[QLatin1String("url")].toString();
  m_phone = variant_hash[QLatin1String("phone")].toString();

  post_init();
}

Refuge::Refuge(const QVariantList & variants)
 : Refuge()
{
  m_id = variants[0].toInt();
  m_name = variants[1].toString();
  m_short_name = variants[2].toString();
  m_altitude = variants[3].toInt();
  m_description = variants[4].toString();
  m_guardian = variants[5].toString();
  m_picture_path = variants[6].toString();
  m_coordinate = variants[7].value<QGeoCoordinate>();
  m_number_of_places = variants[8].toString();
  m_region = variants[9].toString();
  m_url = variants[10].toString();
  m_phone = variants[11].toString();

  post_init();
}

Refuge::Refuge(const QSqlRecord & record)
 : QcRow<RefugeSchema>(record)
{
  m_id = record.value(0).toInt();
  m_name = record.value(1).toString();
  m_short_name = record.value(2).toString();
  m_altitude = record.value(3).toInt();
  m_description = record.value(4).toString();
  m_guardian = record.value(5).toString();
  m_picture_path = record.value(6).toString();
  m_coordinate = orm_type_conversion::load_sql_coordinate(record.value(7));
  m_number_of_places = record.value(8).toString();
  m_region = record.value(9).toString();
  m_url = record.value(10).toString();
  m_phone = record.value(11).toString();

  post_init();
}

Refuge::Refuge(const QSqlQuery & query, int offset)
 : QcRow<RefugeSchema>(query)
{
  m_id = query.value(offset++).toInt();
  m_name = query.value(offset++).toString();
  m_short_name = query.value(offset++).toString();
  m_altitude = query.value(offset++).toInt();
  m_description = query.value(offset++).toString();
  m_guardian = query.value(offset++).toString();
  m_picture_path = query.value(offset++).toString();
  m_coordinate = orm_type_conversion::load_sql_coordinate(query.value(offset++));
  m_number_of_places = query.value(offset++).toString();
  m_region = query.value(offset++).toString();
  m_url = query.value(offset++).toString();
  m_phone = query.value(offset).toString();

  post_init();
}

Refuge::~Refuge()
{
// qInfo() << "--- Delete" << "Refuge" << *this;
}

// bit array ?
Refuge &
Refuge::operator=(const Refuge & other)
{
  if (this != &other) {
    QcRow<RefugeSchema>::operator=(other);
    m_id = other.m_id;
    m_name = other.m_name;
    m_short_name = other.m_short_name;
    m_altitude = other.m_altitude;
    m_description = other.m_description;
    m_guardian = other.m_guardian;
    m_picture_path = other.m_picture_path;
    m_coordinate = other.m_coordinate;
    m_number_of_places = other.m_number_of_places;
    m_region = other.m_region;
    m_url = other.m_url;
    m_phone = other.m_phone;

    post_init();
  }

  return *this;
}

// bit array ?
bool
Refuge::operator==(const Refuge & other) const
{
  if (not QcRow<RefugeSchema>::operator==(other))
    return false;
  if (m_id != other.m_id)
    return false;
  if (m_name != other.m_name)
    return false;
  if (m_short_name != other.m_short_name)
    return false;
  if (m_altitude != other.m_altitude)
    return false;
  if (m_description != other.m_description)
    return false;
  if (m_guardian != other.m_guardian)
    return false;
  if (m_picture_path != other.m_picture_path)
    return false;
  if (m_coordinate != other.m_coordinate)
    return false;
  if (m_number_of_places != other.m_number_of_places)
    return false;
  if (m_region != other.m_region)
    return false;
  if (m_url != other.m_url)
    return false;
  if (m_phone != other.m_phone)
    return false;

  return true;
}

void
Refuge::set_id(int value)
{
  if (m_id != value) {
    m_id = value;

    bool is_changed = is_modified();
    set_bit(Schema::Fields::ID);

    emit idChanged();
    if (not is_changed)
      emit changed();
  }
}

void
Refuge::set_name(const QString & value)
{
  if (m_name != value) {
    m_name = value;

    bool is_changed = is_modified();
    set_bit(Schema::Fields::NAME);

    emit nameChanged();
    if (not is_changed)
      emit changed();
  }
}

void
Refuge::set_short_name(const QString & value)
{
  if (m_short_name != value) {
    m_short_name = value;

    bool is_changed = is_modified();
    set_bit(Schema::Fields::SHORT_NAME);

    emit short_nameChanged();
    if (not is_changed)
      emit changed();
  }
}

void
Refuge::set_altitude(int value)
{
  if (m_altitude != value) {
    m_altitude = value;

    bool is_changed = is_modified();
    set_bit(Schema::Fields::ALTITUDE);

    emit altitudeChanged();
    if (not is_changed)
      emit changed();
  }
}

void
Refuge::set_description(const QString & value)
{
  if (m_description != value) {
    m_description = value;

    bool is_changed = is_modified();
    set_bit(Schema::Fields::DESCRIPTION);

    emit descriptionChanged();
    if (not is_changed)
      emit changed();
  }
}

void
Refuge::set_guardian(const QString & value)
{
  if (m_guardian != value) {
    m_guardian = value;

    bool is_changed = is_modified();
    set_bit(Schema::Fields::GUARDIAN);

    emit guardianChanged();
    if (not is_changed)
      emit changed();
  }
}

void
Refuge::set_picture_path(const QString & value)
{
  if (m_picture_path != value) {
    m_picture_path = value;

    bool is_changed = is_modified();
    set_bit(Schema::Fields::PICTURE_PATH);

    emit picture_pathChanged();
    if (not is_changed)
      emit changed();
  }
}

void
Refuge::set_coordinate(const QGeoCoordinate & value)
{
  if (m_coordinate != value) {
    m_coordinate = value;

    bool is_changed = is_modified();
    set_bit(Schema::Fields::COORDINATE);

    emit coordinateChanged();
    if (not is_changed)
      emit changed();
  }
}

void
Refuge::set_number_of_places(const QString & value)
{
  if (m_number_of_places != value) {
    m_number_of_places = value;

    bool is_changed = is_modified();
    set_bit(Schema::Fields::NUMBER_OF_PLACES);

    emit number_of_placesChanged();
    if (not is_changed)
      emit changed();
  }
}

void
Refuge::set_region(const QString & value)
{
  if (m_region != value) {
    m_region = value;

    bool is_changed = is_modified();
    set_bit(Schema::Fields::REGION);

    emit regionChanged();
    if (not is_changed)
      emit changed();
  }
}

void
Refuge::set_url(const QString & value)
{
  if (m_url != value) {
    m_url = value;

    bool is_changed = is_modified();
    set_bit(Schema::Fields::URL);

    emit urlChanged();
    if (not is_changed)
      emit changed();
  }
}

void
Refuge::set_phone(const QString & value)
{
  if (m_phone != value) {
    m_phone = value;

    bool is_changed = is_modified();
    set_bit(Schema::Fields::PHONE);

    emit phoneChanged();
    if (not is_changed)
      emit changed();
  }
}

QJsonObject
Refuge::to_json(bool only_changed) const
{
  QJsonObject json_object;

 if (only_changed) {
    if (is_id_modified())
      json_object.insert(QLatin1String("id"), QJsonValue(m_id));
    if (is_name_modified())
      json_object.insert(QLatin1String("name"), QJsonValue(m_name));
    if (is_short_name_modified())
      json_object.insert(QLatin1String("short_name"), QJsonValue(m_short_name));
    if (is_altitude_modified())
      json_object.insert(QLatin1String("altitude"), QJsonValue(m_altitude));
    if (is_description_modified())
      json_object.insert(QLatin1String("description"), QJsonValue(m_description));
    if (is_guardian_modified())
      json_object.insert(QLatin1String("guardian"), QJsonValue(m_guardian));
    if (is_picture_path_modified())
      json_object.insert(QLatin1String("picture_path"), QJsonValue(m_picture_path));
    if (is_coordinate_modified())
      json_object.insert(QLatin1String("coordinate"), orm_type_conversion::dump_json_coordinate(m_coordinate));
    if (is_number_of_places_modified())
      json_object.insert(QLatin1String("number_of_places"), QJsonValue(m_number_of_places));
    if (is_region_modified())
      json_object.insert(QLatin1String("region"), QJsonValue(m_region));
    if (is_url_modified())
      json_object.insert(QLatin1String("url"), QJsonValue(m_url));
    if (is_phone_modified())
      json_object.insert(QLatin1String("phone"), QJsonValue(m_phone));
  } else {
    json_object.insert(QLatin1String("id"), QJsonValue(m_id));
    json_object.insert(QLatin1String("name"), QJsonValue(m_name));
    json_object.insert(QLatin1String("short_name"), QJsonValue(m_short_name));
    json_object.insert(QLatin1String("altitude"), QJsonValue(m_altitude));
    json_object.insert(QLatin1String("description"), QJsonValue(m_description));
    json_object.insert(QLatin1String("guardian"), QJsonValue(m_guardian));
    json_object.insert(QLatin1String("picture_path"), QJsonValue(m_picture_path));
    json_object.insert(QLatin1String("coordinate"), orm_type_conversion::dump_json_coordinate(m_coordinate));
    json_object.insert(QLatin1String("number_of_places"), QJsonValue(m_number_of_places));
    json_object.insert(QLatin1String("region"), QJsonValue(m_region));
    json_object.insert(QLatin1String("url"), QJsonValue(m_url));
    json_object.insert(QLatin1String("phone"), QJsonValue(m_phone));
  }

  return json_object;
}

QVariantHash
Refuge::to_variant_hash(bool only_changed) const
{
  QVariantHash variant_hash;

  if (only_changed) {
    if (is_id_modified())
      variant_hash[QLatin1String("id")] = m_id;
    if (is_name_modified())
      variant_hash[QLatin1String("name")] = m_name;
    if (is_short_name_modified())
      variant_hash[QLatin1String("short_name")] = m_short_name;
    if (is_altitude_modified())
      variant_hash[QLatin1String("altitude")] = m_altitude;
    if (is_description_modified())
      variant_hash[QLatin1String("description")] = m_description;
    if (is_guardian_modified())
      variant_hash[QLatin1String("guardian")] = m_guardian;
    if (is_picture_path_modified())
      variant_hash[QLatin1String("picture_path")] = m_picture_path;
    if (is_coordinate_modified())
      variant_hash[QLatin1String("coordinate")] = QVariant::fromValue(m_coordinate);
    if (is_number_of_places_modified())
      variant_hash[QLatin1String("number_of_places")] = m_number_of_places;
    if (is_region_modified())
      variant_hash[QLatin1String("region")] = m_region;
    if (is_url_modified())
      variant_hash[QLatin1String("url")] = m_url;
    if (is_phone_modified())
      variant_hash[QLatin1String("phone")] = m_phone;
  } else {
    variant_hash[QLatin1String("id")] = m_id;
    variant_hash[QLatin1String("name")] = m_name;
    variant_hash[QLatin1String("short_name")] = m_short_name;
    variant_hash[QLatin1String("altitude")] = m_altitude;
    variant_hash[QLatin1String("description")] = m_description;
    variant_hash[QLatin1String("guardian")] = m_guardian;
    variant_hash[QLatin1String("picture_path")] = m_picture_path;
    variant_hash[QLatin1String("coordinate")] = QVariant::fromValue(m_coordinate);
    variant_hash[QLatin1String("number_of_places")] = m_number_of_places;
    variant_hash[QLatin1String("region")] = m_region;
    variant_hash[QLatin1String("url")] = m_url;
    variant_hash[QLatin1String("phone")] = m_phone;
  }

  return variant_hash;
}

QVariantList
Refuge::to_variant_list() const
{
  QVariantList variants;

  variants << m_id;
  variants << m_name;
  variants << m_short_name;
  variants << m_altitude;
  variants << m_description;
  variants << m_guardian;
  variants << m_picture_path;
  variants << QVariant::fromValue(m_coordinate);
  variants << m_number_of_places;
  variants << m_region;
  variants << m_url;
  variants << m_phone;

  return variants;
}

QVariantHash
Refuge::to_variant_hash_sql(bool only_changed, bool duplicate) const
{
  QVariantHash variant_hash;

  if (only_changed) {
    if (is_id_modified())
      variant_hash[QLatin1String("id")] = m_id;
    if (is_name_modified())
      variant_hash[QLatin1String("name")] = m_name;
    if (is_short_name_modified())
      variant_hash[QLatin1String("short_name")] = m_short_name;
    if (is_altitude_modified())
      variant_hash[QLatin1String("altitude")] = m_altitude;
    if (is_description_modified())
      variant_hash[QLatin1String("description")] = m_description;
    if (is_guardian_modified())
      variant_hash[QLatin1String("guardian")] = m_guardian;
    if (is_picture_path_modified())
      variant_hash[QLatin1String("picture_path")] = m_picture_path;
    if (is_coordinate_modified())
      variant_hash[QLatin1String("coordinate")] = orm_type_conversion::dump_sql_coordinate(m_coordinate);
    if (is_number_of_places_modified())
      variant_hash[QLatin1String("number_of_places")] = m_number_of_places;
    if (is_region_modified())
      variant_hash[QLatin1String("region")] = m_region;
    if (is_url_modified())
      variant_hash[QLatin1String("url")] = m_url;
    if (is_phone_modified())
      variant_hash[QLatin1String("phone")] = m_phone;
  } else {
    if (duplicate)
      variant_hash[QLatin1String("id")] = m_id;
    variant_hash[QLatin1String("name")] = m_name;
    variant_hash[QLatin1String("short_name")] = m_short_name;
    variant_hash[QLatin1String("altitude")] = m_altitude;
    variant_hash[QLatin1String("description")] = m_description;
    variant_hash[QLatin1String("guardian")] = m_guardian;
    variant_hash[QLatin1String("picture_path")] = m_picture_path;
    variant_hash[QLatin1String("coordinate")] = orm_type_conversion::dump_sql_coordinate(m_coordinate);
    variant_hash[QLatin1String("number_of_places")] = m_number_of_places;
    variant_hash[QLatin1String("region")] = m_region;
    variant_hash[QLatin1String("url")] = m_url;
    variant_hash[QLatin1String("phone")] = m_phone;
  }

  return variant_hash;
}

QVariantList
Refuge::to_variant_list_sql(bool duplicate) const
{
  QVariantList variants;

  if (duplicate)
    variants << m_id;
  variants << m_name;
  variants << m_short_name;
  variants << m_altitude;
  variants << m_description;
  variants << m_guardian;
  variants << m_picture_path;
  variants << orm_type_conversion::dump_sql_coordinate(m_coordinate);
  variants << m_number_of_places;
  variants << m_region;
  variants << m_url;
  variants << m_phone;

  return variants;
}

QVariant
Refuge::field(int position) const
{
  switch(position) {
   case Schema::Fields::ID:
     return m_id;
   case Schema::Fields::NAME:
     return m_name;
   case Schema::Fields::SHORT_NAME:
     return m_short_name;
   case Schema::Fields::ALTITUDE:
     return m_altitude;
   case Schema::Fields::DESCRIPTION:
     return m_description;
   case Schema::Fields::GUARDIAN:
     return m_guardian;
   case Schema::Fields::PICTURE_PATH:
     return m_picture_path;
   case Schema::Fields::COORDINATE:
     return QVariant::fromValue(m_coordinate);
   case Schema::Fields::NUMBER_OF_PLACES:
     return m_number_of_places;
   case Schema::Fields::REGION:
     return m_region;
   case Schema::Fields::URL:
     return m_url;
   case Schema::Fields::PHONE:
     return m_phone;
   default:
     return QVariant(); // error
  }
}

void
Refuge::set_field(int position, const QVariant & value)
{
  switch(position) {
   case Schema::Fields::ID: {
     m_id = value.toInt();
     break;
   }
   case Schema::Fields::NAME: {
     m_name = value.toString();
     break;
   }
   case Schema::Fields::SHORT_NAME: {
     m_short_name = value.toString();
     break;
   }
   case Schema::Fields::ALTITUDE: {
     m_altitude = value.toInt();
     break;
   }
   case Schema::Fields::DESCRIPTION: {
     m_description = value.toString();
     break;
   }
   case Schema::Fields::GUARDIAN: {
     m_guardian = value.toString();
     break;
   }
   case Schema::Fields::PICTURE_PATH: {
     m_picture_path = value.toString();
     break;
   }
   case Schema::Fields::COORDINATE: {
     m_coordinate = value.value<QGeoCoordinate>();
     break;
   }
   case Schema::Fields::NUMBER_OF_PLACES: {
     m_number_of_places = value.toString();
     break;
   }
   case Schema::Fields::REGION: {
     m_region = value.toString();
     break;
   }
   case Schema::Fields::URL: {
     m_url = value.toString();
     break;
   }
   case Schema::Fields::PHONE: {
     m_phone = value.toString();
     break;
   }
  }
}

void
Refuge::set_insert_id(int id)
{
  set_id(id);

}

bool
Refuge::can_update() const
{
  return m_id > 0;
}

QVariantHash
Refuge::rowid_kwargs() const // To update row
{
  QVariantHash where_kwargs;
  where_kwargs[QLatin1String("id")] = m_id;
  return where_kwargs;
}

QDataStream &
operator<<(QDataStream & out, const Refuge & obj)
{
  out << obj.id();
  out << obj.name();
  out << obj.short_name();
  out << obj.altitude();
  out << obj.description();
  out << obj.guardian();
  out << obj.picture_path();
  out << obj.coordinate();
  out << obj.number_of_places();
  out << obj.region();
  out << obj.url();
  out << obj.phone();

  return out;
}

QDataStream &
operator>>(QDataStream & in, Refuge & obj)
{
  QGeoCoordinate _QGeoCoordinate;
  QString _QString;
  int _int;
  in >> _int;
  obj.set_id(_int);
  in >> _QString;
  obj.set_name(_QString);
  in >> _QString;
  obj.set_short_name(_QString);
  in >> _int;
  obj.set_altitude(_int);
  in >> _QString;
  obj.set_description(_QString);
  in >> _QString;
  obj.set_guardian(_QString);
  in >> _QString;
  obj.set_picture_path(_QString);
  in >> _QGeoCoordinate;
  obj.set_coordinate(_QGeoCoordinate);
  in >> _QString;
  obj.set_number_of_places(_QString);
  in >> _QString;
  obj.set_region(_QString);
  in >> _QString;
  obj.set_url(_QString);
  in >> _QString;
  obj.set_phone(_QString);

  return in;
}

#ifndef QT_NO_DEBUG_STREAM
QDebug
operator<<(QDebug debug, const Refuge & obj)
{
  QDebugStateSaver saver(debug); // Fixme: ???

  // Fixme: quote string !
  debug.nospace() << QLatin1Literal("Refuge(");
  debug << obj.id();
  debug << QLatin1Literal(", ");
  debug << obj.name();
  debug << QLatin1Literal(", ");
  debug << obj.short_name();
  debug << QLatin1Literal(", ");
  debug << obj.altitude();
  debug << QLatin1Literal(", ");
  debug << obj.description();
  debug << QLatin1Literal(", ");
  debug << obj.guardian();
  debug << QLatin1Literal(", ");
  debug << obj.picture_path();
  debug << QLatin1Literal(", ");
  debug << obj.coordinate();
  debug << QLatin1Literal(", ");
  debug << obj.number_of_places();
  debug << QLatin1Literal(", ");
  debug << obj.region();
  debug << QLatin1Literal(", ");
  debug << obj.url();
  debug << QLatin1Literal(", ");
  debug << obj.phone();
  debug << ')';

  return debug;
}
#endif

/**************************************************************************************************/

#ifndef QT_NO_DEBUG_STREAM
QDebug
operator<<(QDebug debug, const RefugePtr & obj)
{
  QDebugStateSaver saver(debug); // Fixme: ???

  debug.noquote() << QLatin1Literal("RefugePtr ->");
  if (obj)
    debug << *obj;
   else
  debug  << QLatin1Literal("NULL");

  return debug;
}
#endif

/**************************************************************************************************/

RefugeCache::RefugeCache()
 : m_loaded_instances(),
   m_modified_instances()
{}

RefugeCache::~RefugeCache()
{}

void
RefugeCache::add(RefugePtr & ptr)
{
  m_loaded_instances.insert(ptr.data(), ptr);
  QObject::connect(ptr.data(), &Refuge::changed,
                   this, &RefugeCache::on_changed);
}

void
RefugeCache::remove(RefugePtr & ptr)
{}

void
RefugeCache::on_changed()
{
  Refuge * row = qobject_cast<Refuge *>(QObject::sender());
  qInfo() << "On changed" << row;
  RefugePtr row_ptr = m_loaded_instances[row];
  if (row_ptr)
    m_modified_instances.insert(row, row_ptr);
}

/**************************************************************************************************/

RefugeModel::RefugeModel()
  : QAbstractListModel(),
    m_items()
{}

RefugeModel::RefugeModel(const ItemList & items)
  : QAbstractListModel(),
    m_items(items)
{}

RefugeModel::~RefugeModel()
{}

int
RefugeModel::rowCount(const QModelIndex & parent) const
{
  Q_UNUSED(parent);
  return m_items.size();
}

QVariant
RefugeModel::data(const QModelIndex & index, int role) const
{
  if (!index.isValid() || index.row() < 0)
    return QVariant();

  if (index.row() >= m_items.count()) {
    qWarning() << "RefugeModel: Index out of bound";
    return QVariant();
  }

  const Item & item = m_items[index.row()];
  switch (role) {
  case ID:
    return item->id();
  case NAME:
    return item->name();
  case SHORT_NAME:
    return item->short_name();
  case ALTITUDE:
    return item->altitude();
  case DESCRIPTION:
    return item->description();
  case GUARDIAN:
    return item->guardian();
  case PICTURE_PATH:
    return item->picture_path();
  case COORDINATE:
    return QVariant::fromValue(item->coordinate());
  case NUMBER_OF_PLACES:
    return item->number_of_places();
  case REGION:
    return item->region();
  case URL:
    return item->url();
  case PHONE:
    return item->phone();
  case FIRST_LETTER:
    return item->first_letter();
  default:
    break;
  }

  return QVariant();
}

QHash<int, QByteArray>
RefugeModel::roleNames() const
{
  // Fixme: cache ???
  QHash<int, QByteArray> role_names;
  role_names[ID] = QLatin1Literal("id").latin1();
  role_names[NAME] = QLatin1Literal("name").latin1();
  role_names[SHORT_NAME] = QLatin1Literal("short_name").latin1();
  role_names[ALTITUDE] = QLatin1Literal("altitude").latin1();
  role_names[DESCRIPTION] = QLatin1Literal("description").latin1();
  role_names[GUARDIAN] = QLatin1Literal("guardian").latin1();
  role_names[PICTURE_PATH] = QLatin1Literal("picture_path").latin1();
  role_names[COORDINATE] = QLatin1Literal("coordinate").latin1();
  role_names[NUMBER_OF_PLACES] = QLatin1Literal("number_of_places").latin1();
  role_names[REGION] = QLatin1Literal("region").latin1();
  role_names[URL] = QLatin1Literal("url").latin1();
  role_names[PHONE] = QLatin1Literal("phone").latin1();
  role_names[FIRST_LETTER] = QLatin1Literal("first_letter").latin1();

  return role_names;
}

void
RefugeModel::clear_items()
{
  beginResetModel();
  m_items.clear();
  endResetModel();
}

void
RefugeModel::set_items(const ItemList & items)
{
  beginResetModel();
  m_items = items;
  endResetModel();
}
RefugeDatabaseSchema::RefugeDatabaseSchema(QcDatabase & database)
  : QcDatabaseSchema(database),
    m_refuge(nullptr),
    m_refuge_cache()
{
  m_refuge = &register_table(RefugeSchema::instance());
}

RefugeDatabaseSchema::~RefugeDatabaseSchema()
{}

template<>
void
RefugeDatabaseSchema::register_row<Refuge>(RefugePtr & row)
{
  qInfo() << "Register in cache" << row;
  m_refuge_cache.add(row);
}

/**************************************************************************************************/
// QC_END_NAMESPACE

/***************************************************************************************************
 *
 * End
 *
 **************************************************************************************************/
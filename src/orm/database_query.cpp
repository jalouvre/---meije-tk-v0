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

#include "database_query.h"

/**************************************************************************************************/

constexpr const char EQUAL[] = "=";
constexpr const char NOT_EQUAL[] = "!=";

constexpr const char LESS_THAN[] = "<";
constexpr const char GREATHER_THAN[] = ">";
constexpr const char LESS_EQUAL_THAN[] = "<=";
constexpr const char GREATHER_EQUAL_THAN[] = ">=";

constexpr const char NOT[] = "NOT";
constexpr const char AND[] = "AND";
constexpr const char OR[] = "OR";

constexpr const char MIN[] = "MIN";
constexpr const char MAX[] = "MAX";

constexpr const char AVG[] = "AVG";
constexpr const char SUM[] = "SUM";

constexpr const char COUNT[] = "COUNT";

constexpr const char LIKE[] = "LIKE";

constexpr const char IS_NULL[] = "IS NULL";
constexpr const char IS_NOT_NULL[] = "IS NOT NULL";

constexpr const char DESC[] = "DESC";
constexpr const char ASC[] = "ASC";

/**************************************************************************************************/

typedef QcSqlExpressionTraits ExpTraits;

/**************************************************************************************************/

// Fixme: multiple ...
bool
_is_alpha_string(const QString & name)
{
  for (const auto & c : name)
    if (not (c.isLetterOrNumber() or c == '_'))
        return false;
  return true;
}

QString
QcSqlExpressionTraits::quote_sql_identifier(const QString & name, SqlFlavour flavour)
{
  /*
   * 'keyword'		A keyword in single quotes is a string literal.
   * "keyword"		A keyword in double-quotes is an identifier.
   * [keyword]		A keyword enclosed in square brackets is an identifier. This is not standard SQL.
   *                      This quoting mechanism is used by MS Access and SQL Server.
   * `keyword`		A keyword enclosed in grave accents (ASCII code 96) is an identifier. This is not standard SQL.
   *                      This quoting mechanism is used by MySQL and is included in SQLite for compatibility.
   */

  // Only quote when necessary
  if (_is_alpha_string(name))
    return name;

  switch (flavour) {
  case SqlFlavour::MySQL:
    return '`' + name + '`';
  case SqlFlavour::SQL_Server:
    return '[' + name + ']';
  default:
    return '"' + name + '"';
  }
}

QString
QcSqlExpressionTraits::to_sql(const QVariant & value)
{
  if (value.type() == QVariant::String)
    return QLatin1String("'") + value.toString() + QLatin1String("'");
  else
    return value.toString();
}

QString
QcSqlExpressionTraits::comma_join(const QStringList & strings)
{
  return strings.join(QLatin1String(", "));
}

QString
QcSqlExpressionTraits::comma_join(const QcSqlExpressionList & expressions, SqlFlavour flavour)
{
  QStringList strings;

  for (const auto & expression : expressions)
    strings << expression->to_sql(flavour);

  return comma_join(strings);
}

/**************************************************************************************************/

QcSqlField::QcSqlField(const QString & name)
  : m_name(name),
    m_table_name()
{}

QcSqlField::QcSqlField(const QString & name, const QString & table_name)
  : m_name(name),
    m_table_name(table_name)
{}

QcSqlField::QcSqlField(const QcSqlField & other)
  : m_name(other.m_name),
    m_table_name(other.m_table_name)
{}

QcSqlField &
QcSqlField::operator=(const QcSqlField & other)
{
  if (this != &other) {
    m_name = other.m_name;
    m_table_name = other.m_table_name;
  }

  return *this;
}

QcSqlField::~QcSqlField()
{}

QString
QcSqlField::to_sql(SqlFlavour flavour) const
{
  QString name = m_table_name.isEmpty() ? m_name : m_table_name + '.' + m_name;
  return quote_sql_identifier(name, flavour);
}

QString
QcSqlField::as(const QString & name, SqlFlavour flavour) const
{
  return to_sql(flavour) + QLatin1String(" AS ") + name;
}

QString
QcSqlField::as(SqlFlavour flavour) const
{
  QString name = m_table_name + '_' + m_name;
  return as(name, flavour);
}

/**************************************************************************************************/

QcSqlFieldExpressionTwoValue::QcSqlFieldExpressionTwoValue(const QcSqlField & field,
                                                           const QVariant & value1,
                                                           const QVariant & value2)
  : m_field(field),
    m_value1(value1),
    m_value2(value2)
{}

/**************************************************************************************************/

QcSqlFieldExpressionValueList::QcSqlFieldExpressionValueList(const QcSqlField & field,
                                                             const QVariantList & values)
  : m_field(field),
    m_values(values)
{}

QStringList
QcSqlFieldExpressionValueList::string_values() const
{
  QStringList strings;
  for (const auto & value : m_values)
    strings << to_sql(value);

  return strings;
}

/**************************************************************************************************/

QString
QcSqlInExpression::to_sql(SqlFlavour flavour) const
{
  return m_field.to_sql(flavour) +
    QLatin1String(" IN (") + comma_join(string_values()) + + ')';
}

/**************************************************************************************************/

QString
QcSqlBetweenExpression::to_sql(SqlFlavour flavour) const
{
  return m_field.to_sql(flavour) + QLatin1String(" BETWEEN ") +
    ExpTraits::to_sql(m_value1) + QLatin1String(" AND ") + ExpTraits::to_sql(m_value2);
}

/**************************************************************************************************/

QcSqlExpressionPtr
QcSqlField::operator==(const QVariant & value) const
{
  return QcSqlExpressionPtr(new QcSqlFieldExpression<EQUAL>(*this, value));
}

QcSqlExpressionPtr
QcSqlField::operator!=(const QVariant & value) const
{
  return QcSqlExpressionPtr(new QcSqlFieldExpression<NOT_EQUAL>(*this, value));
}

QcSqlExpressionPtr
QcSqlField::operator>(const QVariant & value) const
{
  return QcSqlExpressionPtr(new QcSqlFieldExpression<GREATHER_THAN>(*this, value));
}

QcSqlExpressionPtr
QcSqlField::operator<(const QVariant & value) const
{
  return QcSqlExpressionPtr(new QcSqlFieldExpression<LESS_THAN>(*this, value));
}

QcSqlExpressionPtr
QcSqlField::operator>=(const QVariant & value) const
{
  return QcSqlExpressionPtr(new QcSqlFieldExpression<GREATHER_EQUAL_THAN>(*this, value));
}

QcSqlExpressionPtr
QcSqlField::operator<=(const QVariant & value) const
{
  return QcSqlExpressionPtr(new QcSqlFieldExpression<LESS_EQUAL_THAN>(*this, value));
}

QcSqlExpressionPtr
QcSqlField::in(const QVariantList & values) const
{
  return QcSqlExpressionPtr(new QcSqlInExpression(*this, values));
}

QcSqlExpressionPtr
QcSqlField::between(const QVariant & value_min, const QVariant & value_max) const
{
  return QcSqlExpressionPtr(new QcSqlBetweenExpression(*this, value_min, value_max));
}

QcSqlExpressionPtr
QcSqlField::like(const QString & pattern) const
{
  return QcSqlExpressionPtr(new QcSqlFieldExpression<LIKE>(*this, pattern));
}

QcSqlExpressionPtr
QcSqlField::is_null() const
{
  return QcSqlExpressionPtr(new QcSqlFieldSuffixExpression<IS_NULL>(*this));
}

QcSqlExpressionPtr
QcSqlField::is_not_null() const
{
  return QcSqlExpressionPtr(new QcSqlFieldSuffixExpression<IS_NOT_NULL>(*this));
}

QcSqlExpressionPtr
QcSqlField::desc() const
{
  return QcSqlExpressionPtr(new QcSqlFieldSuffixExpression<DESC>(*this));
}

QcSqlExpressionPtr
QcSqlField::asc() const
{
  return QcSqlExpressionPtr(new QcSqlFieldSuffixExpression<ASC>(*this));
}

/**************************************************************************************************/

/*
QcSqlExpressionPtr
operator!(const QcSqlExpressionPtr & expression)
{
  return QcSqlExpressionPtr(new QcSqlUnaryExpression<NOT>(expression));
}
*/

QcSqlExpressionPtr
Not(const QcSqlExpressionPtr & expression)
{
  return QcSqlExpressionPtr(new QcSqlUnaryExpression<NOT>(expression));
}

QcSqlExpressionPtr
Count(const QcSqlExpressionPtr & expression)
{
  return QcSqlExpressionPtr(new QcSqlUnaryExpression<COUNT>(expression));
}

QcSqlExpressionPtr
Min(const QcSqlExpressionPtr & expression)
{
  return QcSqlExpressionPtr(new QcSqlUnaryExpression<MIN>(expression));
}

QcSqlExpressionPtr
Max(const QcSqlExpressionPtr & expression)
{
  return QcSqlExpressionPtr(new QcSqlUnaryExpression<MAX>(expression));
}

QcSqlExpressionPtr
Avg(const QcSqlExpressionPtr & expression)
{
  return QcSqlExpressionPtr(new QcSqlUnaryExpression<AVG>(expression));
}

QcSqlExpressionPtr
Sum(const QcSqlExpressionPtr & expression)
{
  return QcSqlExpressionPtr(new QcSqlUnaryExpression<SUM>(expression));
}

/**************************************************************************************************/

QcSqlExpressionPtr operator&&(const QcSqlExpressionPtr & expression1,
                              const QcSqlExpressionPtr & expression2)
{
  return QcSqlExpressionPtr(new QcSqlBinaryExpression<AND>(expression1, expression2));
}

QcSqlExpressionPtr operator||(const QcSqlExpressionPtr & expression1,
                              const QcSqlExpressionPtr & expression2)
{
  return QcSqlExpressionPtr(new QcSqlBinaryExpression<OR>(expression1, expression2));
}

/**************************************************************************************************/

QcSqlQuery::QcSqlQuery()
  : m_table_name(),
    m_flags(static_cast<int>(Flags::NumberOfFlags)),
    m_fields(),
    m_where(nullptr),
    m_group_by(),
    m_order_by()
{}

QcSqlQuery::QcSqlQuery(const QString & table_name)
  : m_table_name(table_name),
    m_flags(static_cast<int>(Flags::NumberOfFlags)),
    m_fields(),
    m_where(nullptr),
    m_group_by(),
    m_order_by()
{}

/*
QcSqlQuery::QcSqlQuery(const QcSqlTable & table)
  : m_table_name(table.table_name())
{}
*/

QcSqlQuery::QcSqlQuery(const QcSqlQuery & other)
  : m_table_name(other.m_table_name),
    m_query_type(other.m_query_type),
    m_select_type(other.m_select_type),
    m_flags(other.m_flags),
    m_fields(other.m_fields),
    m_where(other.m_where),
    m_group_by(other.m_group_by),
    m_having(other.m_having),
    m_order_by(other.m_order_by),
    m_limit(other.m_limit),
    m_offset(other.m_offset)
{}

QcSqlQuery::~QcSqlQuery()
{}

QcSqlQuery &
QcSqlQuery::operator=(const QcSqlQuery & other)
{
  if (this != &other) {
    m_table_name = other.m_table_name;
    m_query_type = other.m_query_type;
    m_select_type = other.m_select_type;
    m_flags = other.m_flags;
    m_fields = other.m_fields;
    m_where = other.m_where;
    m_group_by = other.m_group_by;
    m_having = other.m_having;
    m_order_by = other.m_order_by;
    m_limit = other.m_limit;
    m_offset = other.m_offset;
  }

  return *this;
}

QcSqlQuery &
QcSqlQuery::distinct()
{
  m_query_type = QueryType::Select;
  set_flags(Flags::SelectDistinct);

  return *this;
}

QcSqlQuery &
QcSqlQuery::count()
{
  m_query_type = QueryType::Select;
  set_flags(Flags::SelectCount);

  return *this;
}

QcSqlQuery &
QcSqlQuery::exists()
{
  m_query_type = QueryType::Select;
  set_flags(Flags::SelectExists);

  return *this;
}

QcSqlQuery &
QcSqlQuery::delete_()
{
  m_query_type = QueryType::Delete;

  return *this;
}

QcSqlQuery &
QcSqlQuery::add_column(const QcSqlField & field)
{
  m_fields << field;

  return *this;
}

QcSqlQuery &
QcSqlQuery::filter(const QcSqlExpressionPtr & expression)
{
  if (m_where.isNull())
    m_where = expression;
  else
    m_where = m_where and expression;

  return *this;
}

QcSqlQuery &
QcSqlQuery::group_by(const QcSqlField & field)
{
  m_group_by << field;

  return *this;
}

QcSqlQuery &
QcSqlQuery::having(const QcSqlExpressionPtr & expression)
{
  m_having = expression;

  return *this;
}

QcSqlQuery &
QcSqlQuery::order_by(const QcSqlExpressionPtr & expression)
{
  m_order_by << expression;

  return *this;
}

QcSqlQuery &
QcSqlQuery::limit(int value)
{
  m_limit = value;
  m_query_type = QueryType::Select;
  m_select_type = SelectType::None;

  return *this;
}

QcSqlQuery &
QcSqlQuery::offset(int value)
{
  m_offset = value;
  m_query_type = QueryType::Select;
  // m_select_type = SelectType::None;

  return *this;
}

QcSqlQuery &
QcSqlQuery::slice(int start, int stop)
{
  m_offset = start;
  m_limit = stop - start;

  m_query_type = QueryType::Select;
  m_select_type = SelectType::None;

  return *this;
}

QcSqlQuery &
QcSqlQuery::one()
{
  m_limit = 1;
  m_select_type = SelectType::SelectOne;

  return *this;
}

QStringList
QcSqlQuery::field_names(const FieldList & fields) const
{
  SqlFlavour flavour = sql_flavour();
  QStringList field_names;

  for (const auto & field : fields)
    field_names << field.to_sql(flavour);

  return field_names;
}

QStringList
QcSqlQuery::fields_for_update() const
{
  SqlFlavour flavour = sql_flavour();
  QStringList field_names;

  for (const auto & field : m_fields)
    field_names << field.to_sql(flavour) + QLatin1String(" = ?");

  return field_names;
}

QString
QcSqlQuery::comma_interrogation_list(int count)
{
  QString query;

  int i_last = count -1;
  for (int i = 0; i <= i_last; i++) {
    query += '?';
    if (i < i_last)
      query += QLatin1String(", ");
  }

  return query;
}

QString
QcSqlQuery::table_name_as(const QString & name) const
{
  return quote_sql_identifier(m_table_name) + QLatin1String(" AS ") + name;
}

QString
QcSqlQuery::to_sql() const
{
  /*
   * SELECT *
   * FROM table
   * WHERE condition
   * GROUP BY expression
   * HAVING condition
   * { UNION | INTERSECT | EXCEPT }
   * ORDER BY expression
   * LIMIT count
   * OFFSET start
   */

  QString query;

  if (m_query_type == QueryType::None)
    return query;

  SqlFlavour flavour = sql_flavour();

  switch (m_query_type) {
  case QueryType::Select: query = QLatin1String("SELECT"); break;
  case QueryType::Insert: query = QLatin1String("INSERT"); break;
  case QueryType::Update: query = QLatin1String("UPDATE"); break;
  case QueryType::Delete: query = QLatin1String("DELETE"); break;
  }

  if (get_flags(Flags::SelectCount))
    // Generates the SQL for this Query as follows:
    // SELECT count(1) AS count_1 FROM (
    //   SELECT <rest of query follows...>
    // ) AS anon_1
    query += QLatin1String("SELECT count(1) AS count_1 FROM ( SELECT ");

  if (get_flags(Flags::SelectExists))
    // Generates the SQL for this Query as follows:
    // SELECT EXISTS FROM (
    //   SELECT <rest of query follows...>
    // ) AS anon_1
    query += QLatin1String("SELECT EXISTS ( SELECT ");

  if (m_query_type == QueryType::Select and
      get_flags(Flags::SelectDistinct)) {
    if (flavour == SqlFlavour::Oracle)
      query += QLatin1String(" UNIQUE");
    else
      // Fixme: PostgreSQL: DISTINCT ON
      query += QLatin1String(" DISTINCT");
  }

  query += ' ';

  if (m_query_type == QueryType::Select) {
    if (m_fields.isEmpty())
      query += '*';
    else
      query += ExpTraits::comma_join(field_names(m_fields));
  }

  if (m_query_type == QueryType::Select)
      query += ' ';

  if (m_query_type == QueryType::Select or
      m_query_type == QueryType::Delete) {
    query += QLatin1String("FROM");
  }

  if (m_query_type == QueryType::Insert)
    query += QLatin1String(" INTO");

  query += ' '  + quote_sql_identifier(m_table_name);

  if (m_query_type == QueryType::Update) {
    query += QLatin1String(" Set ");
      query += ExpTraits::comma_join(fields_for_update());
  }

  if (m_query_type == QueryType::Insert) {
    query += '(';
    query += ExpTraits::comma_join(field_names(m_fields));
    query += QLatin1String(") VALUES (");
    query += comma_interrogation_list(m_fields.size());
    query += ')';
  } else { // Not INSERT
    if (not m_where.isNull()) {
      query += QLatin1String(" WHERE ");
      query += m_where->to_sql(flavour);
    }
  }

  if (m_query_type == QueryType::Select) {
    if (not m_group_by.isEmpty())
      query += QLatin1String(" GROUP BY ") + ExpTraits::comma_join(field_names(m_group_by));

    if (not m_having.isNull())
      query += QLatin1String(" HAVING ") + m_having->to_sql(flavour);

    if (not m_order_by.isEmpty())
      query += QLatin1String(" ORDER BY ") + ExpTraits::comma_join(m_order_by, flavour);

    // MySQL syntax: LIMIT limit, offset
    // but also support ANSI
    if (m_limit > 0)
      query += QLatin1String(" LIMIT ") + m_limit; // ?
    if (m_offset > 0)
      query += QLatin1String(" OFFSET ") + m_offset; // ?
  }

  if (get_flags(Flags::SelectCount) or
      get_flags(Flags::SelectExists))
    query += QLatin1String(") AS anon_1)");

  query += ';';

  return query;
}

/**************************************************************************************************/

/*
QString
QcMySqlQuery::quote_sql_identifier(const QString & name) const
{
  return '`' + name + '`';
}

QString
QcSqlServerQuery::quote_sql_identifier(const QString & name) const
{
  return '[' + name + ']';
}
*/

/***************************************************************************************************
 *
 * End
 *
 **************************************************************************************************/

#include "dataobjectmodel.h"

/*!
  \class DataObjectModel
  \brief The DataObjectModel class provides a QAbstractListModel-based
  implementation of a  more flexible model that allows taking in any
  object of type QObject
*/

/*!
 * \fn DataObjectModel::DataObjectModel(QObject *parent = nullptr)
 * Construct an DataObjectModel with \a parent
 */
DataObjectModel::DataObjectModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

/*!
 * \brief DataObjectModel::registerTypes
 * \internal
 */
void DataObjectModel::registerTypes(const char *uri)
{
    qmlRegisterType<DataObjectModel>(uri, 1, 0, "DataObjectModel");
}

/*!
 * \brief DataObjectModel::rowCount
 * \internal
 */
int DataObjectModel::rowCount(const QModelIndex &p) const
{
    Q_UNUSED(p)
    return m_data.size();
}

/*!
 * \brief DataObjectModel::data
 * \internal
 */
QVariant DataObjectModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(role)
    return QVariant::fromValue(m_data[index.row()]);
}

/*!
 * \brief DataObjectModel::roleNames
 * \internal
 */
QHash<int, QByteArray> DataObjectModel::roleNames() const
{
    static QHash<int, QByteArray> *pHash;
    if (!pHash) {
        pHash = new QHash<int, QByteArray>;
        (*pHash)[Qt::UserRole + 1] = "dataObject";
    }
    return *pHash;
}

/*!
 * \property DataObjectModel::count
 * \brief The total count of the number of items in the model
 */
int DataObjectModel::count() const
{
    return m_data.count();
}

/*!
 * \fn void DataObjectModel::append(QObject* o)
 * Append an object \a o to this model
 */
void DataObjectModel::append(QObject *o) {
    int i = m_data.size();
    beginInsertRows(QModelIndex(), i, i);
    m_data.append(o);

    // Emit changed signals
    emit countChanged(count());

    endInsertRows();
}

/*!
 * \fn void DataObjectModel::insert(QObject* o, int i)
 * Insert an object \a o to this model at position \a i
 */
void DataObjectModel::insert(QObject *o, int i)
{
    beginInsertRows(QModelIndex(), i, i);
    m_data.insert(i, o);
    o->setParent(this);

    // Emit changed signals
    emit countChanged(count());

    endInsertRows();
}


/*!
 * \fn QObject* DataObjectModel::get(int i)
 * Returns an object at index \a i
 */
QObject* DataObjectModel::get(int i)
{
    Q_ASSERT(i >= 0 && i <= m_data.count());
    return m_data[i];
}

/*!
 * \fn QQmlListProperty<QObject> DataObjectModel::content()
 * The default property of this class. All QML-based children will be automatically
 * filtered through the methods associated to the QQmlListProperty
 */
QQmlListProperty<QObject> DataObjectModel::content()
{
    return QQmlListProperty<QObject>(this,
                                     0,
                                     &DataObjectModel::dataObjectAppend,
                                     &DataObjectModel::dataObjectCount,
                                     &DataObjectModel::dataObjectAt,
                                     &DataObjectModel::dataObjectClear);
}

/*!
 * \brief DataObjectModel::dataObjectAppend
 * \internal
 */
void DataObjectModel::dataObjectAppend(QQmlListProperty<QObject> *list, QObject *o)
{
    DataObjectModel *dom = qobject_cast<DataObjectModel*>(list->object);
    if (dom && o) {
        dom->m_data.append(o);
    }
}

/*!
 * \brief DataObjectModel::dataObjectCount
 * \internal
 */
int DataObjectModel::dataObjectCount(QQmlListProperty<QObject> *list)
{
    DataObjectModel *dom = qobject_cast<DataObjectModel*>(list->object);
    if (dom) {
        return dom->m_data.count();
    }
    return 0;
}

/*!
 * \brief DataObjectModel::dataObjectAt
 * \internal
 */
QObject *DataObjectModel::dataObjectAt(QQmlListProperty<QObject> *list, int i)
{
    DataObjectModel *dom = qobject_cast<DataObjectModel*>(list->object);
    if (dom) {
        return dom->m_data.at(i);
    }
    return 0;
}

/*!
 * \brief DataObjectModel::dataObjectClear
 * \internal
 */
void DataObjectModel::dataObjectClear(QQmlListProperty<QObject> *list)
{
    DataObjectModel *dom = qobject_cast<DataObjectModel*>(list->object);
    if (dom) {
        dom->m_data.clear();
    }
}

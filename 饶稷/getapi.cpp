#include <QString>
#include <QUrl>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

// 给定表名和方法以及查询json，返回完整的url
/* 使用方法：
    QString tableName = "EmployeeInfo";
    QString method = "Get";
    QString queryString = "{\"attribute\": \"value\"}";

    QString apiUrl = buildApiUrl(tableName, method, queryString);*/
QString buildApiUrl(const QString &tableName, const QString &method, const QString &queryString)
{
    QString baseUrl = "http://8.130.119.222:1234/api/";
    QString fullUrl = baseUrl + tableName + "/" + method + "/" + queryString;
    return fullUrl;
}


// 给定一系列属性及值，用于生成查询json
/* 使用方法：
    QHash<QString, QVariant> attributes;
    attributes.insert("name", "John");
    attributes.insert("age", 30);
    attributes.insert("position", "Developer");

    QString jsonString = createJsonString(attributes);*/
QString createJsonString(const QHash<QString, QVariant> &data)
{
    QJsonObject jsonObject;

    // 将属性和值添加到 JSON 对象中
    for (const QString &key : data.keys()) {
        jsonObject[key] = QJsonValue::fromVariant(data.value(key));
    }

    // 创建 JSON 文档
    QJsonDocument jsonDocument(jsonObject);

    // 将 JSON 文档转换为字符串
    return jsonDocument.toJson(QJsonDocument::Compact);
}

// 用于QString转base64的QByteArray形式
/* 使用方法：
 * QByteArray encodedData = stringToBase64("helloworld"); */
QByteArray stringToBase64(QString str)
{
    return str.toUtf8().toBase64();
}

// 用于QByteArray形式的base64转QString
/* 使用方法：
 * QByteArray encodedData = stringToBase64("helloworld");
 * QString decodedData = base64ToString(encodedData); */
QString base64ToString(QByteArray array)
{
    QByteArray decodedData = QByteArray::fromBase64(array);
    return QString::fromUtf8(decodedData);
}

// 用于将后端发来的json数组字符串转化为QJsonArray形式：
/* 使用方法：
 *  QJsonArray jsonArray = parseJsonArray(jsonArrayString);  // 获取QJsonArray形式
    for (const QJsonValue &jsonValue : jsonArray) {  // 遍历其中每一个jsonObject
        if (jsonValue.isObject()) {
            QJsonObject jsonObject = jsonValue.toObject();
            qDebug() << "JSON Object:" << jsonObject;
        }
*/
QJsonArray parseJsonArray(const QString &jsonArrayString) {
    QJsonArray jsonArray;

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonArrayString.toUtf8());
    if (jsonDoc.isArray()) {
        jsonArray = jsonDoc.array();
    } else {
        qWarning() << "JSON document is not an array.";
    }

    return jsonArray;
}

// 从发回的jsonArrayString中读取信息，个数不会多于1个
/* 使用方法：
 * QJsonObject personinfo = ResultGet(result);
   */
QJsonObject ResultGet(const QString &jsonArrayString)
{
    QJsonArray jsonArray = parseJsonArray(jsonArrayString);
    if(jsonArray.isEmpty()){
        qWarning() << "no myInformation";
        return QJsonObject();
    }
    return jsonArray.at(0).toObject();
}

// 给定Get方法的url，获取从后端发回的数据
/* 使用方法：
   QByteArray responseData = fetchDataFromUrl(url); */
QByteArray fetchDataFromUrl(const QString &urlString)
{
    QNetworkAccessManager manager;
    QNetworkRequest request((QUrl(urlString)));

    QNetworkReply *reply = manager.get(request);
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() != QNetworkReply::NoError) {
        qWarning() << "Network request error:" << reply->errorString();
        return QByteArray();
    }

    QByteArray data = reply->readAll();
    reply->deleteLater();

    return data;
}

// 用于myInformation界面，给定工号，返回一系列信息的Api
/* 使用方法：
 * QString Api = myInformationApiGet("e0001"); */
QString myInformationApiGet(QString eid)
{
    QHash<QString, QVariant> attributes;

    attributes.insert("EmployeeID", eid);
    QString jsonString = createJsonString(attributes);  // 获取查询json
    return buildApiUrl("FundamentalInfo", "Get", jsonString);
}

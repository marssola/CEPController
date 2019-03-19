#include "cepcontroller.h"
#include <cwf/sqlquery.h>
#include <cwf/urlencoder.h>

void CEPController::doGet(CWF::Request &req, CWF::Response &resp) const
{
    CWF::SqlQuery query(conexao.getDatabase());
    qint32 logr_id = req.getParameter("logr_id").toInt();
    if (logr_id) {
        query.prepare("SELECT * FROM logradouro WHERE logr_id=:logr_id");
        query.bindValue(":logr_id", logr_id);
        query.exec();
    } else {
        query.exec("SELECT * FROM logradouro");
    }
    resp.write(query.toJson());
}

void CEPController::doPost(CWF::Request &req, CWF::Response &resp) const
{
    CWF::SqlQuery query(conexao.getDatabase());
    resp.write(query.insertFromJson(req.bodyToJsonObject(), "logradouro"));
}

void CEPController::doPut(CWF::Request &req, CWF::Response &resp) const
{
    CWF::SqlQuery query(conexao.getDatabase());
    QJsonObject obj = req.bodyToJsonObject();
    QString logr_id = QString("%1").arg(obj.take("logr_id").toInt());
    obj.remove("logr_id");
    resp.write(query.updateFromJson(obj, "logradouro", QString("logr_id=%1").arg(logr_id)));
}

void CEPController::doDelete(CWF::Request &req, CWF::Response &resp) const
{
    CWF::SqlQuery query(conexao.getDatabase());
    resp.write(query.deleteRecord("logradouro", QString("logr_id=%1").arg(req.getParameter("logr_id").toInt())));
}

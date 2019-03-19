#ifndef CEPCONTROLLER_H
#define CEPCONTROLLER_H

#include <QObject>
#include <cwf/controller.h>
#include <cwf/sqldatabasestorage.h>
#include <cwf/request.h>
#include <cwf/response.h>

extern CWF::SqlDatabaseStorage conexao;

class CEPController : public CWF::Controller
{
public:
    void doGet(CWF::Request &req, CWF::Response &resp) const override;
    void doPost(CWF::Request &req, CWF::Response &resp) const override;
    void doPut(CWF::Request &req, CWF::Response &resp) const override;
    void doDelete(CWF::Request &req, CWF::Response &resp) const override;
};

#endif // CEPCONTROLLER_H

#include <cwf/cppwebapplication.h>
#include <cwf/sqldatabasestorage.h>
#include "./cepcontroller.h"

CWF::SqlDatabaseStorage conexao("QPSQL", "localhost", "cepcontroller", "marssola", "", 5432);

int main(int argc, char *argv[])
{
    CWF::CppWebApplication server(argc, argv, "../CEPController/server");
    server.addController<CEPController>("/api/cep");
    return server.start();
}

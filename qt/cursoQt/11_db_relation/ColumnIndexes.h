#ifndef COLUMNINDEXES_H
#define COLUMNINDEXES_H

struct ColumnIndexes
{
	// números(índices) de colunas para clientes:
	int cliId;
	int cliNome ;
	int cliCidade;
	int cliContato;

	// números(índices) de colunas para movimentos:
	int movId;
	int movClienteId;
	int movTipoId;
	int movDate;
	int movDescription;
};

#endif // COLUMNINDEXES_H

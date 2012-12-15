#ifndef APPPROTOCOL_H
#define APPPROTOCOL_H

namespace AppProto
{
	typedef quint32 BlockSize_t ;
	
	// comandos ou requisições aceitas pelo server:
	typedef quint16 RequestType_t;
	
	const RequestType_t invalidCommand = 0;
	// requisições validas:
	const RequestType_t showMessage = 1;
	const RequestType_t execProcess = 2;
}
#endif // APPPROTOCOL_H

#ifndef TCPDATAPROTOCOL_H
#define TCPDATAPROTOCOL_H

#include <QtGlobal>  // definições gerais, como é o caso dos tipos primitivos padronizados em Qt

// Definições comuns para o server e para o cliente.

// Neste exemplo, precisamos apenas de um protocolo para a camada de aplicação da suíte de protocolos TCP/IP.
// Este protocolo de aplicação indica quais solicitações(e dados) o server espera receber de um client.

namespace TcpDataProtocol
{
	typedef quint16 requestType;
	typedef quint32 requestSizeType;

	const requestType showMessage = 1;  // o server deve exibir uma mensagem (tendo como argumento um texto)
	const requestType startProcess = 2;    // o server deve iniciar um processo (tendo como argumento um nome de binário executável)


}



#endif // TCPDATAPROTOCOL_H

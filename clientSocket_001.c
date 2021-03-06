/*
Primo esempio di codice in linguaggio C per programmare una socket TCP lato client
Il codice e' stato composto con finalità didattiche

Autore: Paolo Mangraviti
Verrsione 1.0 14 ottobre 2018 - per sistemi operativi linux/unix like

*/

#include <stdio.h> /* per le funzioni printf() and fprintf() */
#include <sys/socket.h> /* per le funzioni socket(), bind(), connect(), recv() and send() */
#include <arpa/inet.h> /* per la struttura sockaddr_in e la funzione inet_ntoa() */
#include <stdlib.h> /* per le funzioni atoi() and exit() */
#include <string.h> /* per le funzioni memset() */
#include <unistd.h> /* per le funzioni close() */
#define RCVBUFSIZE 32 /* dimesione del buffer di ricezione */

/* Funzione per visualizzare sulla console i messaggi di errore */
void ErrorHandler(char *errorMessage)
{
    fprintf(stderr,"%s",errorMessage);
    exit(1);
} /* Error handling function */

/* -------------------------------------------------------- */
/* -------------------------------------------------------- */
/* Funzione Principale */
int main(int argc, char *argv[]) {
    
    int socket_001 = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    if (socket_001 < 0)
        {
            ErrorHandler("socket creation failed.\n");
             return 0;
        }
        
    /* Predisposizione dei dati per il livello 4 TCP e livello 3 IP (iso/osi)
    struct sockaddr_in sad;
    sad.sin_family = AF_INET;
    sad.sin_addr.s_addr = inet_addr( "127.0.0.1");
    sad.sin_port = htons((unsigned short) __specificare numero porta TCP __);
        
   if (connect(socket_001, (struct sockaddr *)&sad, sizeof(sad)) < 0) 
   {
        ErrorHandler( "Failed to connect.\n");
        close(socket_001);
        return 0;
    }
    
    char* messaggio = "prova";
    char* messaggioRicevuto = "";
    int lunghezzaMessaggio = strlen(messaggio);

    int numeroByteTrasmessi = send(socket_001, messaggio, lunghezzaMessaggio, 0);
    
    if (numeroByteTrasmessi != lunghezzaMessaggio)
        ErrorHandler("Errore di trasmissione.\n");
        
    int numeroByteRicevuti = 0;
    int numeroTotaleByteRicevuti = 0;
    char buffer[RCVBUFSIZE];
    
    int numeroByteAttesi = numeroByteTrasmessi;
    
    while (numeroTotaleByteRicevuti < numeroByteAttesi)
    {
        numeroByteRicevuti = recv(socket_001,buffer,RCVBUFSIZE-1,0);
        if (numeroByteRicevuti <= 0)
            ErrorHandler("Errore di ricezione.\n");
        else
            {
                numeroTotaleByteRicevuti = numeroTotaleByteRicevuti + numeroByteRicevuti;
                strcat(buffer,messaggioRicevuto);
            }
        
    }
        
    close(socket_001);
}

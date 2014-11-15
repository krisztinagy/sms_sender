#ifndef SERIAL_H
#define SERIAL_H

/********************************************/
/****** Serial Port Communicator Class ******/
/******    Written By: Akos Pasztor    ******/
/******                                ******/
/******    Last Modified: 04/22/2013   ******/
/********************************************/

#include <QString>
#include <QProgressDialog>
#include <windows.h>

class Serial
{
public:
    Serial();
    Serial(QString com, long int baud);
    ~Serial();

    /* rtm: Read Total Timeout Multiplier  */
    /* rtc: Read Total Timeout Constant    */
    /* wtm: Write Total Timeout Multiplier */
    /* wtc: Write Total Timeout Constant   */

    //setup
    bool setup(int rtm, int rtc = 0, int wtm = 0, int wtc = 0);
    void close();

    //get
    QString getCom() const;
    long int getBaud() const;
    QString getBaudStr() const;

    //set
    void setCom(QString com);
    void setBaud(long int baud);
    void update(QString, long int baud);

    //read & write
    QString read(QProgressDialog *progress = NULL);
    void write(QString str, bool cr = true);
    void write(char c, bool cr = false);
    /* cr: to put CarriageReturn 0x0D at the end of input ? */

    void writeCR(); // write CarriageReturn 0x0D

private:
    bool active;
    HANDLE Cport;

    QString com;
    long int baud;

};

/*** Description from MSDN ***

ReadIntervalTimeout
    The maximum time allowed to elapse before the arrival of the next byte on the communications line, in milliseconds. If the interval between the arrival of
    any two bytes exceeds this amount, the ReadFile operation is completed and any buffered data is returned. A value of zero indicates that interval time-outs
    are not used.
    A value of MAXDWORD, combined with zero values for both the ReadTotalTimeoutConstant and ReadTotalTimeoutMultiplier members, specifies that the read operation
    is to return immediately with the bytes that have already been received, even if no bytes have been received.

ReadTotalTimeoutMultiplier
    The multiplier used to calculate the total time-out period for read operations, in milliseconds. For each read operation, this value is multiplied by the requested number of bytes to be read.

ReadTotalTimeoutConstant
    A constant used to calculate the total time-out period for read operations, in milliseconds. For each read operation, this value is added to the product of the ReadTotalTimeoutMultiplier member and the requested number of bytes.
    A value of zero for both the ReadTotalTimeoutMultiplier and ReadTotalTimeoutConstant members indicates that total time-outs are not used for read operations.

WriteTotalTimeoutMultiplier
    The multiplier used to calculate the total time-out period for write operations, in milliseconds. For each write operation, this value is multiplied by the number of bytes to be written.

WriteTotalTimeoutConstant
    A constant used to calculate the total time-out period for write operations, in milliseconds. For each write operation, this value is added to the product of the WriteTotalTimeoutMultiplier member and the number of bytes to be written.
    A value of zero for both the WriteTotalTimeoutMultiplier and WriteTotalTimeoutConstant members indicates that total time-outs are not used for write operations.

***/

#endif // SERIAL_H

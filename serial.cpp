#include "serial.h"
#include <QDebug>

Serial::Serial()
{
    com = "COM1";
    baud = 1200;
    active = false;
}

Serial::Serial(QString com, long int baud)
{
    this->com = com;
    this->baud = baud;
    active = false;
}

Serial::~Serial()
{
    if(active) { CloseHandle(Cport); }
    active = false;
}

//SETUP
bool Serial::setup(int rtm, int rtc, int wtm, int wtc)
{
    if(this->active) { this->close(); }
    bool ok = true;

    //com
    char *comports = QString( QString("\\\\.\\") + this->com ).toLocal8Bit().data();
    this->Cport = CreateFileA(comports,
                        GENERIC_READ|GENERIC_WRITE,
                        0,
                        NULL,
                        OPEN_EXISTING,
                        0,
                        NULL);

    if(this->Cport==INVALID_HANDLE_VALUE)
    {
        qDebug() << "unable to open comport";
        ok = false;
    }

    //baudrate
    QString b("baud=" + QString::number(this->baud) + " data=8 parity=N stop=1");
    char *pre_baudr = (char*)malloc( (b.size()+1) * sizeof(char) );
    for(int q=0; q<b.size(); ++q)
    {
        pre_baudr[q] = b.at(q).toLatin1();
    }
    pre_baudr[b.size()] = '\0';
    char baudr[128];
    strcpy(baudr,pre_baudr);
    free(pre_baudr);

    DCB port_settings;
    memset(&port_settings, 0, sizeof(port_settings));
    port_settings.DCBlength = sizeof(port_settings);

    if(!BuildCommDCBA(baudr, &port_settings))
    {
        qDebug() << "unable to set comport dcb settings";
        CloseHandle(this->Cport);
        ok = false;
    }

    if(!SetCommState(this->Cport, &port_settings))
    {
        qDebug() << "unable to set comport cfg settings";
        CloseHandle(this->Cport);
        ok = false;
    }

    COMMTIMEOUTS Cptimeouts;

    Cptimeouts.ReadIntervalTimeout         = MAXDWORD;
    Cptimeouts.ReadTotalTimeoutMultiplier  = rtm;
    Cptimeouts.ReadTotalTimeoutConstant    = rtc;
    Cptimeouts.WriteTotalTimeoutMultiplier = wtm;
    Cptimeouts.WriteTotalTimeoutConstant   = wtc;

    if(!SetCommTimeouts(this->Cport, &Cptimeouts))
    {
        qDebug() << "unable to set comport time-out settings";
        CloseHandle(this->Cport);
        ok = false;
    }

    this->active = ok;
    return ok;
}

// GET parameters
QString Serial::getCom() const
{
    return this->com;
}

long int Serial::getBaud() const
{
    return this->baud;
}

QString Serial::getBaudStr() const
{
    return QString::number(this->baud);
}

// SET parameters
void Serial::setCom(QString com)
{
    this->com = com;
}

void Serial::setBaud(long int baud)
{
    this->baud = baud;
}

void Serial::update(QString com, long int baud)
{
    this->com = com;
    this->baud = baud;
}

// CLOSE port
void Serial::close()
{
    if(active) { CloseHandle(Cport); }
    active = false;
}

// READ
QString Serial::read(QProgressDialog *progress)
{
    QString str("");
    char buf;
    int n = 1;

    while(n)
    {
        ReadFile(Cport, &buf, 1, (LPDWORD)((void *)&n), NULL);
        if(!n) { break; } //utolso karakter beolvasasa utan ne rakja be meg1x az utolso karaktert str-be

        str += QString(buf);
        if(progress && (int)buf != 13) { progress->setValue( progress->value() + 1 ); }
        if(progress && progress->wasCanceled()) { return str; }
    }

    return str;
}

// WRITE
void Serial::write(QString str, bool cr)
{
    char c;
    int n;

    for(int i=0; i<str.size(); ++i)
    {
        c = str.at(i).toAscii();
        WriteFile(Cport, &c , 1, (LPDWORD)((void *)&n), NULL);
    }

    //enter
    if(cr)
    {
        c = (char)13;
        WriteFile(Cport, &c , 1, (LPDWORD)((void *)&n), NULL);
    }
}

void Serial::write(char c, bool cr)
{
    int n;
    WriteFile(Cport, &c , 1, (LPDWORD)((void *)&n), NULL);

    if(cr)
    {
        char enter = (char)13;
        WriteFile(Cport, &enter , 1, (LPDWORD)((void *)&n), NULL);
    }
}

void Serial::writeCR()
{
    int n;
    char c = (char)13;
    WriteFile(Cport, &c , 1, (LPDWORD)((void *)&n), NULL);
}

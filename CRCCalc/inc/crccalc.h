#ifndef CRCCALC_H
#define CRCCALC_H

#include <QMainWindow>
#include <QMessageBox>
#include <QComboBox>
#include <QMetaEnum>
#include <QFileDialog>
#include <QFile>
#include "ui_crccalc.h"
#include <QDebug>
#include "crc.h"

namespace Ui {
class CrcCalc;
}

class CrcCalc : public QMainWindow
{
    Q_OBJECT
public:
    enum CRCList{
        CRC4_itu = 0,
        CRC5_epc,
        CRC5_itu,
        CRC5_usb,
        CRC6_itu,
        CRC7_mmc,

        CRC8,
        CRC8_cdma2000,
        CRC8_darc,
        CRC8_dvb_s2,
        CRC8_ebu,
        CRC8_i_code,
        CRC8_itu,
        CRC8_maxim,   //DS18B20
        CRC8_rohc,
        CRC8_wcdma,

        CRC16_a,
        CRC16_aug_ccitt,
        CRC16_buypass,
        CRC16_ccitt,   // kermit
        CRC16_ccitt_false,
        CRC16_cdma2000,
        CRC16_dds_110,
        CRC16_dect_r,
        CRC16_dect_x,
        CRC16_dnp,
        CRC16_en_13757,
        CRC16_genibus,
        CRC16_ibm,
        CRC16_maxim,
        CRC16_mcrf4xx,
        CRC16_modbus,
        CRC16_riello,
        CRC16_t10_dif,
        CRC16_teledisk,
        CRC16_tms37157,
        CRC16_usb,
        CRC16_x25,
        CRC16_xmodem,

        CRC32,
        CRC32_bzip2,
        CRC32_c,
        CRC32_d,
        CRC32_jamcrc,
        CRC32_mpeg_2,
        CRC32_posix,
        CRC32_q,
        CRC32_xfer,

        Unknown = -1,
    };
    Q_ENUM(CRCList)

    explicit CrcCalc(QWidget *parent = 0);
    ~CrcCalc();
    bool isHexString(QString src);
    QByteArray stringToHex(QString src );
    void  listCRC();

    QByteArray toQByteArray(uint8_t  tmp);
    QByteArray toQByteArray(uint16_t tmp);
    QByteArray toQByteArray(uint32_t tmp);
    QFile *file;
    void calcCRC(QByteArray &tmpBuf, CRCList calcSelect = CRC32 );
    void verifyInput();

private slots:

    void on_btnCalc_clicked();

    void on_btnLoadFile_clicked();

    void on_lstCRCSelect_currentRowChanged(int currentRow);

    void on_ckbHexSelect_clicked(bool checked);

private:
    Ui::CrcCalc *ui;
};

#endif // CRCCALC_H

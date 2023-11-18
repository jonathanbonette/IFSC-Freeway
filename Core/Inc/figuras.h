#ifndef FIGURAS_H_
#define FIGURAS_H_

//504 bytes por figura - 48x84 pixels

const unsigned char tela_inicial [] = {
		0xFF     ,/*  ########  */
		0x01     ,/*  _______#  */
		0x01     ,/*  _______#  */
		0xFD     ,/*  ######_#  */
		0xFD     ,/*  ######_#  */
		0x65     ,/*  _##__#_#  */
		0x65     ,/*  _##__#_#  */
		0x65     ,/*  _##__#_#  */
		0x65     ,/*  _##__#_#  */
		0x65     ,/*  _##__#_#  */
		0x65     ,/*  _##__#_#  */
		0x65     ,/*  _##__#_#  */
		0x65     ,/*  _##__#_#  */
		0x65     ,/*  _##__#_#  */
		0xFD     ,/*  ######_#  */
		0xFD     ,/*  ######_#  */
		0x71     ,/*  _###___#  */
		0x71     ,/*  _###___#  */
		0xF1     ,/*  ####___#  */
		0xF1     ,/*  ####___#  */
		0x71     ,/*  _###___#  */
		0x71     ,/*  _###___#  */
		0xF1     ,/*  ####___#  */
		0xF1     ,/*  ####___#  */
		0x71     ,/*  _###___#  */
		0x71     ,/*  _###___#  */
		0xF1     ,/*  ####___#  */
		0xFD     ,/*  ######_#  */
		0xFD     ,/*  ######_#  */
		0x05     ,/*  _____#_#  */
		0x05     ,/*  _____#_#  */
		0xFD     ,/*  ######_#  */
		0x65     ,/*  _##__#_#  */
		0x65     ,/*  _##__#_#  */
		0xFD     ,/*  ######_#  */
		0xED     ,/*  ###_##_#  */
		0xED     ,/*  ###_##_#  */
		0xED     ,/*  ###_##_#  */
		0xED     ,/*  ###_##_#  */
		0xED     ,/*  ###_##_#  */
		0xFD     ,/*  ######_#  */
		0x65     ,/*  _##__#_#  */
		0x65     ,/*  _##__#_#  */
		0xFD     ,/*  ######_#  */
		0x65     ,/*  _##__#_#  */
		0x65     ,/*  _##__#_#  */
		0xFD     ,/*  ######_#  */
		0xFD     ,/*  ######_#  */
		0xCD     ,/*  ##__##_#  */
		0xCD     ,/*  ##__##_#  */
		0x3D     ,/*  __####_#  */
		0x3D     ,/*  __####_#  */
		0xCD     ,/*  ##__##_#  */
		0xCD     ,/*  ##__##_#  */
		0x3D     ,/*  __####_#  */
		0x3D     ,/*  __####_#  */
		0xFD     ,/*  ######_#  */
		0xFD     ,/*  ######_#  */
		0xF9     ,/*  #####__#  */
		0xF9     ,/*  #####__#  */
		0x99     ,/*  #__##__#  */
		0x99     ,/*  #__##__#  */
		0x99     ,/*  #__##__#  */
		0x99     ,/*  #__##__#  */
		0xF9     ,/*  #####__#  */
		0xF9     ,/*  #####__#  */
		0xC1     ,/*  ##_____#  */
		0xC1     ,/*  ##_____#  */
		0xC1     ,/*  ##_____#  */
		0xC1     ,/*  ##_____#  */
		0xC1     ,/*  ##_____#  */
		0xC1     ,/*  ##_____#  */
		0xC1     ,/*  ##_____#  */
		0xF1     ,/*  ####___#  */
		0xF1     ,/*  ####___#  */
		0xF1     ,/*  ####___#  */
		0x31     ,/*  __##___#  */
		0x31     ,/*  __##___#  */
		0xF1     ,/*  ####___#  */
		0xF1     ,/*  ####___#  */
		0xF1     ,/*  ####___#  */
		0x01     ,/*  _______#  */
		0x01     ,/*  _______#  */
		0xFF     ,/*  ########  */
		0xFF     ,/*  ########  */
		0x00     ,/*  ________  */
		0x00     ,/*  ________  */
		0xFF     ,/*  ########  */
		0xFF     ,/*  ########  */
		0x66     ,/*  _##__##_  */
		0x66     ,/*  _##__##_  */
		0x66     ,/*  _##__##_  */
		0x66     ,/*  _##__##_  */
		0x66     ,/*  _##__##_  */
		0x66     ,/*  _##__##_  */
		0x66     ,/*  _##__##_  */
		0x66     ,/*  _##__##_  */
		0x66     ,/*  _##__##_  */
		0xFF     ,/*  ########  */
		0xFF     ,/*  ########  */
		0x66     ,/*  _##__##_  */
		0x66     ,/*  _##__##_  */
		0xFF     ,/*  ########  */
		0xFF     ,/*  ########  */
		0x66     ,/*  _##__##_  */
		0x66     ,/*  _##__##_  */
		0xFF     ,/*  ########  */
		0xFF     ,/*  ########  */
		0x66     ,/*  _##__##_  */
		0x66     ,/*  _##__##_  */
		0xFF     ,/*  ########  */
		0xFF     ,/*  ########  */
		0x7F     ,/*  _#######  */
		0x60     ,/*  _##_____  */
		0x60     ,/*  _##_____  */
		0x7F     ,/*  _#######  */
		0x06     ,/*  _____##_  */
		0x26     ,/*  __#__##_  */
		0x57     ,/*  _#_#_###  */
		0x26     ,/*  __#__##_  */
		0x06     ,/*  _____##_  */
		0x76     ,/*  _###_##_  */
		0x56     ,/*  _#_#_##_  */
		0x76     ,/*  _###_##_  */
		0x07     ,/*  _____###  */
		0x76     ,/*  _###_##_  */
		0x56     ,/*  _#_#_##_  */
		0x77     ,/*  _###_###  */
		0x06     ,/*  _____##_  */
		0x7E     ,/*  _######_  */
		0x7F     ,/*  _#######  */
		0x7F     ,/*  _#######  */
		0x7C     ,/*  _#####__  */
		0x7C     ,/*  _#####__  */
		0x73     ,/*  _###__##  */
		0x73     ,/*  _###__##  */
		0x7C     ,/*  _#####__  */
		0x7C     ,/*  _#####__  */
		0x73     ,/*  _###__##  */
		0x73     ,/*  _###__##  */
		0x7F     ,/*  _#######  */
		0x7F     ,/*  _#######  */
		0xFF     ,/*  ########  */
		0xFF     ,/*  ########  */
		0x99     ,/*  #__##__#  */
		0x99     ,/*  #__##__#  */
		0x99     ,/*  #__##__#  */
		0x99     ,/*  #__##__#  */
		0xFF     ,/*  ########  */
		0xFF     ,/*  ########  */
		0xFF     ,/*  ########  */
		0x99     ,/*  #__##__#  */
		0x99     ,/*  #__##__#  */
		0xFF     ,/*  ########  */
		0x99     ,/*  #__##__#  */
		0x99     ,/*  #__##__#  */
		0xFF     ,/*  ########  */
		0xFF     ,/*  ########  */
		0x03     ,/*  ______##  */
		0x03     ,/*  ______##  */
		0xC0     ,/*  ##______  */
		0xC0     ,/*  ##______  */
		0xFF     ,/*  ########  */
		0xFF     ,/*  ########  */
		0xFF     ,/*  ########  */
		0x00     ,/*  ________  */
		0x00     ,/*  ________  */
		0xFF     ,/*  ########  */
		0xFF     ,/*  ########  */
		0x00     ,/*  ________  */
		0x00     ,/*  ________  */
		0xFF     ,/*  ########  */
		0xFF     ,/*  ########  */
		0x66     ,/*  _##__##_  */
		0x66     ,/*  _##__##_  */
		0x66     ,/*  _##__##_  */
		0x66     ,/*  _##__##_  */
		0x66     ,/*  _##__##_  */
		0x66     ,/*  _##__##_  */
		0x66     ,/*  _##__##_  */
		0x66     ,/*  _##__##_  */
		0x66     ,/*  _##__##_  */
		0xFF     ,/*  ########  */
		0xFF     ,/*  ########  */
		0x66     ,/*  _##__##_  */
		0x66     ,/*  _##__##_  */
		0xFF     ,/*  ########  */
		0xFF     ,/*  ########  */
		0x66     ,/*  _##__##_  */
		0x66     ,/*  _##__##_  */
		0xFF     ,/*  ########  */
		0xFF     ,/*  ########  */
		0x66     ,/*  _##__##_  */
		0x66     ,/*  _##__##_  */
		0xFF     ,/*  ########  */
		0xFF     ,/*  ########  */
		0x00     ,/*  ________  */
		0xFF     ,/*  ########  */
		0x01     ,/*  _______#  */
		0xFF     ,/*  ########  */
		0x00     ,/*  ________  */
		0x77     ,/*  _###_###  */
		0x55     ,/*  _#_#_#_#  */
		0x77     ,/*  _###_###  */
		0x00     ,/*  ________  */
		0x77     ,/*  _###_###  */
		0x55     ,/*  _#_#_#_#  */
		0x77     ,/*  _###_###  */
		0x00     ,/*  ________  */
		0x70     ,/*  _###____  */
		0x50     ,/*  _#_#____  */
		0x70     ,/*  _###____  */
		0x00     ,/*  ________  */
		0xFF     ,/*  ########  */
		0x61     ,/*  _##____#  */
		0xC5     ,/*  ##___#_#  */
		0x8D     ,/*  #___##_#  */
		0x19     ,/*  ___##__#  */
		0xFF     ,/*  ########  */
		0x00     ,/*  ________  */
		0xFF     ,/*  ########  */
		0x01     ,/*  _______#  */
		0xFD     ,/*  ######_#  */
		0x05     ,/*  _____#_#  */
		0x07     ,/*  _____###  */
		0x00     ,/*  ________  */
		0xFF     ,/*  ########  */
		0xFF     ,/*  ########  */
		0x99     ,/*  #__##__#  */
		0x99     ,/*  #__##__#  */
		0x99     ,/*  #__##__#  */
		0x99     ,/*  #__##__#  */
		0xFF     ,/*  ########  */
		0xFF     ,/*  ########  */
		0xFF     ,/*  ########  */
		0x99     ,/*  #__##__#  */
		0x99     ,/*  #__##__#  */
		0xFF     ,/*  ########  */
		0x99     ,/*  #__##__#  */
		0x99     ,/*  #__##__#  */
		0xFF     ,/*  ########  */
		0xFF     ,/*  ########  */
		0x06     ,/*  _____##_  */
		0x06     ,/*  _____##_  */
		0x1F     ,/*  ___#####  */
		0x1F     ,/*  ___#####  */
		0xFF     ,/*  ########  */
		0xFF     ,/*  ########  */
		0xFF     ,/*  ########  */
		0x00     ,/*  ________  */
		0x00     ,/*  ________  */
		0xFF     ,/*  ########  */
		0xFF     ,/*  ########  */
		0x00     ,/*  ________  */
		0x00     ,/*  ________  */
		0x7F     ,/*  _#######  */
		0x7F     ,/*  _#######  */
		0x7E     ,/*  _######_  */
		0x7E     ,/*  _######_  */
		0x7E     ,/*  _######_  */
		0x7E     ,/*  _######_  */
		0x7E     ,/*  _######_  */
		0x7E     ,/*  _######_  */
		0x7E     ,/*  _######_  */
		0x1E     ,/*  ___####_  */
		0x5E     ,/*  _#_####_  */
		0x5F     ,/*  _#_#####  */
		0x5F     ,/*  _#_#####  */
		0x5E     ,/*  _#_####_  */
		0x5E     ,/*  _#_####_  */
		0x5F     ,/*  _#_#####  */
		0x5F     ,/*  _#_#####  */
		0x5E     ,/*  _#_####_  */
		0x5E     ,/*  _#_####_  */
		0x47     ,/*  _#___###  */
		0x17     ,/*  ___#_###  */
		0xD6     ,/*  ##_#_##_  */
		0x56     ,/*  _#_#_##_  */
		0x57     ,/*  _#_#_###  */
		0x57     ,/*  _#_#_###  */
		0x10     ,/*  ___#____  */
		0xD7     ,/*  ##_#_###  */
		0x54     ,/*  _#_#_#__  */
		0x57     ,/*  _#_#_###  */
		0x90     ,/*  #__#____  */
		0x17     ,/*  ___#_###  */
		0xD5     ,/*  ##_#_#_#  */
		0x57     ,/*  _#_#_###  */
		0x50     ,/*  _#_#____  */
		0x57     ,/*  _#_#_###  */
		0x15     ,/*  ___#_#_#  */
		0xD7     ,/*  ##_#_###  */
		0x50     ,/*  _#_#____  */
		0x50     ,/*  _#_#____  */
		0x50     ,/*  _#_#____  */
		0x10     ,/*  ___#____  */
		0xD0     ,/*  ##_#____  */
		0x17     ,/*  ___#_###  */
		0x14     ,/*  ___#_#__  */
		0x14     ,/*  ___#_#__  */
		0xD5     ,/*  ##_#_#_#  */
		0x14     ,/*  ___#_#__  */
		0x97     ,/*  #__#_###  */
		0x50     ,/*  _#_#____  */
		0x57     ,/*  _#_#_###  */
		0x94     ,/*  #__#_#__  */
		0x15     ,/*  ___#_#_#  */
		0xD5     ,/*  ##_#_#_#  */
		0x17     ,/*  ___#_###  */
		0x10     ,/*  ___#____  */
		0x17     ,/*  ___#_###  */
		0xD7     ,/*  ##_#_###  */
		0x17     ,/*  ___#_###  */
		0x47     ,/*  _#___###  */
		0x5F     ,/*  _#_#####  */
		0x5F     ,/*  _#_#####  */
		0x5F     ,/*  _#_#####  */
		0x5F     ,/*  _#_#####  */
		0x5F     ,/*  _#_#####  */
		0x59     ,/*  _#_##__#  */
		0x59     ,/*  _#_##__#  */
		0x5F     ,/*  _#_#####  */
		0x59     ,/*  _#_##__#  */
		0x19     ,/*  ___##__#  */
		0x7F     ,/*  _#######  */
		0x7F     ,/*  _#######  */
		0x7C     ,/*  _#####__  */
		0x7C     ,/*  _#####__  */
		0x60     ,/*  _##_____  */
		0x60     ,/*  _##_____  */
		0x7F     ,/*  _#######  */
		0x7F     ,/*  _#######  */
		0x7F     ,/*  _#######  */
		0x00     ,/*  ________  */
		0x00     ,/*  ________  */
		0xFF     ,/*  ########  */
		0xFF     ,/*  ########  */
		0x00     ,/*  ________  */
		0x00     ,/*  ________  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x90     ,/*  #__#____  */
		0x97     ,/*  #__#_###  */
		0x91     ,/*  #__#___#  */
		0x91     ,/*  #__#___#  */
		0x90     ,/*  #__#____  */
		0x90     ,/*  #__#____  */
		0x97     ,/*  #__#_###  */
		0x91     ,/*  #__#___#  */
		0x93     ,/*  #__#__##  */
		0x94     ,/*  #__#_#__  */
		0x90     ,/*  #__#____  */
		0x97     ,/*  #__#_###  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x94     ,/*  #__#_#__  */
		0x90     ,/*  #__#____  */
		0x97     ,/*  #__#_###  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x94     ,/*  #__#_#__  */
		0x90     ,/*  #__#____  */
		0x97     ,/*  #__#_###  */
		0x92     ,/*  #__#__#_  */
		0x91     ,/*  #__#___#  */
		0x92     ,/*  #__#__#_  */
		0x97     ,/*  #__#_###  */
		0x90     ,/*  #__#____  */
		0x97     ,/*  #__#_###  */
		0x91     ,/*  #__#___#  */
		0x91     ,/*  #__#___#  */
		0x97     ,/*  #__#_###  */
		0x90     ,/*  #__#____  */
		0x90     ,/*  #__#____  */
		0x91     ,/*  #__#___#  */
		0x97     ,/*  #__#_###  */
		0x91     ,/*  #__#___#  */
		0x90     ,/*  #__#____  */
		0x90     ,/*  #__#____  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x95     ,/*  #__#_#_#  */
		0x00     ,/*  ________  */
		0x00     ,/*  ________  */
		0xFF     ,/*  ########  */
		0xFF     ,/*  ########  */
		0x80     ,/*  #_______  */
		0x00     ,/*  ________  */
		0x3F     ,/*  __######  */
		0x3F     ,/*  __######  */
		0x3B     ,/*  __###_##  */
		0x3F     ,/*  __######  */
		0x3F     ,/*  __######  */
		0x3B     ,/*  __###_##  */
		0x3F     ,/*  __######  */
		0x3F     ,/*  __######  */
		0x3B     ,/*  __###_##  */
		0x3F     ,/*  __######  */
		0x3F     ,/*  __######  */
		0x3B     ,/*  __###_##  */
		0x3F     ,/*  __######  */
		0x3F     ,/*  __######  */
		0x3B     ,/*  __###_##  */
		0x3F     ,/*  __######  */
		0x3F     ,/*  __######  */
		0x3B     ,/*  __###_##  */
		0x3F     ,/*  __######  */
		0x3F     ,/*  __######  */
		0xBB     ,/*  #_###_##  */
		0xBF     ,/*  #_######  */
		0xBF     ,/*  #_######  */
		0xBB     ,/*  #_###_##  */
		0xBF     ,/*  #_######  */
		0xBF     ,/*  #_######  */
		0xBB     ,/*  #_###_##  */
		0xBF     ,/*  #_######  */
		0xBF     ,/*  #_######  */
		0xBB     ,/*  #_###_##  */
		0xBF     ,/*  #_######  */
		0xBF     ,/*  #_######  */
		0xBB     ,/*  #_###_##  */
		0xBF     ,/*  #_######  */
		0xBF     ,/*  #_######  */
		0xBB     ,/*  #_###_##  */
		0xBF     ,/*  #_######  */
		0xBF     ,/*  #_######  */
		0xBB     ,/*  #_###_##  */
		0xBF     ,/*  #_######  */
		0xBF     ,/*  #_######  */
		0xBB     ,/*  #_###_##  */
		0xBF     ,/*  #_######  */
		0xBF     ,/*  #_######  */
		0xBB     ,/*  #_###_##  */
		0xBF     ,/*  #_######  */
		0xBF     ,/*  #_######  */
		0xBB     ,/*  #_###_##  */
		0xBF     ,/*  #_######  */
		0xBF     ,/*  #_######  */
		0xBB     ,/*  #_###_##  */
		0xBF     ,/*  #_######  */
		0xBF     ,/*  #_######  */
		0xBB     ,/*  #_###_##  */
		0xBF     ,/*  #_######  */
		0xBF     ,/*  #_######  */
		0xBB     ,/*  #_###_##  */
		0xBF     ,/*  #_######  */
		0xBF     ,/*  #_######  */
		0xBB     ,/*  #_###_##  */
		0xBF     ,/*  #_######  */
		0xBF     ,/*  #_######  */
		0xBB     ,/*  #_###_##  */
		0xBF     ,/*  #_######  */
		0xBF     ,/*  #_######  */
		0xBB     ,/*  #_###_##  */
		0xBF     ,/*  #_######  */
		0xBF     ,/*  #_######  */
		0xBB     ,/*  #_###_##  */
		0xBF     ,/*  #_######  */
		0xBF     ,/*  #_######  */
		0xBB     ,/*  #_###_##  */
		0xBF     ,/*  #_######  */
		0xBF     ,/*  #_######  */
		0xBB     ,/*  #_###_##  */
		0xBF     ,/*  #_######  */
		0xBF     ,/*  #_######  */
		0xBB     ,/*  #_###_##  */
		0x80     ,/*  #_______  */
		0x80     ,/*  #_______  */
		0xFF     /*  ########  */
};


// ---------------------------------------------------------------------------------------
// Os pixeis n�o empregados na definic�o dos bytes DEVEM ser ZERO, ou seja, os pixeis que n�o devem ser impressos
// A figura � desenhada conforme trabalho do LCD, do LSB to MSB (bytes alinhados verticalmente, ver manual do LCD5110)
//---------------------------------------------------------------------------------------------------
// triangulo
const struct figura_t tri1f =
{
		5,
		3,
		{0b00000100, 0b00000110, 0b00000111, 0b00000110, 0b00000100}

};

const struct figura_t apaga_tri1f =
{
		5,
		3,
		{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000}

};
//---------------------------------------------------------------------------------------------------
// bola
const struct figura_t bola1f =
{
		5,
		5,
		{0b00000100, 0b00001110, 0b00011111, 0b00001110, 0b00000100}

};

const struct figura_t apaga_bola1f =
{
		5,
		5,
		{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000}

};
//---------------------------------------------------------------------------------------------------
// carro 1
const struct figura_t carro1f =
{
		5,
		5,
		{0b00001110, 0b00011111, 0b00001110, 0b00011111, 0b00001110}
};

const struct figura_t apaga_carro1f =
{
		5,
		5,
		{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000}
};
//---------------------------------------------------------------------------------------------------
// sedan 1
const struct figura_t sedan1f =
{
		7,
		5,
		{0b00001110, 0b00011111, 0b00001110, 0b00001110, 0b00001110, 0b00011111, 0b00001110}
};

const struct figura_t apaga_sedan1f =
{
		7,
		5,
		{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000}
};
//---------------------------------------------------------------------------------------------------
// caminhao 1
const struct figura_t caminhao1f =
{
		13,
		5,
		{0b00001110, 0b00001110, 0b00011111, 0b00000100, 0b00011111, 0b00011111, 0b00011111, 0b00011111, 0b00011111, 0b00011111, 0b00011111, 0b00011111, 0b00011111}
};

const struct figura_t apaga_caminhao1f =
{
		13,
		5,
		{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000}
};
//---------------------------------------------------------------------------------------------------
// caminhao 2
const struct figura_t caminhao2f =
{
		23,
		5,
		{0b00011111, 0b00011111, 0b00011111, 0b00011111, 0b00011111, 0b00011111, 0b00011111, 0b00011111, 0b00011111, 0b00000100, 0b00011111, 0b00011111, 0b00011111, 0b00011111, 0b00011111, 0b00011111, 0b00011111, 0b00011111, 0b00011111, 0b00000100, 0b00011111, 0b00001110, 0b00001110}
};

const struct figura_t apaga_caminhao2f =
{
		23,
		5,
		{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000}
};
//---------------------------------------------------------------------------------------------------
// corrida 1
const struct figura_t corrida1f =
{
		10,
		5,
		{0b00010001, 0b00010001, 0b00011111, 0b00001110, 0b00011111, 0b00011111, 0b00001110, 0b00001110, 0b00011111, 0b00001110}
};

const struct figura_t apaga_corrida1f =
{
		10,
		5,
		{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000}
};
//---------------------------------------------------------------------------------------------------
// moto 1
const struct figura_t moto1f =
{
		5,
		5,
		{0b00000100, 0b00001110, 0b00000100, 0b00001110, 0b00000100}
};

const struct figura_t apaga_moto1f =
{
		5,
		5,
		{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000}
};

#endif /* FIGURAS_H_ */
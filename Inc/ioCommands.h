
#define TEMP_SENSOR_CALIB_VAL_ADDR 0x1FFFF7B8U

uint32_t getUID(void);

enum IOcommand {
      WHO_AM_I //Отдали UID
    , RESET_ME // сброс
    , CHANGE_I2C_ADDR // сменить I2C-адрес вручную
    , SAVE_I2C_ADDR // Сохранить текущий адрес во флэш, чтобы стартовать при последующих включениях с него
    , PORT_MODE_INPUT // настроили пины на вход
    , PORT_MODE_PULLUP // .. вход с поддтяжкой вверх
    , PORT_MODE_PULLDOWN
    , PORT_MODE_OUTPUT // .. на выход
    , DIGITAL_READ    // считали состояние виртуального порта
    , DIGITAL_WRITE_HIGH // Выставили пины виртуального порта в высокий уровень
    , DIGITAL_WRITE_LOW // .. в низкий уровень
    , ANALOG_WRITE // Запустить ШИМ
    , ANALOG_READ // Считать значениие с АЦП
    , PWM_FREQ // установка частоты ШИМ (общая для всех PWM-пинов)
};

uint16_t concat2U8toU16(uint8_t highVal, uint8_t lowVal){
  uint16_t result = highVal;
  result <<= 8;
  result |= lowVal;
  return result;
}

void setAnswerBuf_16(uint8_t *answerBuf, uint16_t val){
  answerBuf[1] = val & (uint8_t)0xFF;
  val >>= 8;
  answerBuf[0] = val & (uint8_t)0xFF;
}

void setAnswerBuf_32(uint8_t *answerBuf, uint32_t val){
  answerBuf[3] = val & (uint8_t)0xFF;
  val >>= 8;
  answerBuf[2] = val & (uint8_t)0xFF;
  val >>= 8;
  answerBuf[1] = val & (uint8_t)0xFF;
  val >>= 8;
  answerBuf[0] = val & (uint8_t)0xFF;
}

uint32_t getUID(){
  uint32_t result;
  uint32_t* calibVal = (uint32_t*)TEMP_SENSOR_CALIB_VAL_ADDR;
  result = *calibVal;
  return  result;
}
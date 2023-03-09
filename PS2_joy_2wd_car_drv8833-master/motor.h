/**
   ArduinoNa
   Motor 2channel utility function
*/
uint8_t STANDBYPin = 7;


//ขาสัญญาณมอเตอร์ซ้าย
uint8_t MLftAIN1Pin = 10;
uint8_t MLftAIN2Pin = 11; 
bool  MLftRev = false;    //กลับทิศทางล้อซ้าย

//ขาสัญญาณมอเตอร์ขวา
uint8_t MRgtAIN1Pin = 6;
uint8_t MRgtAIN2Pin = 9; 
bool  MRgtRev = false;     //กลับทิศทางล้อขวา

#define MIN_PWM_SPD 0    //ตั้งค่าความเร็ว PWM [0-254] ต่ำสุดที่ล้อเริ่มหมุน
#define MAX_PWM_SPD 254   //ตั้งค่าความเร็ว PWM [0-254] สูงสุดที่จะใช้
#define DEADBAND_PWM 0.1  //ตั้งค่าช่วงไร้การสั่งการ

//ฟังก์ชันทำ deadband สำหรับตัดค่าที่ต่ำกว่า deadband ให้กลายเป็น 0 สำหรับช่วง [-1,1]
float applyDeadband(float value, float d) {
  float out=0;
  if (value>d) 
    out = (value-d)/(1-d);
  else if (value>-d) 
    out = 0;
  else 
    out = (value+d)/(1-d);
  return out;
}

//ฟังก์ชัน map ค่าแบบทศนิยม
double mapf(double val, double in_min, double in_max, double out_min, double out_max) {
    return (val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

 

//ฟังก์ชันเริ่มการตั้งค่ามอเตอร์ ให้รันใน Setup()
void motor_init() {
    pinMode(STANDBYPin, OUTPUT);
    digitalWrite(STANDBYPin, HIGH);
    Serial.println("Motor inited");
}

/**
 * ฟังก์ชันขับมอเตอร์โดยดูจากความเร็วที่ให้มา หาก speed เป็น + ให้ทิศทางไปข้างหน้า - คือถอยหลัง 0 คือหยุด
 * โดยความเร็วมีค่าตั้งแต่ -1 ถึง 1 สำหรับแต่ละล้อ
 * @param leftspd [-1.0, 1.0]
 * @param rightspd [-1.0, 1.0]
 */
void motor_cmd(float leftspd, float rightspd) {
 


    /**
     * ทำความเร็วให้เป็น + ด้วยคำสั่ง function absolute  (fabs) จากนั้นลิมิตค่าให้ไม่เกิน
     */
    float Lout = constrain( fabs(leftspd), 0.0, 1.0);
    float Rout = constrain( fabs(rightspd), 0.0, 1.0);

    /**
     *        PWM OUT(Duty of cycle 0-255)
     * 255.0  |
     *        }      /
     *        }     /
     *        }    /
     * MIN_SPD|___/______________ 1.0 _> Control signal
     *            deadband
     */

    Lout = applyDeadband(Lout, DEADBAND_PWM);
    Rout = applyDeadband(Rout, DEADBAND_PWM);

    
    if(Lout>0) {
      Lout = mapf(Lout, 0, 1.0, MIN_PWM_SPD, MAX_PWM_SPD);
    }
    if(Rout>0) {
      Rout = mapf(Rout, 0, 1.0, MIN_PWM_SPD, MAX_PWM_SPD);
    }


    
  Serial.print(Lout);Serial.print(",");
  Serial.print(Rout );Serial.print("\n"); 


  if( applyDeadband(leftspd, 0.05) ==0 ) {
    analogWrite(MLftAIN1Pin, 255);
    analogWrite(MLftAIN2Pin, 255);
  }else if( applyDeadband(leftspd, 0.05) > 0 ) {
    analogWrite(MLftAIN1Pin, Lout);
    analogWrite(MLftAIN2Pin, 0);
  }else{
    analogWrite(MLftAIN1Pin, 0);
    analogWrite(MLftAIN2Pin, Lout);
    
  }

  if( applyDeadband(rightspd, 0.05) ==0 ) {
    analogWrite(MRgtAIN1Pin, 255);
    analogWrite(MRgtAIN2Pin, 255);
  }else if( applyDeadband(rightspd, 0.05) > 0 ) {
    analogWrite(MRgtAIN1Pin, Rout);
    analogWrite(MRgtAIN2Pin, 0);
    
  }else{
    analogWrite(MRgtAIN1Pin, 0);
    analogWrite(MRgtAIN2Pin, Rout);
    
  }
//
//
//    analogWrite(MLftAIN1Pin, Lout);
//    digitalWrite(MLftAIN2Pin, (Lout ==0? 0: leftspd>0));
//    analogWrite(MRgtAIN1Pin, Rout);
//    digitalWrite(MRgtAIN2Pin, (Rout ==0 ? 0:rightspd>0));
}

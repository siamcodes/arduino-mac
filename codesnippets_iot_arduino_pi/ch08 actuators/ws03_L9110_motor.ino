
 
// wired connections
#define MOTOR_A_IA D6 
#define MOTOR_A_IB D5 
 
// functional connections
#define MOTOR_A_PWM MOTOR_A_IA // Motor B PWM Speed
#define MOTOR_A_DIR MOTOR_A_IB // Motor B Direction
 


#define PWM_SPEED1 450  
#define PWM_SPEED2 750 
#define DIR_DELAY 3000 
 
void setup()
{
  Serial.begin( 9600 );
  pinMode( MOTOR_A_DIR, OUTPUT );
  pinMode( MOTOR_A_PWM, OUTPUT );
  digitalWrite( MOTOR_A_DIR, LOW ); 
  digitalWrite( MOTOR_A_PWM, LOW );
}
 
void loop()
{
   
      Serial.println( "speed 2 forward..." );
      // set the motor speed and direction
      digitalWrite( MOTOR_A_DIR, LOW ); // direction
      analogWrite( MOTOR_A_PWM, PWM_SPEED2 ); // PWM speed2 hi
      delay( DIR_DELAY );

      Serial.println( "speed 1 forward..." );
      digitalWrite( MOTOR_A_DIR, LOW ); // direction
      analogWrite( MOTOR_A_PWM, PWM_SPEED1 ); // PWM speed1 slow
      delay( DIR_DELAY );

      Serial.println( "stop..." );
      digitalWrite( MOTOR_A_DIR, LOW ); // direction
      analogWrite( MOTOR_A_PWM, 0 );   //  stop
      delay( DIR_DELAY );
        
      Serial.println( "speed 2 reverse..." );
      
      digitalWrite( MOTOR_A_DIR, HIGH ); // direction
      analogWrite( MOTOR_A_PWM, 1023 - PWM_SPEED2 ); // PWM speed2 hi
      delay( DIR_DELAY );

      Serial.println( "speed 1 reverse..." );
      // set the motor speed and direction
      digitalWrite( MOTOR_A_DIR, HIGH ); // direction
      analogWrite( MOTOR_A_PWM, 1023 - PWM_SPEED1 ); // PWM speed1 slow
      delay( DIR_DELAY );

      Serial.println( "stop..." );
      digitalWrite( MOTOR_A_DIR, LOW );
      analogWrite( MOTOR_A_PWM, 0 );    
      delay( DIR_DELAY );
  
}

